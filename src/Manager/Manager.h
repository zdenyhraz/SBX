#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"

class Manager
{
public:
	Manager( std::shared_ptr<ComponentVectors> components );

protected:
	std::shared_ptr<ComponentVectors> m_Components;
	std::mutex m_mutex;

private:

};

