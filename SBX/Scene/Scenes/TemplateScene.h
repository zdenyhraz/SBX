#pragma once
#include "Scene/Scene.h"

class TemplateScene : public Scene
{
public:
	TemplateScene();
	~TemplateScene();

private:
	void OnGLInit() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;
};
