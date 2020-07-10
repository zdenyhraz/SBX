#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
	Renderer();

	void Clear() const;
	void Draw( const VertexArray &va, const IndexBuffer &ib, const Shader &sh ) const;

private:

};