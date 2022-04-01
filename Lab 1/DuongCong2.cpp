#include <GL/glut.h>
#include <cmath>

using namespace std;
/*
void RenderCosWave()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);  // clear background with black
    glClear(GL_COLOR_BUFFER_BIT);   
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(-2, 2, -3, 3, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPointSize(3);
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_POINTS);
    for(float i=0;i<300;i=i+0.0005)
    {
        float x = cos(i) - cos(80*i)*sin(i); 
        float y = 2.0*sin(i) - sin(80*i);
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
    glutDisplayFunc( RenderCosWave );
    glutMainLoop();
    return 0;
}
*/
