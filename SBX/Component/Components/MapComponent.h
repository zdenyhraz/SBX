#pragma once

struct MapComponent
{
	static constexpr float MapWidth = 1;
	static constexpr float MapHeight = 1;

	static constexpr float MinPositionX = -MapWidth;
	static constexpr float MinPositionY = -MapHeight;

	static constexpr float MaxPositionX = MapWidth;
	static constexpr float MaxPositionY = MapHeight;

};