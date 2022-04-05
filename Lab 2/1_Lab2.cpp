//#include <GL/gl.h>
//
//#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <iomanip>
using std::fixed;
using std::setprecision;
using std::setw;
#include <stdio.h>

void printmatrix(GLdouble thematrix[16])
{
  int i, j;
  for (i = 0; i < 4; ++i)
  {
    for (j = 0; j < 4; ++j)
    {
      cout << fixed << setprecision(4) << setw(7) << thematrix[j * 4 + i] << " ";
    }
    cout << endl;
  }
}

void printCurrentModelViewMatrix()
{
  GLdouble matrixd[16];
  glGetDoublev(GL_MODELVIEW_MATRIX, matrixd);
  printmatrix(matrixd);
}

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
}

void display(void)
{
  printf("Print the current modelview matrix\n");
  printCurrentModelViewMatrix();
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glLoadIdentity();

  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glScalef(1.0, 2.0, 1.0);
  glutWireCube(1.0);
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(display);

  glViewport(0, 0, (GLsizei)500, (GLsizei)500);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);

  glutMainLoop();
  return 0;
}
