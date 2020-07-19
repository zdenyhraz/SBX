#include "System.h"

System::System( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ):
	m_Components( components ),
	m_Managers( managers )
{

}

void System::Tick( float dt )
{

}

void System::Run()
{

}

