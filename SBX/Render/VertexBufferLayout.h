#pragma once
#include "Stdafx.h"

struct VertexBufferElement
{
	unsigned int Count;
	unsigned int Type;
	bool Normalized;
};

class VertexBufferLayout
{
public:

private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
};