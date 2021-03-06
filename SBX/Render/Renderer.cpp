#include "Renderer.h"

std::unique_ptr<RendererStorage> Renderer::m_RendererStorage;
std::unique_ptr<Camera> Renderer::m_Camera;

void Renderer::Init( float aspectRatio )
{
	m_RendererStorage = std::make_unique<RendererStorage>();
	m_Camera = std::make_unique<Camera>( aspectRatio );
}

void Renderer::Clear()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void Renderer::Update( const UserInput &ui )
{
	m_Camera->Update( ui );
}

void Renderer::Draw( VertexArray *va, Shader *sh )
{
	sh->Bind();
	va->Bind();
	glDrawElements( GL_TRIANGLES, va->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr );
}

void Renderer::Draw( Model *model, Shader *sh )
{
	sh->Bind();
	model->Bind();
	glDrawElements( GL_TRIANGLES, model->va->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr );
}

void Renderer::DrawQuad( const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec2 &size, Shader *shader, Texture *texture )
{
	shader->Bind();
	texture->Bind();
	m_RendererStorage->GetQuadVA()->Bind();
	const glm::mat4 model = glm::translate( glm::mat4( 1.0f ), pos ) * glm::eulerAngleXZY( rot.x, rot.y, rot.z ) * glm::scale( glm::mat4( 1.0f ), glm::vec3( size.x / 2, size.y / 2, 1.0f ) );
	shader->SetUniformMat4f( "u_Model", model );
	glDrawElements( GL_TRIANGLES, m_RendererStorage->GetQuadVA()->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr );
}

void Renderer::DrawQuad( const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec2 &size, Shader *shader, const std::string &texname )
{
	DrawQuad( pos, rot, size, shader, m_RendererStorage->GetTexture( texname ) );
}

void Renderer::DrawCube( const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &size, Shader *shader, Texture *texture )
{
	shader->Bind();
	texture->Bind();
	m_RendererStorage->GetCubeVA()->Bind();
	const glm::mat4 model = glm::translate( glm::mat4( 1.0f ), pos ) * glm::eulerAngleXZY( rot.x, rot.y, rot.z ) * glm::scale( glm::mat4( 1.0f ), glm::vec3( size.x / 2, size.y / 2, size.z / 2 ) );
	shader->SetUniformMat4f( "u_Model", model );
	glDrawElements( GL_TRIANGLES, m_RendererStorage->GetCubeVA()->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr );
}

void Renderer::DrawCube( const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &size, Shader *shader, const std::string &texname )
{
	DrawCube( pos, rot, size, shader, m_RendererStorage->GetTexture( texname ) );
}

