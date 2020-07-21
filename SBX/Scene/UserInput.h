#pragma once

struct UserInput
{
	bool KeyW = false;
	bool KeyS = false;
	bool KeyA = false;
	bool KeyD = false;
	bool MouseL = false;
	bool MouseR = false;
	float MouseX = 0;
	float MouseY = 0;
	float MouseXprev = 0;
	float MouseYprev = 0;
	float MouseScroll = 0;

	void Update()
	{
		MouseXprev = MouseX;
		MouseYprev = MouseY;
		MouseScroll = 0;
	}
};