#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "Manager/ManagerVector.h"
#include "Scene/TestScene.h"

class Sandbox
{
public:
	Sandbox();

	~Sandbox();

	void Run();

	void Kill();

private:

	void Init();

	void InitTest();

	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
	std::unique_ptr<Scene> m_Scene;
};