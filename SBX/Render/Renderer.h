#pragma once
#include "Stdafx.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "RendererStorage.h"
#include "Camera.h"

class Renderer
{
public:
	static std::unique_ptr<RendererStorage> m_RendererStorage;
	static std::unique_ptr<Camera> m_Camera;
	static void InitStorage( float aspectRatio );
	static void Clear();
	static void Draw( const VertexArray &va, const Shader &sh );
	static void DrawQuad( const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec2 &size, Shader *shader, Texture *texture );
	static void DrawCube( const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &size, Shader *shader, Texture *texture );
};
