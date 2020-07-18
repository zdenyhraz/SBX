#pragma once

struct EntityInfoComponent
{
	enum EntityType
	{
		Entity,
		Camera,
		Light
	};


	int Id = 0;
	EntityType Type = Entity;
	std::string Name = "";
	int Health = 100;
};