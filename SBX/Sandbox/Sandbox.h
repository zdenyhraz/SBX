#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "System/SystemVector.h"
#include "Manager/ManagerVector.h"

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
	std::shared_ptr<SystemVector> m_Systems;
	std::shared_ptr<ManagerVector> m_Managers;
};