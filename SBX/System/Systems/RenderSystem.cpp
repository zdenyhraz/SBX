#include "RenderSystem.h"

RenderSystem::RenderSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Render", true ),
	m_WindowName( "SBX 3D" ),
	m_WindowWidth( 1500 ),
	m_WindowHeight( 1000 )
{

}

std::string RenderSystem::ParseShader( const std::string &path )
{
	std::ifstream stream( path );
	std::stringstream ss;
	std::string line;
	while ( getline( stream, line ) )
	{
		ss << line << "\n";
	}
	LOG_DEBUG( "Shader {} source code:\n{}", path, ss.str() );
	return ss.str();
}

unsigned int RenderSystem::CompileShader( unsigned int type, const std::string &source )
{
	unsigned int id = glCreateShader( type );
	const char *src = source.c_str();
	glShaderSource( id, 1, &src, nullptr );
	glCompileShader( id );

	int result;
	glGetShaderiv( id, GL_COMPILE_STATUS, &result );
	if ( result == GL_FALSE )
	{
		int length;
		glGetShaderiv( id, GL_INFO_LOG_LENGTH, &length );
		char *message = ( char * )alloca( length * sizeof( char ) );
		glGetShaderInfoLog( id, length, &length, message );
		LOG_ERROR( "Failed to compile shader! (type {}) - {}", type, message );
		glDeleteShader( id );
		return 0;
	}

	return id;
}

unsigned int RenderSystem::CreateShader( const std::string &vertexShader, const std::string &fragmentShader )
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader( GL_VERTEX_SHADER, vertexShader );
	unsigned int fs = CompileShader( GL_FRAGMENT_SHADER, fragmentShader );

	glAttachShader( program, vs );
	glAttachShader( program, fs );
	glLinkProgram( program );
	glValidateProgram( program );

	glDeleteShader( vs );
	glDeleteShader( fs );

	return program;
}

void RenderSystem::Tick()
{
	glfwInit();
	m_Window = glfwCreateWindow( m_WindowWidth, m_WindowHeight, m_WindowName.c_str(), NULL, NULL );
	glfwMakeContextCurrent( m_Window );
	glewInit();
	LOG_INFO( "SBX using OpenGL version {}", glGetString( GL_VERSION ) );

	float positions[] =
	{
		-0.5f, -0.5f,
		+0.5f, -0.5f,
		+0.5f, +0.5f,
		-0.5f, +0.5f
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	unsigned int vertexBufferId;
	glGenBuffers( 1, &vertexBufferId );
	glBindBuffer( GL_ARRAY_BUFFER, vertexBufferId );
	glBufferData( GL_ARRAY_BUFFER, 4 * 2 * sizeof( float ), positions, GL_STATIC_DRAW );

	int attribIdx = 0;//index of vertex attribute (just one - position)
	int attribCnt = 2;//floats per vertex attribute (two - 2D position)
	int stride = 2 * sizeof( float );//stride between vertices
	const void *attribPtr = 0;//byte offset to this attribute
	glEnableVertexAttribArray( attribIdx );
	glVertexAttribPointer( attribIdx, attribCnt, GL_FLOAT, GL_FALSE, stride, attribPtr );

	unsigned int indexBufferId;
	glGenBuffers( 1, &indexBufferId );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBufferId );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof( unsigned int ), indices, GL_STATIC_DRAW );

	std::string vertexShader = ParseShader( "Resources/Shaders/Vertex.shader" );
	std::string fragmentShader = ParseShader( "Resources/Shaders/Fragment.shader" );

	unsigned int shader = CreateShader( vertexShader, fragmentShader );
	glUseProgram( shader );

	// <INDEX BUFFERS>
	// - index buffers help reuse memory - no need to copy adjacent vertices
	// - draw call count is all the indices tho

	// <SHADERS>
	// there can be other shaders (like compute shader, geometry shader, idk...), but most important are:
	// 1) vertex shader is run for each vertex (can for example project vertices)
	// 2) fragment (pixel) shader is run for each pixel that needs to be rasterized (can for example determines color, lighting)


	while ( !glfwWindowShouldClose( m_Window ) )
	{
		glClear( GL_COLOR_BUFFER_BIT );
		//----------------------------

		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );

		//----------------------------
		glfwSwapBuffers( m_Window );
		glfwPollEvents();
	}
	glDeleteProgram( shader );
	glfwTerminate();
}