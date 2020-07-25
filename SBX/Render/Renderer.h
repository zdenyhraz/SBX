#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace Renderer {
void Clear();
void Draw( const VertexArray &va, const IndexBuffer &ib, const Shader &sh );
void Draw( const VertexArray &va );
};
