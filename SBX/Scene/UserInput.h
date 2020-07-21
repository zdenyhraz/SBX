#pragma once

struct UserInput
{
	bool KeyW = false;
	bool KeyS = false;
	bool KeyA = false;
	bool KeyD = false;
	bool MouseL = false;
	bool MouseR = false;
	double MouseX = 0;
	double MouseY = 0;
	double MouseXprev = 0;
	double MouseYprev = 0;
	double MouseScroll = 0;

	void Update()
	{
		MouseXprev = MouseX;
		MouseYprev = MouseY;
		MouseScroll = 0;
	}
};