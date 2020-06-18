#include "Stdafx.h"
#include "Log/Logger.h"
#include "Sandbox/Sandbox.h"

std::unique_ptr<Sandbox> sandbox = std::make_unique<Sandbox>();

int main()
{
	LOG_SUCC( "App started" );


	LOG_ERROR( "Press any key to end the app ..." );
	std::cin.ignore();
	return 0;
}