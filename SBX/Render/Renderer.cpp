#include "Renderer.h"

void Renderer::Clear()
{
	glClear( GL_COLOR_BUFFER_BIT );
}

void Renderer::Draw( const VertexArray &va, const IndexBuffer &ib, const Shader &sh )
{
	sh.Bind();
	va.Bind();
	ib.Bind();
	glDrawElements( GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr );
}
