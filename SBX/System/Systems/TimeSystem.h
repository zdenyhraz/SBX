#pragma once
#include "System/System.h"

class TimeSystem : public System
{
public:

	TimeSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Tick( float dt ) override;

private:
	std::string m_ConsoleTitle;
	bool m_SystemsReady;
};
