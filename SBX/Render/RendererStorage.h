#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Texture.h"

class RendererStorage
{
public:
	RendererStorage();

	VertexArray *GetQuadVA() { return m_QuadVA.get(); }
	VertexArray *GetCubeVA() { return m_CubeVA.get(); }

	Texture *GetQuadTex() { return m_QuadTex.get(); }
	Texture *GetCubeTex() { return m_CubeTex.get(); }

private:
	std::shared_ptr<VertexArray> m_QuadVA;
	std::shared_ptr<VertexArray> m_CubeVA;

	std::shared_ptr<Texture> m_QuadTex;
	std::shared_ptr<Texture> m_CubeTex;

	std::shared_ptr<VertexBuffer> m_QuadVB;
	std::shared_ptr<VertexBuffer> m_CubeVB;

	std::shared_ptr<VertexBufferLayout> m_QuadVBL;
	std::shared_ptr<VertexBufferLayout> m_CubeVBL;

	std::shared_ptr<IndexBuffer> m_QuadIB;
	std::shared_ptr<IndexBuffer> m_CubeIB;

	void CreateQuad();
	void CreateCube();
	void CreateTextures();
};