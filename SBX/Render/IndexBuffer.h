#pragma once
#include "Stdafx.h"

// <INDEX BUFFERS>
// - index buffers help reuse memory - no need to copy adjacent vertices
// - draw call count is all the indices tho
class IndexBuffer
{
public:
	IndexBuffer( const unsigned int *data, unsigned int count );

	~IndexBuffer();

	void Bind() const;

	void Unbind() const;

	inline unsigned int GetCount() const { return m_Count; }

private:
	unsigned int m_RendererId;
	unsigned int m_Count;
};