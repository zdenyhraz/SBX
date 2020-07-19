#pragma once
#include "Stdafx.h"
#include "Render/VertexArray.h"
#include "Render/VertexBuffer.h"
#include "Render/VertexBufferLayout.h"
#include "Render/IndexBuffer.h"
#include "Render/Shader.h"
#include "Render/Renderer.h"
#include "Render/Texture.h"
#include "System/SystemVector.h"

class Scene
{
public:
	Scene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems );
	virtual ~Scene();

	void Run();

protected:
	virtual void OnGLInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnImGuiRender() = 0;

	void GlfwStart();
	void GlfwStop();
	void GlfwRender();

	void ImGuiStart();
	void ImGuiStop();
	void ImgGuiNewFrame();
	void ImGuiRender();

	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
	std::shared_ptr<SystemVector> m_Systems;

	std::string m_WindowName;
	int m_WindowWidth;
	int m_WindowHeight;
	float m_AspectRatio;
	GLFWwindow *m_Window;
};