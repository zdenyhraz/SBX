#pragma once
#include "Scene.h"

class TestScene: public Scene
{
public:
	TestScene();
	~TestScene();

private:
	void OnGLInit() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;

	std::unique_ptr<Shader> m_Shader;
	std::unique_ptr<Renderer> m_Renderer;
	glm::mat4 m_Proj;
	glm::mat4 m_View;
	glm::vec4 m_ClearColor;
	glm::vec3 m_TranslationA;
	glm::vec3 m_TranslationB;
	std::unique_ptr<VertexArray> m_Va;
	std::unique_ptr<IndexBuffer> m_Ib;
};
