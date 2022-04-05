#include <GL/glut.h>
#include <cmath>

using namespace std;

void Render()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);  // clear background with black
    glClear(GL_COLOR_BUFFER_BIT);   
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0, 10, -3, 12, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPointSize(3);
    glColor3f(1.0,1.0,1.0);

    glBegin(GL_POINTS);
    for(float i=0;i<300;i=i+0.0005)
    {
        float x =  i + sin(2.0*i); 
        float y =  i + sin(3.0*i);
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
    glutCreateWindow( "Lab.cpp" );
    glutDisplayFunc( Render );
    glutMainLoop();
    return 0;
}

