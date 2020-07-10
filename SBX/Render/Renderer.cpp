#include "Renderer.h"

Renderer::Renderer()
{

}

void Renderer::Clear() const
{
	glClear( GL_COLOR_BUFFER_BIT );
}

void Renderer::Draw( const VertexArray &va, const IndexBuffer &ib, const Shader &sh ) const
{
	sh.Bind();
	va.Bind();
	ib.Bind();
	glDrawElements( GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr );



}
