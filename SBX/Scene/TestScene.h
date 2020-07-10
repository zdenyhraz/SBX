#pragma once
#include "Scene.h"

class TestScene: public Scene
{
public:
	TestScene();
	~TestScene();

	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;

private:
	glm::vec4 m_ClearColor;
};
