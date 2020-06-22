#pragma once
#include "Stdafx.h"
#include "System/System.h"

class TemplateSystem : public System
{
public:

	TemplateSystem( std::shared_ptr<ComponentVectors> components );

	void Tick() override;

private:
};
