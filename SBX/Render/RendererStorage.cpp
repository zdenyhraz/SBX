#include "RendererStorage.h"

RendererStorage::RendererStorage()
{
	CreateQuad();
	CreateCube();
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
		0, 1, 2, 2, 3, 0
	};

	m_QuadVB = std::make_shared<VertexBuffer>( positions, 4 * 5 * sizeof( float ) );
	m_QuadIB = std::make_shared<IndexBuffer>( indices, 6 );
	m_QuadVA = std::make_shared<VertexArray>();
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
		//bot
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		+1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		+1.0f, +1.0f, 0.0f, 1.0f, 1.0f,
		-1.0f, +1.0f, 0.0f, 0.0f, 1.0f,
		//top
		-1.0f, -1.0f, 2.0f, 0.0f, 0.0f,
		+1.0f, -1.0f, 2.0f, 1.0f, 0.0f,
		+1.0f, +1.0f, 2.0f, 1.0f, 1.0f,
		-1.0f, +1.0f, 2.0f, 0.0f, 1.0f,
		//front
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		+1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		+1.0f, -1.0f, 2.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 2.0f, 0.0f, 1.0f,
		//back
		-1.0f, +1.0f, 0.0f, 0.0f, 0.0f,
		+1.0f, +1.0f, 0.0f, 1.0f, 0.0f,
		+1.0f, +1.0f, 2.0f, 1.0f, 1.0f,
		-1.0f, +1.0f, 2.0f, 0.0f, 1.0f,
		//left
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		-1.0f, +1.0f, 0.0f, 1.0f, 0.0f,
		-1.0f, +1.0f, 2.0f, 1.0f, 1.0f,
		-1.0f, -1.0f, 2.0f, 0.0f, 1.0f,
		//right
		+1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		+1.0f, +1.0f, 0.0f, 1.0f, 0.0f,
		+1.0f, +1.0f, 2.0f, 1.0f, 1.0f,
		+1.0f, -1.0f, 2.0f, 0.0f, 1.0f,
	};

	unsigned int indices[] =
	{
		//bot
		0, 1, 2, 2, 3, 0,
		//top
		4, 5, 6, 6, 7, 4,
		//front
		8, 9, 10, 10, 11, 8,
		//back
		12, 13, 14, 14, 15, 12,
		//left
		16, 17, 18, 18, 19, 16,
		//right
		20, 21, 22, 22, 23, 20
	};

	m_CubeVB = std::make_shared<VertexBuffer>( positions, 24 * 5 * sizeof( float ) );
	m_CubeIB = std::make_shared<IndexBuffer>( indices, 36 );
	m_CubeVA = std::make_shared<VertexArray>();
	m_CubeVBL = std::make_shared<VertexBufferLayout>();
	m_CubeVBL->Push<float>( 3 ); //vertex position
	m_CubeVBL->Push<float>( 2 ); //texture coordinate
	m_CubeVA->SetVertexBuffer( m_CubeVB, m_CubeVBL );
	m_CubeVA->SetIndexBuffer( m_CubeIB );
}

