#pragma once
#include "Stdafx.h"
#include "Component/ComponentVectors.h"
#include "System/SystemVector.h"
#include "Manager/EntityManager.h"

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

		int initEntityCnt = 20;
		LOG_DEBUG( "Initializing {} entities", initEntityCnt );

		for ( int i = 0; i < initEntityCnt; i++ )
		{
			m_EntityManager->CreateEntity();
		}

		m_Components->EntityInfos.Find( 0 ).Name = "Saska";

		for ( auto &mod : m_Components->Models.Data )
		{
			mod.second.Color = cv::Scalar( Utils::Rand01(), Utils::Rand01(), Utils::Rand01() );
			mod.second.Size = Utils::Rand01() * 30;
		}

		for ( auto &pos : m_Components->Positions.Data )
		{
			const double spread = 0.8;
			pos.second.Position.x = Utils::Rand11() * spread;
			pos.second.Position.y = Utils::Rand11() * spread;
		}

		for ( auto &vel : m_Components->Velocities.Data )
		{
			vel.second.Velocity.x = Utils::Rand11() * 0.5;
			vel.second.Velocity.y = Utils::Rand11() * 0.5;
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


private:

	std::shared_ptr<ComponentVectors> m_Components;
	std::shared_ptr<SystemVector> m_Systems;
	std::shared_ptr<EntityManager> m_EntityManager;
};