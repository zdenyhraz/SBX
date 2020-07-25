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
	std::shared_ptr<VertexBuffer> m_VbEntity;
	std::shared_ptr<VertexBuffer> m_VbGround;
	std::shared_ptr<VertexBuffer> m_VbBox;
	std::shared_ptr<VertexBufferLayout> m_VblEntity;
	std::shared_ptr<VertexBufferLayout> m_VblGround;
	std::shared_ptr<VertexBufferLayout> m_VblBox;
	std::shared_ptr<VertexArray> m_VaEntity;
	std::shared_ptr<VertexArray> m_VaGround;
	std::shared_ptr<VertexArray> m_VaBox;
	std::shared_ptr<IndexBuffer> m_Ib;
	std::shared_ptr<IndexBuffer> m_IbBox;
	std::shared_ptr<Texture> m_TextureEntity;
	std::shared_ptr<Texture> m_TextureGround;
	std::shared_ptr<Texture> m_TextureBox;
	std::shared_ptr<Camera3D> m_Camera3D;
};
