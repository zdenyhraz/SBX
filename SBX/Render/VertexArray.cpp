#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays( 1, &m_RenderedId );
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays( 1, &m_RenderedId );
}

void VertexArray::Bind() const
{
	glBindVertexArray( m_RenderedId );
}

void VertexArray::Unbind() const
{
	glBindVertexArray( 0 );
}

void VertexArray::AddBuffer( const VertexBuffer &vb, const VertexBufferLayout &layout )
{
	Bind();
	vb.Bind();
	const auto &elements = layout.GetElements();
	unsigned int offset = 0;
	for ( unsigned int i = 0; i < elements.size(); i++ )
	{
		const auto &element = elements[i];
		glEnableVertexAttribArray( i );
		glVertexAttribPointer( i, element.Count, element.Type, element.Normalized, layout.GetStride(), ( const void * )offset );
		offset += element.Count * VertexBufferLayoutElement::GetSizeOfType( element.Type );
	}
}
