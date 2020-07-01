#include "Stdafx.h"
#include "Sandbox/Sandbox.h"

int main()
{
	std::srand( ( uint )time( 0 ) );

	Sandbox sandbox;

	sandbox.Run();
	std::this_thread::sleep_for( std::chrono::milliseconds( 100 * 1000 ) );
	sandbox.Kill();

	LOG_ERROR( "Press enter twice to end the app" );
	std::cin.ignore();
	return 0;
}