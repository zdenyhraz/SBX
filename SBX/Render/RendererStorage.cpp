#include "RendererStorage.h"

RendererStorage::RendererStorage()
{
	//CreateQuad();
	//CreateCube();
	//CreateTextures();
}

void RendererStorage::CreateQuad()
{
	float positions[] =
	{
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		+1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		+1.0f, +1.0f, 0.0f, 1.0f, 1.0f,
		-1.0f, +1.0f, 0.0f, 0.0f, 1.0f
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	m_QuadIB = std::make_shared<IndexBuffer>( indices, 6 );
	m_QuadVA = std::make_shared<VertexArray>();
	m_QuadVB = std::make_shared<VertexBuffer>( positions, 4 * 5 * sizeof( float ) );
	m_QuadVBL = std::make_shared<VertexBufferLayout>();
	m_QuadVBL->Push<float>( 3 ); //vertex position
	m_QuadVBL->Push<float>( 2 ); //texture coordinate
	m_QuadVA->SetVertexBuffer( m_QuadVB, m_QuadVBL );
	m_QuadVA->SetIndexBuffer( m_QuadIB );
}

void RendererStorage::CreateCube()
{
	float positions[] =
	{
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 2.0f * 1.0f, 0.0f, 0.0f,
		1.0f, -1.0f, 2.0f * 1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 2.0f * 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 2.0f * 1.0f, 0.0f, 1.0f,
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	m_CubeIB = std::make_shared<IndexBuffer>( indices, 6 );
	m_CubeVA = std::make_shared<VertexArray>();
	m_CubeVB = std::make_shared<VertexBuffer>( positions, 4 * 5 * sizeof( float ) );
	m_CubeVBL = std::make_shared<VertexBufferLayout>();
	m_CubeVBL->Push<float>( 3 ); //vertex position
	m_CubeVBL->Push<float>( 2 ); //texture coordinate
	m_CubeVA->SetVertexBuffer( m_CubeVB, m_CubeVBL );
	m_CubeVA->SetIndexBuffer( m_CubeIB );
}

void RendererStorage::CreateTextures()
{

}
