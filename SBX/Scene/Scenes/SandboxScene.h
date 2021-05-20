#pragma once
#include "Scene/Scene.h"

class SandboxScene: public Scene
{
public:
	SandboxScene( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers, std::shared_ptr<SystemVector> systems );

private:
	void OnStart() override;
	void OnStop() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnImGuiRender() override;

	std::shared_ptr<Shader> m_Shader;
	glm::vec4 m_ClearColor;
	std::vector<glm::vec3> m_BoxPositions;
	std::vector<glm::vec3> m_BoxRotations;
	float mTime = 0;
};
