#include "TemplateScene.h"

TemplateScene::TemplateScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems ) :
	Scene( components, managers, systems )
{

}

void TemplateScene::OnStart()
{

}

void TemplateScene::OnStop()
{

}

void TemplateScene::OnUpdate()
{

}

void TemplateScene::OnRender()
{

}

void TemplateScene::OnImGuiRender()
{

}

void TemplateScene::OnKeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods )
{

}

void TemplateScene::OnScrollCallback( GLFWwindow *window, double xoffset, double yoffset )
{

}

