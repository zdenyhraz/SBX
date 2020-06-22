#pragma once
#include "Stdafx.h"
#include "System.h"

class SystemVector
{
public:
	SystemVector( std::shared_ptr<ComponentVectors> components );

	void Run();

	void End();

private:
	std::vector<std::shared_ptr<System>> Systems;

};