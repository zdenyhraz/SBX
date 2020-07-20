#pragma once
#include "Scene/Scene.h"

class TemplateScene : public Scene
{
public:
	TemplateScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems );

private:
	void OnStart() override;
	void OnStop() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;
	void OnKeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods ) override;
	void OnScrollCallback( GLFWwindow *window, double xoffset, double yoffset ) override;
};
