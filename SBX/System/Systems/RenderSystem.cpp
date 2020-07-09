#include "RenderSystem.h"

RenderSystem::RenderSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Render", true ),
	m_WindowName( "SBX 3D" ),
	m_WindowWidth( 1500 ),
	m_WindowHeight( 1000 )
{

}

void RenderSystem::Tick()
{
	glfwInit();
	m_Window = glfwCreateWindow( m_WindowWidth, m_WindowHeight, m_WindowName.c_str(), NULL, NULL );
	glfwMakeContextCurrent( m_Window );
	glewInit();
	LOG_INFO( "SBX using OpenGL version {}", glGetString( GL_VERSION ) );

	while ( !glfwWindowShouldClose( m_Window ) )
	{
		glClear( GL_COLOR_BUFFER_BIT );
		//----------------------------

		glBegin( GL_TRIANGLES );
		glVertex2f( -0.5f, -0.5f );
		glVertex2f( 0.0f, 0.5f );
		glVertex2f( 0.5f, -0.5f );
		glEnd();

		//----------------------------
		glfwSwapBuffers( m_Window );
		glfwPollEvents();
	}

	glfwTerminate();
}