#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors/ComponentVectors.h"

class System
{
public:
	virtual void Run() = 0;
	virtual void Tick( double dt ) = 0;

private:
};