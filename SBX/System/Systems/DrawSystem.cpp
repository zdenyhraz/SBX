#include "DrawSystem.h"

DrawSystem::DrawSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Draw", true ),
	m_WindowName( "SBX OpenCV" ),
	m_WindowWidth( 1500 ),
	m_WindowHeight( 1000 ),
	m_DrawEntityThickness( -1 ),
	m_TextRelOffsetX( 1.5 ),
	m_TextRelOffsetY( 0.5 ),
	m_TextRelScale( 0.05 ),
	m_TextMinRelScale( 0.5 ),
	m_TextThickness( 2 ),
	m_DrawEntityArrowLengthScale( 3 ),
	m_DrawEntityArrowThicknessScale( 0.5 ),
	m_FpsTextThickness( 2 ),
	m_FpsTextColor( 0.2, 1, 0.2 ),
	m_FpsTextScale( 1 ),
	m_TickDuration( 1000 )
{
	m_WindowCenter = cv::Point( m_WindowWidth / 2, m_WindowHeight / 2 );
	m_Blank = cv::Mat::zeros( m_WindowHeight, m_WindowWidth, CV_32FC3 );
	m_Live = m_Blank.clone();
}

void DrawSystem::Tick()
{
	m_TickStart = Utils::GetTimeNow();
	m_Live = m_Blank.clone();

	for ( auto &model : m_Components->Models.GetContainer() )
	{
		auto pos = m_Components->Positions.Find( model.first );
		auto winpos = GetWindowCoordinates( pos.Position.x, pos.Position.y );

		if ( model.second.Size )
		{
			cv::circle( m_Live, winpos, model.second.Size, model.second.Color, m_DrawEntityThickness );
			cv::arrowedLine( m_Live, winpos, winpos + ( cv::Point )( Utils::UnitVector( m_Components->Velocities.Find( model.first ).Velocity ) * m_DrawEntityArrowLengthScale * model.second.Size ), model.second.Color, ( int )( m_DrawEntityArrowThicknessScale * model.second.Size ) );
		}

		if ( m_Components->EntityInfos.Find( model.first ).Name != "" )
		{
			cv::putText( m_Live, m_Components->EntityInfos.Find( model.first ).Name, winpos + cv::Point( ( int )( m_TextRelOffsetX * model.second.Size ), ( int )( m_TextRelOffsetY * model.second.Size ) ), 0, std::max( m_TextRelScale * model.second.Size, m_TextMinRelScale ), model.second.Color, m_TextThickness );
		}
	}

	cv::putText( m_Live, std::to_string( ( int )( 1000 / m_TickDuration ) ) + " fps", cv::Point( 0, ( int )( 0.025 * m_WindowHeight * m_FpsTextScale ) ), 0, m_FpsTextScale, m_FpsTextColor, m_FpsTextThickness );

	cv::namedWindow( m_WindowName, cv::WINDOW_NORMAL );
	cv::resizeWindow( m_WindowName, m_WindowWidth, m_WindowHeight );
	cv::imshow( m_WindowName, m_Live );
	cv::waitKey( 1 );

	m_TickEnd = Utils::GetTimeNow();
	m_TickDuration = Utils::GetDuration( m_TickStart, m_TickEnd );
}

cv::Point DrawSystem::GetWindowCoordinates( double x, double y )
{
	return m_WindowCenter + cv::Point( ( int )( ( x / m_Components->Map.MapWidth ) * ( m_WindowWidth / 2 ) ), ( int )( ( y / m_Components->Map.MapHeight ) * ( m_WindowHeight / 2 ) ) );
}