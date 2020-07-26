#pragma once
#include "Stdafx.h"
#include "Scene/UserInput.h"

class Camera
{
public:
	Camera( float aspectRatio ) :
		m_AspectRatio( aspectRatio ),
		m_ViewPos( 1.5f, -1.5f, 1.5f ),
		m_ViewDir( 0.f, 0.f, 0.f ),
		m_UpDirDef( 0.f, 0.f, 1.f ),
		m_UpDir( 0.f, 0.f, 1.f ),
		m_CameraPosSpeed( 0.02f ),
		m_CameraDirSpeed( 0.1f ),
		m_CameraFovSpeed( 5.f ),
		m_CameraFov( 80.f ),
		m_Target( 0.f, 0.f, 0.f ),
		m_Targeted( false ),
		m_Pitch( 45 ),
		m_Yaw( -45 )
	{
	}

	void Update( const UserInput &ui )
	{
		m_Pitch += ( float )ui.MouseR * m_CameraDirSpeed * -( ui.MouseY - ui.MouseYprev );
		m_Yaw += ( float )ui.MouseR * m_CameraDirSpeed * ( ui.MouseX - ui.MouseXprev );
		Utils::Clampr( m_Pitch, 1.f, 179.f );

		m_ViewDir.x = sin( glm::radians( m_Yaw ) ) * sin( glm::radians( m_Pitch ) );
		m_ViewDir.y = cos( glm::radians( m_Yaw ) ) * sin( glm::radians( m_Pitch ) );
		m_ViewDir.z = -cos( glm::radians( m_Pitch ) );

		m_RightDir = glm::normalize( glm::cross( m_UpDirDef, m_ViewDir ) );
		m_UpDir = glm::cross( m_ViewDir, m_RightDir );

		m_ViewPos += m_CameraPosSpeed * ( m_ViewDir  * ( float )( ui.KeyW - ui.KeyS ) + m_RightDir * ( float )( ui.KeyA - ui.KeyD ) );

		m_CameraFov += m_CameraFovSpeed * -( float )ui.MouseScroll;
		Utils::Clampr( m_CameraFov, 5.0f, 180.f );

		m_View = glm::lookAt( m_ViewPos, m_ViewPos + m_ViewDir, m_UpDir );
		m_Proj = glm::perspective( glm::radians( m_CameraFov ), m_AspectRatio, 0.1f, 1000.0f );

		if ( m_Targeted )
		{

		}
	}

	void StartTargeting( glm::vec3 &target )
	{
		m_Targeted = true;
		m_Target = target;
	}

	void StopTargeting()
	{
		m_Targeted = false;
	}

	glm::mat4 m_Proj;
	glm::mat4 m_View;
	glm::vec3 m_ViewPos;
	glm::vec3 m_ViewDir;
	glm::vec3 m_UpDir;
	glm::vec3 m_RightDir;
	glm::vec3 m_UpDirDef;
	glm::vec3 m_Target;
	float m_Pitch;
	float m_Yaw;
	bool m_Targeted;
	float m_AspectRatio;
	float m_CameraPosSpeed;
	float m_CameraDirSpeed;
	float m_CameraFovSpeed;
	float m_CameraFov;
};