#include "RendererStorage.h"

RendererStorage::RendererStorage()
{
	CreateQuad();
	CreateCube();
}

void RendererStorage::AddModel( const std::string &name, const std::string &objPath, const std::string &texPath )
{
	m_Models.emplace( std::pair( name, std::make_unique<Model>( objPath, texPath ) ) );
}

void RendererStorage::AddTexture( const std::string &name, const std::string &texPath )
{
	m_Textures.emplace( std::pair( name, std::make_unique<Texture>( texPath ) ) );
}

Model *RendererStorage::GetModel( const std::string &name )
{

	return m_Models.find( name )->second.get();
}

Texture *RendererStorage::GetTexture( const std::string &name )
{
	return m_Textures.find( name )->second.get();
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

	m_QuadVB = std::make_unique<VertexBuffer>( positions, 4u * 5 * sizeof( float ) );
	m_QuadIB = std::make_unique<IndexBuffer>( indices, 6 );
	m_QuadVA = std::make_unique<VertexArray>();
	m_QuadVBL = std::make_unique<VertexBufferLayout>();
	m_QuadVBL->Push<float>( 3 ); //vertex position
	m_QuadVBL->Push<float>( 2 ); //texture coordinate
	m_QuadVA->SetBuffers( m_QuadVB.get(), m_QuadVBL.get(), m_QuadIB.get() );
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

	m_CubeVB = std::make_unique<VertexBuffer>( positions, 24 * 5 * sizeof( float ) );
	m_CubeIB = std::make_unique<IndexBuffer>( indices, 36 );
	m_CubeVA = std::make_unique<VertexArray>();
	m_CubeVBL = std::make_unique<VertexBufferLayout>();
	m_CubeVBL->Push<float>( 3 ); //vertex position
	m_CubeVBL->Push<float>( 2 ); //texture coordinate
	m_CubeVA->SetBuffers( m_CubeVB.get(), m_CubeVBL.get(), m_CubeIB.get() );
}

