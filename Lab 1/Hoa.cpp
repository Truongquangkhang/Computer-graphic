#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);    
   glLoadIdentity();
   glOrtho(0.0, 3.0, 0.0, 3.0, -1.0, 1.0);
   
}
void drawCircle(double x, double y, double r, float red, float gr, float bl)
{
	glBegin(GL_TRIANGLE_FAN);              
		glColor3f(red, gr, bl);          
		double radius = r;
		double ori_x = x;                         
		double ori_y = y;
		for (int i = 0; i <= 300; i++) {
	    	double angle = 2 * 3.14 * i / 300;
	    	double x = cos(angle) * radius;
	    	double y = sin(angle) * radius;
	    	glVertex2d(ori_x + x, ori_y + y);
		}
	glEnd();
	glBegin(GL_LINE_LOOP);              
		glColor3f(0.0, 0.0, 0.0);          
		for (int i = 0; i <= 300; i++) {
	    	double angle = 2 * 3.14 * i / 300;
	    	double x = cos(angle) * radius;
	    	double y = sin(angle) * radius;
	    	glVertex2d(ori_x + x, ori_y + y);
		}
	glEnd();
}
void veHoa(float xt, float yt, float r)
{
    float *x = new float[5], *y = new float[5], grad = (float) ((72 * 3.14) / 180);
	x[0] = xt;
	y[0] = yt - r;
	r += r/3;
	drawCircle(x[0], y[0], r, 0.0, 1.0, 0.0);
    for (int i = 1; i < 5; i++) {
        x[i] = (float) (x[0] * cos(i * grad) - y[0] * sin(i * grad) + yt * sin(i * grad) + xt * (1 - cos(i * grad)));
        y[i] = (float) (x[0] * sin(i * grad) + y[0] * cos(i * grad) + yt * (1 - cos(i * grad)) - xt * sin(i * grad));
        drawCircle(x[i], y[i], r, 0.0, 1.0, 0.0);
    }
    drawCircle(xt, yt, r, 1.0, 1.0, 1.0);
}
void display() {
   	glClear(GL_COLOR_BUFFER_BIT);   
   	veHoa(1, 1, 0.3);
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



