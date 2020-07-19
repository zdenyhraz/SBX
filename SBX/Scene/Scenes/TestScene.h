#pragma once
#include "Scene/Scene.h"

class TestScene: public Scene
{
public:
	TestScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems );

private:
	void OnGLInit() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;

	std::unique_ptr<Shader> m_Shader;
	glm::mat4 m_Proj;
	glm::mat4 m_View;

	glm::vec4 m_ClearColor;
	glm::vec3 m_TranslationA;
	glm::vec3 m_TranslationB;
	std::unique_ptr<VertexArray> m_Va;
	std::unique_ptr<IndexBuffer> m_Ib;
	std::unique_ptr<Texture> m_Texture;
};
