#pragma once
#include "Stdafx.h"
#include "Component/PastFutureComponentVectors.h"

class Manager
{
public:
	Manager( std::shared_ptr<PastFutureComponentVectors> components );

protected:
	std::shared_ptr<PastFutureComponentVectors> m_Components;
	std::mutex m_mutex;

};

