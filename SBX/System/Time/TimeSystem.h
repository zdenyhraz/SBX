#pragma once
#include "Stdafx.h"
#include "System/System.h"

class TimeSystem : public System
{
public:

	TimeSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick() override;

private:
	std::string m_ConsoleTitle;
};
