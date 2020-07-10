#pragma once
#include "Stdafx.h"

class Scene
{
public:
	Scene() {};
	virtual ~Scene() {};

	virtual void OnUpdate() {};
	virtual void OnRender() {};
	virtual void OnImGuiRender() {};
};