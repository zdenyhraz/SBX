#pragma once

struct AgentComponent
{
	enum MovementBehaviour
	{
		None,
		Avoiding,
		Seeking,
		Swarming
	};

	MovementBehaviour MovementBehaviour = None;
	float AvoidSpeed = 0;
	float SeekSpeed = 0;
	int TargetId = 0;
};