#pragma once
#include "Stdafx.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "RendererStorage.h"
#include "Camera.h"
#include "Model.h"

class Renderer
{
public:
	static std::unique_ptr<RendererStorage> m_RendererStorage;
	static std::unique_ptr<Camera> m_Camera;
	static void Init( float aspectRatio );
	static void Clear();
	static void Update( const UserInput &ui );
	static void Draw( VertexArray *va, Shader *sh );
	static void Draw( Model *model, Shader *sh );
	static void DrawQuad( const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec2 &size, Shader *shader, Texture *texture );
	static void DrawCube( const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &size, Shader *shader, Texture *texture );
};
