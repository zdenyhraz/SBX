#include "TemplateScene.h"

TemplateScene::TemplateScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems ) :
	Scene( components, managers, systems )
{

}

TemplateScene::~TemplateScene()
{

}

void TemplateScene::OnGLInit()
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
