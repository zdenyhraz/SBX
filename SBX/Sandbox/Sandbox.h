#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "System/SystemVector.h"
#include "Manager/EntityManager.h"
#include "Manager/SystemManager.h"

class Sandbox
{
public:
	Sandbox();

	~Sandbox();

	void Init();

	void InitTest();

	void RunSystems();

	void EndSystems();

private:

	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<SystemVector> m_Systems;
	std::shared_ptr<EntityManager> m_EntityManager;
	std::shared_ptr<SystemManager> m_SystemManager;

};