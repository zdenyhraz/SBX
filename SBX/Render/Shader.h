#pragma once
#include "Stdafx.h"

// <SHADERS>
// there can be other shaders (like compute shader, geometry shader, idk...), but most important are:
// - vertex shader is run for each vertex (can for example project vertices)
// - fragment (pixel) shader is run for each pixel that needs to be rasterized (can for example determines color, lighting)
// <UNIFORMS>
// - passes data from CPU to GPU (glUniform4f call before draw call)
// - cannot be cahnged during one draw call - different colors need vertex attribs
// - define in shader - e.g. "uniform vec4 u_Color"
// - name in get uniform location must be exactly the same, ofc
// - call of glUniform4f affects current program (currently bound)
class Shader
{
public:
	Shader( const std::string &filepathVertex, const std::string &filepathFragment );
	~Shader();
	void Bind() const;
	void Unbind() const;
	void SetUniform1f( const std::string &name, float v );
	void SetUniform4f( const std::string &name, float v0, float v1, float v2, float v3 );

private:
	unsigned int m_RendererId;
	std::string m_VertexFilepath;
	std::string m_FragmentFilepath;
	std::string m_VertexShader;
	std::string m_FragmentShader;
	std::unordered_map<std::string, int> m_UniformLocationCache;

	int GetUniformLocation( const std::string &name );
	std::string ParseShader( const std::string &path );
	unsigned int CompileShader( unsigned int type, const std::string &source );
	unsigned int CreateShader( const std::string &sourceVertex, const std::string &sourceFragment );
};