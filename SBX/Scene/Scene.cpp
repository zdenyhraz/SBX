#include "Scene.h"

Scene::Scene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems ) :
	m_Components( components ),
	m_Managers( managers ),
	m_Systems( systems ),
	m_WindowName( "SBX OpenGL" ),
	m_WindowWidth( 2000 ),
	m_WindowHeight( 1500 )
{
	m_AspectRatio = ( float )m_WindowWidth / m_WindowHeight;
}

inline Scene::~Scene()
{

}

void Scene::Run()
{
	std::thread thread( &CommandLineSystem::Run, m_Systems->CommandLine.get() );
	thread.detach();

	GlfwStart();
	ImGuiStart();
	OnStart();

	while ( !glfwWindowShouldClose( m_Window ) )
	{
		OnUpdate();
		Clear();
		OnRender();
		ImgGuiNewFrame();
		OnImGuiRender();
		ImGuiRender();
		GlfwRender();
	}

	OnStop();
	ImGuiStop();
	GlfwStop();
}

void Scene::Clear()
{
	glClear( GL_COLOR_BUFFER_BIT );
}

void Scene::GlfwStart()
{
	glfwInit();
	m_Window = glfwCreateWindow( m_WindowWidth, m_WindowHeight, m_WindowName.c_str(), NULL, NULL );
	glfwMakeContextCurrent( m_Window );
	glfwSwapInterval( 1 );
	glfwSetInputMode( m_Window, GLFW_STICKY_KEYS, GLFW_TRUE );
	glfwSetWindowUserPointer( m_Window, this );
	glfwSetKeyCallback( m_Window, KeyCallback );
	glfwSetScrollCallback( m_Window, ScrollCallback );
	glewInit();
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	LOG_INFO( "SBX using OpenGL version {}", glGetString( GL_VERSION ) );
}

void Scene::GlfwStop()
{
	glfwDestroyWindow( m_Window );
	glfwTerminate();
}

void Scene::GlfwRender()
{
	glfwSwapBuffers( m_Window );
	glfwPollEvents();
}

void Scene::ImGuiStart()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL( m_Window, true );
	ImGui_ImplOpenGL3_Init( ( char * )glGetString( GL_NUM_SHADING_LANGUAGE_VERSIONS ) );
}

void Scene::ImGuiStop()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void Scene::ImgGuiNewFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Scene::ImGuiRender()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );
}

void Scene::KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods )
{
	if ( action == GLFW_REPEAT )
	{
		return;
	}

	Scene *scene = ( Scene * )glfwGetWindowUserPointer( window );

	switch ( key )
	{
		case GLFW_KEY_W:
			scene->m_Keys.KeyW = action == GLFW_PRESS;
			return;

		case GLFW_KEY_S:
			scene->m_Keys.KeyS = action == GLFW_PRESS;
			return;

		case GLFW_KEY_A:
			scene->m_Keys.KeyA = action == GLFW_PRESS;
			return;

		case GLFW_KEY_D:
			scene->m_Keys.KeyD = action == GLFW_PRESS;
			return;
	}

	scene->OnKeyCallback( window, key, scancode, action, mods );
}

void Scene::ScrollCallback( GLFWwindow *window, double xoffset, double yoffset )
{
	Scene *scene = ( Scene * )glfwGetWindowUserPointer( window );
	scene->OnScrollCallback( window, xoffset, yoffset );
}
