#include "RenderSystem.h"

RenderSystem::RenderSystem( std::shared_ptr<ComponentVectors> components, std::shared_ptr<ManagerVector> managers ) :
	System( components, managers, "Render", true )
{

}

void RenderSystem::Tick()
{
	glfwInit();
	m_Window = glfwCreateWindow( 640, 480, "Hello OpenGL", NULL, NULL );
	glfwMakeContextCurrent( m_Window );
	glewInit();

	while ( !glfwWindowShouldClose( m_Window ) )
	{
		glClear( GL_COLOR_BUFFER_BIT );
		//----------------------------

		glBegin( GL_TRIANGLES );
		glVertex2f( -0.5f, -0.5f );
		glVertex2f( 0.0f, 0.5f );
		glVertex2f( 0.5f, -0.5f );
		glEnd();

		//----------------------------
		glfwSwapBuffers( m_Window );
		glfwPollEvents();
	}

	glfwTerminate();
}