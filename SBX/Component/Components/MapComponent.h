#pragma once

struct MapComponent
{
	static constexpr double MapWidth = 1;
	static constexpr double MapHeight = 1;

	static constexpr double MinPositionX = -MapWidth;
	static constexpr double MinPositionY = -MapHeight;

	static constexpr double MaxPositionX = MapWidth;
	static constexpr double MaxPositionY = MapHeight;

};