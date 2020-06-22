#pragma once
#include "Stdafx.h"
#include "System.h"

class TimeSystem : public System
{
public:

	TimeSystem( std::shared_ptr<ComponentVectors> components );

	void Tick() override;

private:
	std::string m_ConsoleTitle;
};
