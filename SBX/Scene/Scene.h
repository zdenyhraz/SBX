#pragma once
#include "Stdafx.h"

class Scene
{
public:
	Scene() {};
	virtual ~Scene() {};
	virtual void OnUpdate( float dt ) = 0;
	virtual void OnRender() = 0;
	virtual void OnImGuiRender() = 0;
};