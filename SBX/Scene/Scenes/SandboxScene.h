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
	glm::mat4 m_Proj;
	glm::mat4 m_View;
	glm::vec3 m_ViewPos;

	glm::vec4 m_ClearColor;
	std::unique_ptr<VertexArray> m_Va;
	std::unique_ptr<IndexBuffer> m_Ib;
	std::unique_ptr<Texture> m_Texture;

	float m_CameraMoveSpeed;
	float m_CameraZoomSpeed;
	float m_CameraZoom;

	bool m_KeyPressed_W;
	bool m_KeyPressed_S;
	bool m_KeyPressed_A;
	bool m_KeyPressed_D;
};
