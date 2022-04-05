#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;
void initGL()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glOrtho(-10.0, 10, -10.0, 10, -1.0, 1.0);
}
void drawCoordinate()
{
   glColor3f(1.0, 0.0, 0.0); // red x
   glBegin(GL_LINES);
   // x aix

   glVertex3f(-10.0, 0.0f, 0.0f);
   glVertex3f(10.0, 0.0f, 0.0f);
   glEnd();
   glFlush();

   // y
   glColor3f(0.0, 1.0, 0.0); // green y
   glBegin(GL_LINES);
   glVertex3f(0.0, -10.0f, 0.0f);
   glVertex3f(0.0, 10.0f, 0.0f);
   glEnd();
   glFlush();

   // z
   glColor3f(0.0, 0.0, 1.0); // blue z
   glBegin(GL_LINES);
   glVertex3f(0.0, 0.0f, -4.0f);
   glVertex3f(0.0, 0.0f, 4.0f);
   glEnd();
   glFlush();
}
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   drawCoordinate();

   glBegin(GL_LINES);
   glColor3f(1.0, 0.0, 0.0);
   glVertex3f(1, 2, 0.0);
   glVertex3f(7, 14, 0.0);
   glEnd();
   glFlush();
}
void displayTranslation()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   drawCoordinate();
   glTranslatef(5, 0, 0.0);
   glBegin(GL_LINES);
   glColor3f(1.0, 0.0, 0.0);
   glVertex3f(7, 14, 0.0);
   glVertex3f(1, 2, 0.0);
   glEnd();
   glPopMatrix();

   glFlush();
}
void displayRotate()
{
   glClear(GL_COLOR_BUFFER_BIT);
   drawCoordinate();
   glPushMatrix();

   glRotatef(30, 0.0, 1, 0);
   glBegin(GL_LINES);
   // glColor3f(1.0, 0.0, 0.0);
   glVertex3f(1, 2, 0.0);
   glVertex3f(7, 14, 0.0);
   glEnd();
   glPopMatrix();
   glFlush();
}
void displayRefl()
{
   glClear(GL_COLOR_BUFFER_BIT);
   drawCoordinate();
   glPushMatrix();

   glScalef(1, -1, 1);
   glBegin(GL_LINES);
   glColor3f(1.0, 0.0, 0.0);
   glVertex3f(1, 2, 0.0);
   glVertex3f(7, 14, 0.0);
   glEnd();
   glPopMatrix();
   glFlush();
}
void displayRotateMN(float xM, float yM, float xN, float yN)
{
   glClear(GL_COLOR_BUFFER_BIT);
   drawCoordinate();
   float angle = atan(fabs(yM - yN) / fabs(xM - xN)) * 180 / 3.14;
   glPushMatrix();

   glTranslatef(xM, yM, 0);
   glRotatef(30, 0, 0, 0);
   glRotatef(angle, 0, 0, 1);
   glTranslatef(-xM, -yN, 0);
   glBegin(GL_LINES);
   glColor3f(1.0, 0.0, 0.0);
   glVertex3f(1, 2, 0.0);
   glVertex3f(7, 14, 0.0);
   glEnd();
   glPopMatrix();
   glFlush();
}
void displayReflMN(float xM, float yM, float xN, float yN)
{
   glClear(GL_COLOR_BUFFER_BIT);
   float angle = atan(fabs(yM - yN) / fabs(xM - xN)) * 180 / 3.14;
   drawCoordinate();
   glPushMatrix();
   glTranslatef(xM, yM, 0);
   glScalef(-1, 1, 1);
   glRotatef(angle, 0, 0, 1);
   glTranslatef(-xM, -yN, 0);
   glBegin(GL_LINES);
   glColor3f(1.0, 0.0, 0.0);
   glVertex3f(1, 2, 0.0);
   glVertex3f(7, 14, 0.0);
   glEnd();
   glPopMatrix();
   glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 27:

   case 't':
   case 'T':
      displayTranslation();
      break;
   case 'r':
   case 'R':
      displayRotate();
      break;
   case 'p':
   case 'P':
      displayRefl();
      break;
   case 'f':
   case 'F':
      displayReflMN(1, 1, 4, 4);
      break;
   case 'h':
   case 'H':
      displayRotateMN(1, 1, 4, 4);
      break;
   case 'q':
      exit(0);
      break;
   }
}
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutCreateWindow("Lab");
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(50, 50);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   initGL();
   glutMainLoop();
   return 0;
}
