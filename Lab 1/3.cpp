#include <GL/glut.h>
#include <math.h>
float distance(float x1, float y1, float x2, float y2)
{
   return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
void drawCircle(float x1, float y1, float x2, float y2, float x3, float y3)
{
   float c = distance(x1, y1, x2, y2);
   float a = distance(x2, y2, x3, y3);
   float b = distance(x1, y1, x3, y3);

   float h = (a * x1 + b * x2 + c * x3) / (a + b + c);
   float k = (a * y1 + b * y2 + c * y3) / (a + b + c);

   float p = (a + b + c) / 2;
   float area = sqrt(p * (p - a) * (p - b) * (p - c));

   glBegin(GL_LINE_LOOP);
   double radius = area / p;
   double ori_x = h;
   double ori_y = k;
   for (int i = 0; i <= 300; i++)
   {
      double angle = 2 * 3.14 * i / 300;
      double x = cos(angle) * radius;
      double y = sin(angle) * radius;
      glVertex2d(ori_x + x, ori_y + y);
   }
   glEnd();
}
void initGL()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   float x1 = 0.3, y1 = 0.8;
   float x2 = 0.2, y2 = 0.4;
   float x3 = 0.5, y3 = 0.3;
   glBegin(GL_LINE_LOOP);
   glVertex2f(x1, y1);
   glVertex2f(x2, y2);
   glVertex2f(x3, y3);
   glEnd();
   drawCircle(x1, y1, x2, y2, x3, y3);
   glFlush();
}
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutCreateWindow("Lab");
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(50, 50);
   glutDisplayFunc(display);
   initGL();
   glutMainLoop();
   return 0;
}
