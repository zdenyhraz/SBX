#pragma once
#include "Stdafx.h"
#include "System/System.h"

class SystemVector
{
public:
	SystemVector( std::shared_ptr<PastFutureComponentVectors> components, std::shared_ptr<ManagerVector> managers );

	void Run();

	void Kill();

private:
	std::vector<std::shared_ptr<System>> Systems;

};