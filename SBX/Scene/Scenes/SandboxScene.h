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
	void OnMouseMoveCallback( GLFWwindow *window, double xpos, double ypos ) override;
	void OnMouseClickCallback( GLFWwindow *window, int button, int action, int mods ) override;

	std::shared_ptr<Shader> m_Shader;
	glm::vec4 m_ClearColor;
	std::shared_ptr<Texture> m_TextureEntity;
	std::shared_ptr<Texture> m_TextureGround;
	std::shared_ptr<Texture> m_TextureBox;
};
