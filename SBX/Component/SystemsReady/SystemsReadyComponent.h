#pragma once
#include "Component/Component.h"

struct SystemsReadyComponent : Component
{
	void SubscribeSystem( const std::string &systemName )
	{
		SystemsReady.emplace( std::pair<std::string, bool>( systemName, false ) );
		LOG_INFO( "System {} ready status subscribed", systemName );
	}

	void UnsubscribeSystem( const std::string &systemName )
	{
		SystemsReady.erase( systemName );
		LOG_INFO( "System {} ready status unsubscribed", systemName );
	}

	void NotifySystemReady( const std::string &systemName )
	{
		SystemsReady.find( systemName )->second = true;
	}

	void ClearStatus()
	{
		for ( auto &system : SystemsReady )
		{
			system.second = false;
		}
	}

	bool Ready()
	{
		bool ready = true;
		for ( auto &system : SystemsReady )
		{

			if ( !( system.second ) )
			{
				ready = false;
				LOG_ERROR( "System {} not ready!", system.first );
			}
			else
			{
				LOG_SUCC( "System {} ready!", system.first );
			}

			/*
			if ( !( system.second ) )
			{
				ready = false;
				break;
			}
			*/
		}
		return ready;
	}

private:
	std::unordered_map<std::string, bool> SystemsReady;
};