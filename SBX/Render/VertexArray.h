#pragma once
#include "Stdafx.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
	VertexArray();

	~VertexArray();

	void AddBuffer( const VertexBuffer &vb, const VertexBufferLayout &layout );

private:

};