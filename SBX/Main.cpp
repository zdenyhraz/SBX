#include "Stdafx.h"
#include "Log/Logger.h"
#include "Sandbox/Sandbox.h"

int main()
{
	std::unique_ptr<Logger> logger = std::make_unique<Logger>();
	std::unique_ptr<Sandbox> sandbox = std::make_unique<Sandbox>();

	LOG_INFO( "yeeeea boiii" );

	std::cin.ignore();
	return 0;
}