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

	float positions[6] =
	{
		-0.5f, -0.5f,
		0.3f,  0.5f,
		0.5f, -0.7f
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

	std::string vertexShader = ParseShader( "Resources/Shaders/Vertex.shader" );
	std::string fragmentShader = ParseShader( "Resources/Shaders/Fragment.shader" );

	unsigned int shader = CreateShader( vertexShader, fragmentShader );
	glUseProgram( shader );

	// there can be other shaders (like compute shader, geometry shader, idk...), but most important are:
	// 1) vertex shader is run for each vertex (can for example project vertices)
	// 2) fragment (pixel) shader is run for each pixel that needs to be rasterized (can for example determines color, lighting)


	while ( !glfwWindowShouldClose( m_Window ) )
	{
		glClear( GL_COLOR_BUFFER_BIT );
		//----------------------------

		glDrawArrays( GL_TRIANGLES, 0, 3 );

		//----------------------------
		glfwSwapBuffers( m_Window );
		glfwPollEvents();
	}
	glDeleteProgram( shader );
	glfwTerminate();
}