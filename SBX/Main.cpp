#include "Stdafx.h"
#include "Sandbox/Sandbox.h"

int main()
{
	std::srand( ( uint )time( 0 ) );
	std::unique_ptr<Sandbox> sandbox = std::make_unique<Sandbox>();

	sandbox->Run();
	std::this_thread::sleep_for( std::chrono::milliseconds( 10 * 1000 ) );
	sandbox->Kill();

	LOG_ERROR( "Press enter twice to end the app" );
	std::cin.ignore();
	return 0;
}