#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);    
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
   
}
 
void ngoisao(float xt, float yt, float r) {
	float *x = new float[5], *y = new float[5], grad = (float) ((72 * 3.14) / 180);	
	x[0] = xt;
	y[0] = yt - r;
	for (int i = 1; i < 5; i++) {
		x[i] = (float) (x[0] * cos(i * grad) - y[0] * sin(i * grad) + yt * sin(i * grad) + xt * (1 - cos(i * grad)));
		y[i] = (float) (x[0] * sin(i * grad) + y[0] * cos(i * grad) + yt * (1 - cos(i * grad)) - xt * sin(i * grad));
	}
	glBegin(GL_LINES);
		glVertex2f(x[0], y[0]);
		glVertex2f(x[2], y[2]);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(x[0], y[0]);
		glVertex2f(x[3], y[3]);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(x[1], y[1]);
		glVertex2f(x[3], y[3]);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(x[1], y[1]);
		glVertex2f(x[4], y[4]);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(x[2], y[2]);
		glVertex2f(x[4], y[4]);
	glEnd();
}
void display() {
   	glClear(GL_COLOR_BUFFER_BIT);   
   	ngoisao(0.5, 0.5, 0.3);
   	glFlush();
}
int main(int argc, char** argv) {
   glutInit(&argc, argv);         \
   glutCreateWindow("Lab"); 
   glutInitWindowSize(500, 500);   
   glutInitWindowPosition(50, 50); 
   glutDisplayFunc(display);       
   initGL();                       
   glutMainLoop();                 
   return 0;
}
