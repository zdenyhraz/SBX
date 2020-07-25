#pragma once
#include "Stdafx.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "RendererStorage.h"

class Renderer
{
public:
	static std::unique_ptr<RendererStorage> m_RendererStorage;
	static void InitStorage();
	static void Clear();
	static void Draw( const VertexArray &va, const Shader &sh );
	static void DrawQuad( const glm::vec3 &pos, const glm::vec3 &rot, float size );
};
