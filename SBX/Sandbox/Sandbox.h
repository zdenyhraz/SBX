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
		LOG_STARTEND( "Initializing sandbox world", "Sandbox world initialized" );
		InitTest();
	}

	void InitTest()
	{

		int initEntityCnt = 3;
		LOG_DEBUG( "Initializing {} entities", initEntityCnt );

		for ( int i = 0; i < initEntityCnt; i++ )
		{
			m_EntityManager->CreateEntity();
		}

		for ( auto &mod : m_Components->Models.Data )
		{
			mod.second.m_Color = cv::Scalar( Utils::Rand01(), Utils::Rand01(), Utils::Rand01() );
			mod.second.m_Size = Utils::Rand01() * 20;
		}

		for ( auto &pos : m_Components->Positions.Data )
		{
			const double spread = 0.8;
			pos.second.x = Utils::Rand11() * spread;
			pos.second.y = Utils::Rand11() * spread;
		}

		for ( auto &vel : m_Components->Velocities.Data )
		{
			vel.second.x = Utils::Rand11() * 0.5;
			vel.second.y = Utils::Rand11() * 0.5;

		}

		for ( auto &acc : m_Components->Accelerations.Data )
		{
			//acc.second.x = Utils::Rand11() * 0.05;
			//acc.second.y = Utils::Rand11() * 0.05;


			//acc.second.x = m_Components->Positions.Find( acc.first ).y * +0.1;
			//acc.second.y = m_Components->Positions.Find( acc.first ).x * -0.1;
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