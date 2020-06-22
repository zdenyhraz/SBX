#pragma once
#include "Stdafx.h"
#include "System.h"
#include "MovementSystem.h"
#include "DrawSystem.h"
#include "CommandLineSystem.h"
#include "TestSystem.h"
#include "TimeSystem.h"

class SystemVector
{
public:
	SystemVector( std::shared_ptr<ComponentVectors> components );

	void Run();

	void End();

private:
	std::vector<std::shared_ptr<System>> Systems;

};