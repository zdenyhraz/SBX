#pragma once
#include "Stdafx.h"
#include "Render/VertexArray.h"
#include "Render/VertexBuffer.h"
#include "Render/VertexBufferLayout.h"
#include "Render/IndexBuffer.h"
#include "Render/Shader.h"
#include "Render/Renderer.h"
#include "Render/Texture.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void Run();
	void Kill();

private:
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnImGuiRender() = 0;

	bool m_Enabled;
	std::string m_WindowName;
	int m_WindowWidth;
	int m_WindowHeight;
	float m_AspectRatio;
	GLFWwindow *m_Window;
	std::unique_ptr<Shader> m_Shader;
	std::unique_ptr<Renderer> m_Renderer;
};