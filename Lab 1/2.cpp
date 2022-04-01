#include <GL/glut.h>
#include <math.h>
/*
void drawCircle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float x12 = x1 - x2;
    float x13 = x1 - x3;
 
    float y12 = y1 - y2;
    float y13 = y1 - y3;
 
    float y31 = y3 - y1;
    float y21 = y2 - y1;
 
    float x31 = x3 - x1;
    float x21 = x2 - x1;
 
    // x1^2 - x3^2
    float sx13 = pow(x1, 2) - pow(x3, 2);
 
    // y1^2 - y3^2
    float sy13 = pow(y1, 2) - pow(y3, 2);
 
    float sx21 = pow(x2, 2) - pow(x1, 2);
    float sy21 = pow(y2, 2) - pow(y1, 2);
 
    float f = ((sx13) * (x12)
             + (sy13) * (x12)
             + (sx21) * (x13)
             + (sy21) * (x13))
            / (2 * ((y31) * (x12) - (y21) * (x13)));
    float g = ((sx13) * (y12)
             + (sy13) * (y12)
             + (sx21) * (y13)
             + (sy21) * (y13))
            / (2 * ((x31) * (y12) - (x21) * (y13)));
 
    float c = -pow(x1, 2) - pow(y1, 2) - 2 * g * x1 - 2 * f * y1;

    float h = -g;
    float k = -f;
    float sqr_of_r = h * h + k * k - c;
 
    float r = sqrt(sqr_of_r);

    glBegin(GL_LINE_LOOP);                        
		double radius = r;
		double ori_x = h;                         
		double ori_y = k;
		for (int i = 0; i <= 300; i++) {
	    	double angle = 2 * 3.14 * i / 300;
	    	double x = cos(angle) * radius;
	    	double y = sin(angle) * radius;
	    	glVertex2d(ori_x + x, ori_y + y);
		}
	glEnd();
}
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);    
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
 
void display() {
   	glClear(GL_COLOR_BUFFER_BIT);   
   	float x1 = 0.3, y1 = 0.8;
    float x2 = 0.2, y2 = 0.4;
    float x3 = 0.5, y3 = 0.3;
    glBegin(GL_TRIANGLES);
    	glVertex2f(x1, y1);
    	glVertex2f(x2, y2);
    	glVertex2f(x3, y3);
    glEnd();
    drawCircle(x1, y1, x2, y2, x3, y3);
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
*/

