#pragma once
#include "Scene.h"

class TestScene: public Scene
{
public:
	TestScene();
	~TestScene();

private:
	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;

	glm::vec4 m_ClearColor;
};
