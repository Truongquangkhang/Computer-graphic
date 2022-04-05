#include <gl/glut.h>
#include <gl/gl.h>
void myInit(void)
{
	glClearColor(0.7f, 0.7f, 0.7f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glMatrixMode(GL_MODELVIEW);
}
void myDisplay(void)
{
	int x = 320, y = 240;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(x - 100, y - 100, x + 100, y + 100);
	glColor3f(1.0f, 1.0f, 0.0f);

	glPushMatrix();
	glRotatef(20, 0, 0, 1);
	glRectf(x - 100, y - 100, x + 100, y + 100);
	glPopMatrix();
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("3_Lab2");
	glutDisplayFunc(myDisplay);
	myInit();		// Our own OpenGL initialization
	glutMainLoop(); // Enter the infinite event-processing loop
	return 0;
}
