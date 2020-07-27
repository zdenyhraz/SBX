#include "Shader.h"
#include "Render/Renderer.h"

Shader::Shader( const std::string &filepathVertex, const std::string &filepathFragment ):
	m_VertexFilepath( filepathVertex ),
	m_FragmentFilepath( filepathFragment ),
	m_RendererId( 0 )
{
	m_VertexShader = ParseShader( filepathVertex );
	m_FragmentShader = ParseShader( filepathFragment );
	m_RendererId = CreateShader( m_VertexShader, m_FragmentShader );
}

Shader::~Shader()
{
	glDeleteProgram( m_RendererId );
}

void Shader::Bind() const
{
	glUseProgram( m_RendererId );
}

void Shader::Unbind() const
{
	glUseProgram( 0 );
}

void Shader::SetUniform1i( const std::string &name, int v )
{
	glUniform1i( GetUniformLocation( name ), v );
}

void Shader::SetUniform1f( const std::string &name, float v )
{
	glUniform1f( GetUniformLocation( name ), v );
}

void Shader::SetUniform4f( const std::string &name, float v0, float v1, float v2, float v3 )
{
	glUniform4f( GetUniformLocation( name ), v0, v1, v2, v3 );
}

void Shader::SetUniformMat4f( const std::string &name, const glm::mat4 &matrix )
{
	glUniformMatrix4fv( GetUniformLocation( name ), 1, GL_FALSE, &matrix[0][0] );
}

void Shader::UpdateMvp()
{
	SetUniformMat4f( "u_View", Renderer::m_Camera->m_View );
	SetUniformMat4f( "u_Proj", Renderer::m_Camera->m_Proj );
}

int Shader::GetUniformLocation( const std::string &name )
{
	if ( m_UniformLocationCache.find( name ) != m_UniformLocationCache.end() )
		return m_UniformLocationCache[name];

	int location = glGetUniformLocation( m_RendererId, name.c_str() );
	m_UniformLocationCache[name] = location;
	return location;
}

unsigned int Shader::CreateShader( const std::string &sourceVertex, const std::string &sourceFragment )
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader( GL_VERTEX_SHADER, sourceVertex );
	unsigned int fs = CompileShader( GL_FRAGMENT_SHADER, sourceFragment );

	glAttachShader( program, vs );
	glAttachShader( program, fs );
	glLinkProgram( program );
	glValidateProgram( program );

	glDeleteShader( vs );
	glDeleteShader( fs );

	return program;
}

std::string Shader::ParseShader( const std::string &path )
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

unsigned int Shader::CompileShader( unsigned int type, const std::string &source )
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

