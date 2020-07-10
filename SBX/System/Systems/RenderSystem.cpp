#include "RenderSystem.h"
#include "Render/VertexArray.h"
#include "Render/VertexBuffer.h"
#include "Render/VertexBufferLayout.h"
#include "Render/IndexBuffer.h"
#include "Render/Shader.h"
#include "Render/Renderer.h"
#include "Render/Texture.h"

RenderSystem::RenderSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Render", true ),
	m_WindowName( "SBX OpenGL" ),
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
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	LOG_INFO( "SBX using OpenGL version {}", glGetString( GL_VERSION ) );

	float positions[] =
	{
		-0.5f, -0.7f, 0.0f, 0.0f,
		+0.5f, -0.3f, 1.0f, 0.0f,
		+0.5f, +0.7f, 1.0f, 1.0f,
		-0.5f, +0.3f, 0.0f, 1.0f
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	VertexArray va;
	VertexBuffer vb( positions, 4 * 4 * sizeof( float ) );
	VertexBufferLayout vbl;
	vbl.Push<float>( 2 );//vertex position
	vbl.Push<float>( 2 );//texture coordinate
	va.AddBuffer( vb, vbl );
	IndexBuffer ib( indices, 6 );
	Shader sh( "Resources/Shaders/Vertex.shader", "Resources/Shaders/Fragment.shader" );
	Renderer renderer;
	Texture texture( "Resources/Textures/sasa.png" );
	texture.Bind();
	sh.SetUniform1i( "u_Texture", 0 );

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