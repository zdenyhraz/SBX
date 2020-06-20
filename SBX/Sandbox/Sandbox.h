#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "System/SystemVector.h"
#include "EntityManager.h"

class Sandbox
{
public:
	Sandbox()
	{
		LOG_STARTEND( "Creating sandbox", "Sandbox created" );
		Components = std::make_shared<ComponentVectors>();
		Systems = std::make_shared<SystemVector>( Components );
		m_EntityManager = std::make_shared<EntityManager>( Components );

		Init();
		Run();
	}

	~Sandbox()
	{
		LOG_INFO( "Sandbox destructed" );
	}

	void Init()
	{
		LOG_STARTEND( "Initializing sandbox", "Sandbox initialized" );
		for ( int i = 0; i < 1000; i++ )
		{
			m_EntityManager->CreateEntity();
		}
	}

	void Run()
	{
		LOG_STARTEND( "Running systems", "Systems ran" );
		Systems->Run();
	}

	void Stop()
	{
		LOG_STARTEND( "Stopping systems", "Systems stopped" );
		Systems->Stop();
	}

	void StartTime()
	{
		TimeRate = 1;
		LOG_INFO( "Time started" );
	}

	void StopTime()
	{
		TimeRate = 0;
		LOG_INFO( "Time stopped" );
	}

	void SetTimeRate( double timeRate )
	{
		TimeRate = timeRate;
		LOG_INFO( "Time rate set to {}", TimeRate );
	}


private:
	double Time = 0;
	double TimeRate = 1;
	double Dt;//fixme

	std::shared_ptr<ComponentVectors> Components;
	std::shared_ptr<SystemVector> Systems;
	std::shared_ptr<EntityManager> m_EntityManager;

};