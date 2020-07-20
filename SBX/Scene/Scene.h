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
#include "Camera2D.h"
#include "Camera3D.h"

class Scene
{
public:
	Scene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems );
	virtual ~Scene();

	void Run();

protected:
	virtual void OnStart() {};
	virtual void OnStop() {};
	virtual void OnUpdate() {};
	virtual void OnRender() {};
	virtual void OnImGuiRender() {};
	virtual void OnKeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods ) {};
	virtual void OnScrollCallback( GLFWwindow *window, double xoffset, double yoffset ) {};

	void Clear();
	void GlfwStart();
	void GlfwStop();
	void GlfwRender();

	void ImGuiStart();
	void ImGuiStop();
	void ImgGuiNewFrame();
	void ImGuiRender();

	static void KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods );
	static void ScrollCallback( GLFWwindow *window, double xoffset, double yoffset );

	struct KeysPressed
	{
		bool KeyW = false;
		bool KeyS = false;
		bool KeyA = false;
		bool KeyD = false;
	};

	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
	std::shared_ptr<SystemVector> m_Systems;

	std::string m_WindowName;
	int m_WindowWidth;
	int m_WindowHeight;
	float m_AspectRatio;
	GLFWwindow *m_Window;
	KeysPressed m_Keys;
};