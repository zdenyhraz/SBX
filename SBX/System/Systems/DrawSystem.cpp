#include "DrawSystem.h"

DrawSystem::DrawSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers ),
	m_WindowName( "SBX OpenCV" ),
	m_WindowWidth( 1500 ),
	m_WindowHeight( 1000 ),
	m_DrawEntityThickness( -1 ),
	m_TextRelOffsetX( 1.5f ),
	m_TextRelOffsetY( 0.5f ),
	m_TextRelScale( 0.05f ),
	m_TextMinRelScale( 0.5f ),
	m_TextThickness( 2 ),
	m_DrawEntityArrowLengthScale( 3.0f ),
	m_DrawEntityArrowThicknessScale( 0.5f ),
	m_FpsTextThickness( 2 ),
	m_FpsTextColor( 0.2, 1, 0.2 ),
	m_FpsTextScale( 1.0f ),
	m_TickDuration( 1000 ),
	m_SizeScale( 5.0f )
{
	m_WindowCenter = cv::Point( m_WindowWidth / 2, m_WindowHeight / 2 );
	m_Blank = cv::Mat::zeros( m_WindowHeight, m_WindowWidth, CV_32FC3 );
	m_Live = m_Blank.clone();
}

void DrawSystem::Tick( float dt )
{
	m_TickStart = Utils::GetTimeNow();
	m_Live = m_Blank.clone();

	for ( auto &model : m_Components->Models.GetContainer() )
	{
		auto pos = m_Components->Positions.Find( model.first );
		auto winpos = GetWindowCoordinates( pos.Position.x, pos.Position.y );
		int size = ( int )( m_SizeScale * model.second.Size );

		cv::circle( m_Live, winpos, size, model.second.Color, m_DrawEntityThickness );
		auto arrow = Utils::UnitVector( m_Components->Velocities.Find( model.first ).Velocity ) * m_DrawEntityArrowLengthScale * ( float )size;
		cv::arrowedLine( m_Live, winpos, winpos + cv::Point( ( int )arrow.x, -( int )arrow.y ), model.second.Color, ( int )( m_DrawEntityArrowThicknessScale * size ) );

		if ( m_Components->EntityInfos.Find( model.first ).Name != "" )
		{
			cv::putText( m_Live, m_Components->EntityInfos.Find( model.first ).Name, winpos + cv::Point( ( int )( m_TextRelOffsetX * size ), ( int )( m_TextRelOffsetY * size ) ), 0, std::max( m_TextRelScale * size, m_TextMinRelScale ), model.second.Color, m_TextThickness );
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

cv::Point DrawSystem::GetWindowCoordinates( float x, float y )
{
	return m_WindowCenter + cv::Point( ( int )( ( x / m_Components->Map.MapWidth ) * ( m_WindowWidth / 2 ) ), -( int )( ( y / m_Components->Map.MapHeight ) * ( m_WindowHeight / 2 ) ) );
}