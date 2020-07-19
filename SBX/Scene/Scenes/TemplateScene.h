#pragma once
#include "Scene/Scene.h"

class TemplateScene : public Scene
{
public:
	TemplateScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems );

private:
	void OnGLInit() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;
};
