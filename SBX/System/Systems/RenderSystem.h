#pragma once
#include "System/System.h"

class RenderSystem : public System
{
public:

	RenderSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

	static unsigned int CreateShader( const std::string &vertexShader, const std::string &fragmentShader );

	static unsigned int CompileShader( unsigned int type, const std::string &source );

	static std::string ParseShader( const std::string &path );

private:
	std::string m_WindowName;
	int m_WindowWidth;
	int m_WindowHeight;
	GLFWwindow *m_Window;
};
