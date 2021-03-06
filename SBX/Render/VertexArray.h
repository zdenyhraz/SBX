#pragma once
#include "Stdafx.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"

// <VERTEX ARRAYS>
// - with multiple objects in the scene we need to (for each object) do the following:
//	 bind shader, buffer, layout, index and then draw
// - vertex array simplifies this - binds the buffer with its layout
// - before draw call we just bind bind shader, array, index and then draw
// - option A: one global bound vertex array and before draw call I bind shader,buffer,layout,index
// - option B: each object has its vertex array and before draw call I bind shader,array,index
// - OpenGL recommends option B
class VertexArray
{
public:
	VertexArray();

	~VertexArray();

	void Bind() const;
	void Unbind() const;

	void SetBuffers( VertexBuffer *vb, VertexBufferLayout *vbl, IndexBuffer *ib );

	VertexBuffer *GetVertexBuffer() const { return m_vb; }
	IndexBuffer *GetIndexBuffer() const { return m_ib; }

private:
	unsigned int m_RenderedId;
	VertexBuffer *m_vb;
	IndexBuffer *m_ib;
};