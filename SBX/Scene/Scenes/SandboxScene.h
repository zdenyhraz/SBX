#pragma once
#include "Scene/Scene.h"

class SandboxScene: public Scene
{
public:
	SandboxScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems );

private:
	void OnStart() override;
	void OnStop() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;
	void OnKeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods ) override;
	void OnScrollCallback( GLFWwindow *window, double xoffset, double yoffset ) override;

	std::unique_ptr<Shader> m_Shader;
	glm::vec4 m_ClearColor;
	std::unique_ptr<VertexArray> m_Va;
	std::unique_ptr<IndexBuffer> m_Ib;
	std::unique_ptr<Texture> m_Texture;
	std::unique_ptr<Camera3D> m_Camera3D;
};
