#include "Model.h"

Model::Model( const std::string &objPath, const std::string &texPath )
{
	float positions[] = {0, 0, 0};
	unsigned int indices[] = { 0, 0, 0 };


	vb = std::make_unique<VertexBuffer>( positions, 1 * 3 * sizeof( float ) );
	ib = std::make_unique<IndexBuffer>( indices, 3 );
	va = std::make_unique<VertexArray>();
	vbl = std::make_unique<VertexBufferLayout>();
	vbl->Push<float>( 3 ); //vertex position
	vbl->Push<float>( 2 ); //texture coordinate
	va->SetBuffers( vb.get(), vbl.get(), ib.get() );
	tex = std::make_unique<Texture>( texPath );
}

void Model::Bind() const
{
	tex->Bind();
	va->Bind();
}
