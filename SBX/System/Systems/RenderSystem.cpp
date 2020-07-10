#include "RenderSystem.h"
#include "Render/VertexArray.h"
#include "Render/VertexBuffer.h"
#include "Render/VertexBufferLayout.h"
#include "Render/IndexBuffer.h"
#include "Render/Shader.h"
#include "Render/Renderer.h"

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
	glfwSwapInterval( 1 );
	glewInit();
	LOG_INFO( "SBX using OpenGL version {}", glGetString( GL_VERSION ) );

	float positions[] =
	{
		-0.6f, -0.5f,
		+0.5f, -0.7f,
		+0.5f, +0.3f,
		-0.3f, +0.8f
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	VertexArray va;
	VertexBuffer vb( positions, 4 * 2 * sizeof( float ) );
	VertexBufferLayout vbl;
	vbl.Push<float>( 2 );
	va.AddBuffer( vb, vbl );
	IndexBuffer ib( indices, 6 );
	Shader sh( "Resources/Shaders/Vertex.shader", "Resources/Shaders/Fragment.shader" );
	Renderer renderer;

	va.Unbind();
	vb.Unbind();
	ib.Unbind();
	sh.Unbind();

	float r = 0.0f;
	float incrementAbs = 0.02f;
	float increment = incrementAbs;

	while ( !glfwWindowShouldClose( m_Window ) )
	{
		renderer.Clear();
		sh.Bind();
		sh.SetUniform4f( "u_Color", r, 1.0f - r, r, 1.0f );
		renderer.Draw( va, ib, sh );

		r += increment;
		if ( r >= 1.0 )
			increment = -incrementAbs;
		if ( r <= 0.0 )
			increment = incrementAbs;

		glfwSwapBuffers( m_Window );
		glfwPollEvents();
	}
	glfwTerminate();
}