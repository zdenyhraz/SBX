#pragma once
#include "Stdafx.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Texture.h"

class Model
{
public:
	Model( const std::string &objPath, const std::string &texPath );

	void Bind() const;

	std::unique_ptr<VertexArray> va;
	std::unique_ptr<VertexBuffer> vb;
	std::unique_ptr<VertexBufferLayout> vbl;
	std::unique_ptr<IndexBuffer> ib;
	std::unique_ptr<Texture> tex;
};