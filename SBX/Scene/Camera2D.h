#pragma once
#include "Stdafx.h"

class Camera2D
{
public:
	Camera2D( float aspect ):
		m_AspectRatio( aspect ),
		m_ViewPos( 0.f, 0.f, 1.f ),
		m_CameraMoveSpeed( 0.01f ),
		m_CameraZoomSpeed( 0.1f ),
		m_CameraZoom( 1.f )
	{
	}

	void Update()
	{
		m_View = glm::translate( glm::mat4( 1.0f ), -m_ViewPos );
		m_Proj = glm::ortho( -1.0f * m_CameraZoom, 1.0f * m_CameraZoom, -1.0f / m_AspectRatio * m_CameraZoom, 1.0f / m_AspectRatio * m_CameraZoom, -1.0f, 1.0f );
	}

	glm::mat4 m_Proj;
	glm::mat4 m_View;
	glm::vec3 m_ViewPos;
	float m_CameraMoveSpeed;
	float m_CameraZoomSpeed;
	float m_CameraZoom;
	float m_AspectRatio;
};