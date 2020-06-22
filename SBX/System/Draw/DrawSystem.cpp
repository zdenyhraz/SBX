#include "DrawSystem.h"

DrawSystem::DrawSystem( std::shared_ptr<ComponentVectors> components ) :
	System( components, "Draw" ),
	m_WindowName( "SBX" ),
	m_WindowWidth( 1500 ),
	m_WindowHeight( 1000 ),
	m_MapWidth( 1 ),
	m_MapHeight( 1 ),
	m_DrawEntityThickness( -1 ),
	m_TextRelOffsetX( 1.5 ),
	m_TextRelOffsetY( 0.5 ),
	m_TextRelScale( 0.05 ),
	m_TextMinRelScale( 0.5 ),
	m_TextThickness( 2 )
{
	m_WindowCenter = cv::Point( m_WindowWidth / 2, m_WindowHeight / 2 );
	m_Blank = cv::Mat::zeros( m_WindowHeight, m_WindowWidth, CV_32FC3 );
	m_Live = m_Blank.clone();
}

void DrawSystem::Tick()
{
	m_Live = m_Blank.clone();

	for ( auto &model : m_Components->Models.Data )
	{
		auto pos = m_Components->Positions.Find( model.first );
		cv::circle( m_Live, GetWindowCoordinates( pos.Position.x, pos.Position.y ), model.second.Size, model.second.Color, m_DrawEntityThickness );
		cv::putText( m_Live, m_Components->EntityInfos.Find( model.first ).Name, GetWindowCoordinates( pos.Position.x, pos.Position.y ) + cv::Point( ( int )( m_TextRelOffsetX * model.second.Size ), ( int )( m_TextRelOffsetY * model.second.Size ) ), 0, std::max( m_TextRelScale * model.second.Size, m_TextMinRelScale ), model.second.Color, m_TextThickness );
	}

	cv::namedWindow( m_WindowName, cv::WINDOW_NORMAL );
	cv::resizeWindow( m_WindowName, m_WindowWidth, m_WindowHeight );
	cv::imshow( m_WindowName, m_Live );
	cv::waitKey( 1 );
}

cv::Point DrawSystem::GetWindowCoordinates( double x, double y )
{
	return m_WindowCenter + cv::Point( ( int )( ( x / m_MapWidth ) * ( m_WindowWidth / 2 ) ), ( int )( ( y / m_MapHeight ) * ( m_WindowHeight / 2 ) ) );
}