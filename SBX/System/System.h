#pragma once
#include "Component/ComponentVectors.h"
#include "Manager/ManagerVector.h"

class System
{
public:
	System( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );
	~System();

	virtual void Tick( float dt ) = 0;

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<ManagerVector> m_Managers;
};

