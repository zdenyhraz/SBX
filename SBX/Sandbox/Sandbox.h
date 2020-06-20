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
		m_Components = std::make_shared<ComponentVectors>();
		m_Systems = std::make_shared<SystemVector>( m_Components );
		m_EntityManager = std::make_shared<EntityManager>( m_Components );

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
		m_Systems->Run();
	}

	void Stop()
	{
		LOG_STARTEND( "Stopping systems", "Systems stopped" );
		m_Systems->Stop();
	}

	void StartTime()
	{
		m_TimeRate = 1;
		LOG_INFO( "Time started" );
	}

	void StopTime()
	{
		m_TimeRate = 0;
		LOG_INFO( "Time stopped" );
	}

	void SetTimeRate( double timeRate )
	{
		m_TimeRate = timeRate;
		LOG_INFO( "Time rate set to {}", m_TimeRate );
	}


private:
	double m_Time = 0;
	double m_TimeRate = 1;
	double m_Dt;//fixme

	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<SystemVector> m_Systems;
	std::shared_ptr<EntityManager> m_EntityManager;

};