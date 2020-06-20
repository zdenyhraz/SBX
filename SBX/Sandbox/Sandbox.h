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
		InitTest();
	}

	void InitTest()
	{
		LOG_STARTEND( "Initializing sandbox world", "Sandbox world initialized" );

		int initEntityCnt = 1000;
		LOG_DEBUG( "Initializing {} entities", initEntityCnt );

		for ( int i = 0; i < initEntityCnt; i++ )
		{
			m_EntityManager->CreateEntity();
		}

		for ( auto &pos : m_Components->Positions.Data )
		{
			pos.second.x = Utils::Rand11() * 1.5;
			pos.second.y = Utils::Rand11() * 1;
		}

		for ( auto &vel : m_Components->Velocities.Data )
		{
			vel.second.vx = Utils::Rand11() * 0.2;
			vel.second.vy = Utils::Rand11() * 0.2;
		}

		for ( auto &acc : m_Components->Accelerations.Data )
		{
			acc.second.ax = Utils::Rand11() * 0.1;
			acc.second.ay = Utils::Rand11() * 0.1;
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

	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<SystemVector> m_Systems;
	std::shared_ptr<EntityManager> m_EntityManager;

};