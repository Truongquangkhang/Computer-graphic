#include <GL/glut.h>
#include <cmath>

using namespace std;

void RenderSineWave()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);  // clear background with black
    glClear(GL_COLOR_BUFFER_BIT);   

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    double ar = w / h;
    glOrtho(0, 360 * ar, -120, 120, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPointSize(3);
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_POINTS);
    for(int i=0;i<500;i=i+1)
    {
        float x = (float)i; 
        float y = 100.0 * sin(i *(3.14/180.0));
        glVertex2f(x,y);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "SineWave.cpp" );
    glutDisplayFunc( RenderSineWave );
    glutMainLoop();
    return 0;
}
