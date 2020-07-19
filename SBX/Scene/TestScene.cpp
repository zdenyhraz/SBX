#include "TestScene.h"

TestScene::TestScene():
	Scene(),
	m_ClearColor{0.3, 0.1, 0.3, 1}
{

}

TestScene::~TestScene()
{

}

void TestScene::OnUpdate()
{

}

void TestScene::OnRender()
{
	glClearColor( m_ClearColor.x, m_ClearColor.y, m_ClearColor.z, m_ClearColor.w );
	glClear( GL_COLOR_BUFFER_BIT );

}

void TestScene::OnImGuiRender()
{
	ImGui::SetWindowFontScale( 1.5 );
	ImGui::ColorEdit4( "Clear color", &m_ClearColor.x );
}
