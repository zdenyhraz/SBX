#pragma once
#include "Stdafx.h"

class SystemVector;

class SystemManager
{
public:
	SystemManager( std::shared_ptr<SystemVector> systems );

	void Run();

	void End();

private:
	std::shared_ptr<SystemVector> m_Systems;
};