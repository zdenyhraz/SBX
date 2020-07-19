#pragma once
#include "Component/ComponentVectors.h"
#include "Manager/ManagerVector.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	virtual void Tick( float dt );
	virtual void Run();

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
};

