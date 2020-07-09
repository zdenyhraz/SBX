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

	float positions[6] =
	{
		-0.5f, -0.5f,
		0.0f,  0.5f,
		0.5f, -0.5f
	};

	unsigned int bufferId;
	glGenBuffers( 1, &bufferId );
	glBindBuffer( GL_ARRAY_BUFFER, bufferId );
	glBufferData( GL_ARRAY_BUFFER, 6 * sizeof( float ), positions, GL_STATIC_DRAW );
	int attribIdx = 0;//index of vertex attribute (just one - position)
	int attribCnt = 2;//floats per vertex attribute (two - 2D position)
	int stride = 2 * sizeof( float );//stride between vertices
	const void *attribPtr = 0;//byte offset to this attribute
	glEnableVertexAttribArray( attribIdx );
	glVertexAttribPointer( attribIdx, attribCnt, GL_FLOAT, GL_FALSE, stride, attribPtr );

	while ( !glfwWindowShouldClose( m_Window ) )
	{
		glClear( GL_COLOR_BUFFER_BIT );
		//----------------------------

		glDrawArrays( GL_TRIANGLES, 0, 3 );

		//----------------------------
		glfwSwapBuffers( m_Window );
		glfwPollEvents();
	}

	glfwTerminate();
}