#pragma once
#include "ComponentVectors.h"

struct PastFutureComponentVectors
{
	std::shared_ptr<ComponentVectors> Past;
	std::shared_ptr<ComponentVectors> Future;

	PastFutureComponentVectors()
	{
		Past = std::make_shared<ComponentVectors>();
		Future = std::make_shared<ComponentVectors>();
	}

	void Swap()
	{
		std::swap( Past, Future );
	}
};