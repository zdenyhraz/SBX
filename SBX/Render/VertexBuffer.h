#pragma once
#include "Stdafx.h"

// <VERTEX BUFFERS>
// - basic storage of vertices
// - gen buffers - unique id
// - bind buffer - state machine
// - buffer data - alloc on GPU
// - default screen coordinates are in [-1, 1]
class VertexBuffer
{
public:
	VertexBuffer( const void *data, unsigned int size );

	~VertexBuffer();

	void Bind() const;

	void Unbind() const;

private:
	unsigned int m_RendererId;
};