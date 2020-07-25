#include "Renderer.h"

std::unique_ptr<RendererStorage> Renderer::m_RendererStorage;

void Renderer::InitStorage()
{
	m_RendererStorage = std::make_unique<RendererStorage>();
}

void Renderer::Clear()
{
	glClear( GL_COLOR_BUFFER_BIT );
}

void Renderer::Draw( const VertexArray &va, const Shader &sh )
{
	sh.Bind();
	va.Bind();
	glDrawElements( GL_TRIANGLES, va.GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr );
}

void Renderer::DrawQuad( const glm::vec3 &pos, const glm::vec3 &rot, float size )
{
	//const glm::mat4 model = glm::translate( glm::mat4( 1.0f ), pos ) * glm::eulerAngleXZY( rot.x, rot.y, rot.z ) * glm::scale( glm::mat4( 1.0f ), glm::vec3( size ) );
	//glm::mat4 mvp = m_Camera3D->m_Proj * m_Camera3D->m_View * model;
	//m_Shader->SetUniformMat4f( "u_MVP", mvp );
	//m_RendererStorage->GetQuadVA()->Bind();
	//m_RendererStorage->GetQuadTex()->Bind();
	//glDrawElements( GL_TRIANGLES, m_RendererStorage->GetQuad()->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr );
}

