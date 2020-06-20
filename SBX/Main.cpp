#include "Stdafx.h"
#include "Sandbox/Sandbox.h"

int main()
{
	LOG_SUCC( "App started" );

	std::unique_ptr<Sandbox> sandbox = std::make_unique<Sandbox>();

	LOG_ERROR( "Press any key to end the app ..." );
	std::cin.ignore();
	return 0;
}