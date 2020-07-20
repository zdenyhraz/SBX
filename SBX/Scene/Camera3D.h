#pragma once
#include "Stdafx.h"

class Camera3D
{
public:
	Camera3D( float aspect ) :
		m_AspectRatio( aspect ),
		m_ViewPos( 0.f, -1.f, 1.f ),
		m_ViewDir( 0.f, 1.f, -1.f ),
		m_UpDir( 0.f, 0.f, 1.f ),
		m_CameraMoveSpeed( 0.1f ),
		m_CameraFovSpeed( 3.5f ),
		m_CameraFov( 90.f )
	{
	}

	void Update()
	{
		m_ViewDir = glm::normalize( m_ViewDir );
		m_View = glm::lookAt( m_ViewPos, m_ViewPos + m_ViewDir, m_UpDir );
		m_Proj = glm::perspective( glm::radians( m_CameraFov ), m_AspectRatio, 0.1f, 1000.0f );
	}

	glm::mat4 m_Proj;
	glm::mat4 m_View;
	glm::vec3 m_ViewPos;
	glm::vec3 m_ViewDir;
	glm::vec3 m_UpDir;
	float m_AspectRatio;
	float m_CameraMoveSpeed;
	float m_CameraFovSpeed;
	float m_CameraFov;
};