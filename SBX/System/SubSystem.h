#pragma once
#include "Component/ComponentVectors.h"
#include "Manager/ManagerVector.h"

class SubSystem
{
public:

	SubSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	virtual void Tick() = 0;

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;

};