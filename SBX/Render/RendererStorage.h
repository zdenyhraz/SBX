#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Texture.h"
#include "Model.h"

class RendererStorage
{
public:
	RendererStorage();

	VertexArray *GetQuadVA() { return m_QuadVA.get(); }
	VertexArray *GetCubeVA() { return m_CubeVA.get(); }

private:
	void CreateQuad();
	void CreateCube();

	std::unordered_map<std::string, Model> m_Models;

	std::unique_ptr<VertexArray> m_QuadVA;
	std::unique_ptr<VertexArray> m_CubeVA;

	std::unique_ptr<VertexBuffer> m_QuadVB;
	std::unique_ptr<VertexBuffer> m_CubeVB;

	std::unique_ptr<VertexBufferLayout> m_QuadVBL;
	std::unique_ptr<VertexBufferLayout> m_CubeVBL;

	std::unique_ptr<IndexBuffer> m_QuadIB;
	std::unique_ptr<IndexBuffer> m_CubeIB;
};