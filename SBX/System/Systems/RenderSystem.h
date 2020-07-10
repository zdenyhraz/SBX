#pragma once
#include "System/System.h"

class RenderSystem : public System
{
public:

	RenderSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
	std::string m_WindowName;
	int m_WindowWidth;
	int m_WindowHeight;
	float m_AspectRatioReversed;
	GLFWwindow *m_Window;
};
