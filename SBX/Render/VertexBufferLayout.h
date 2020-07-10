#pragma once
#include "Stdafx.h"

// <VERTEX ATTRIB POINTERS>
// - specifies layout of the data in vertex buffer
// - need to specify attrib layouts for all attrribs - one buffer can have multiple attribs (position, normal,..)
// - arg1: index of vertex attribute (just one - position)
// - arg2: count of <T> per vertex attribute (two - 2D position)
// - arg3: <T> type (float)
// - arg4: normalize to 0-1 (false)
// - arg5: stride between vertices (byte size of one vertex)
// - arg6: byte offset to this attribute
struct VertexBufferLayoutElement
{
	unsigned int Type;
	unsigned int Count;
	unsigned char Normalized;

	static unsigned int GetSizeOfType( unsigned int type )
	{
		switch ( type )
		{
			case GL_FLOAT:
				return sizeof( GLfloat );
			case GL_UNSIGNED_INT:
				return sizeof( GLuint );
			case GL_UNSIGNED_BYTE:
				return sizeof( GLbyte );
		}
		return 0;
	}
};

class VertexBufferLayout
{
public:
	VertexBufferLayout():
		m_Stride( 0 )
	{
	}

	template<typename T>
	void Push( unsigned int count )
	{
		static_assert( false );
	}

	template<>
	void Push<float>( unsigned int count )
	{
		m_ElementLayouts.push_back( { GL_FLOAT, count, GL_FALSE } );
		m_Stride += count * VertexBufferLayoutElement::GetSizeOfType( GL_FLOAT );
	}

	template<>
	void Push<unsigned int>( unsigned int count )
	{
		m_ElementLayouts.push_back( { GL_UNSIGNED_INT, count, GL_FALSE } );
		m_Stride += count * VertexBufferLayoutElement::GetSizeOfType( GL_UNSIGNED_INT );
	}

	template<>
	void Push<unsigned char>( unsigned int count )
	{
		m_ElementLayouts.push_back( { GL_UNSIGNED_BYTE, count, GL_TRUE } );
		m_Stride += count * VertexBufferLayoutElement::GetSizeOfType( GL_UNSIGNED_BYTE );
	}

	inline const std::vector<VertexBufferLayoutElement> &GetElements() const { return m_ElementLayouts; }

	inline unsigned int GetStride() const { return m_Stride; }


private:
	std::vector<VertexBufferLayoutElement> m_ElementLayouts;
	unsigned int m_Stride;
};