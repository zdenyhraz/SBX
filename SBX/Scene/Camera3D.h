#pragma once
#include "Stdafx.h"
#include "UserInput.h"

class Camera3D
{
public:
	Camera3D( float aspect ) :
		m_AspectRatio( aspect ),
		m_ViewPos( 0.f, -1.f, 1.f ),
		m_ViewDir( 0.f, 1.f, -1.f ),
		m_UpDir( 0.f, 0.f, 1.f ),
		m_CameraPosSpeed( 0.1f ),
		m_CameraDirSpeed( 0.001f ),
		m_CameraFovSpeed( 3.5f ),
		m_CameraFov( 90.f )
	{
	}

	void Update( const UserInput &ui )
	{
		//m_Camera3D->m_UpDir += ( float )m_UserInput.MouseR * ( m_Camera3D->m_CameraDirSpeed * glm::vec3( m_UserInput.MouseX - m_UserInput.MouseXprev, 0.f, m_UserInput.MouseY - m_UserInput.MouseYprev ) );
		m_ViewDir += ( float )ui.MouseR * ( m_CameraDirSpeed * glm::vec3( ui.MouseX - ui.MouseXprev, 0.f, 0.f ) );
		m_ViewPos += m_ViewDir * m_CameraPosSpeed * ( float )( ui.KeyW - ui.KeyS );

		m_CameraFov += m_CameraFovSpeed * -( float )ui.MouseScroll;
		Utils::Clampr( m_CameraFov, 5.0f, 180.f );

		m_View = glm::lookAt( m_ViewPos, m_ViewPos + m_ViewDir, m_UpDir );
		m_Proj = glm::perspective( glm::radians( m_CameraFov ), m_AspectRatio, 0.1f, 1000.0f );
	}

	glm::mat4 m_Proj;
	glm::mat4 m_View;
	glm::vec3 m_ViewPos;
	glm::vec3 m_ViewDir;
	glm::vec3 m_UpDir;
	float m_AspectRatio;
	float m_CameraPosSpeed;
	float m_CameraDirSpeed;
	float m_CameraFovSpeed;
	float m_CameraFov;
};