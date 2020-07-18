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
	double AvoidSpeed = 0;
	double SeekSpeed = 0;
	int TargetId = 0;
};