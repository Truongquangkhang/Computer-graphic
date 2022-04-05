#include<gl/glut.h>
#include<gl/gl.h>
#include<stdio.h>
void myDisplay(void)
{
       glClear(GL_COLOR_BUFFER_BIT);
       glutSwapBuffers();
       glFlush();
}
void myMouse(int b, int s, int x, int y)
{
       switch (b)
       {
              case GLUT_LEFT_BUTTON:
                     if (s==GLUT_DOWN) printf("\nLeft button pressed!");
                     else if (s==GLUT_UP)printf("\nLeft button released!");
                     break;
              case GLUT_RIGHT_BUTTON:
                     if (s==GLUT_DOWN)printf("\nRight button pressed!");
                     else if (s==GLUT_UP) printf("\nRight button released");
                     break;
              default: break;
       }
}
void myKeyboard(unsigned char c, int x, int y)
{
       switch (c)
       {
              case 27:
                     exit(0);
                     break;
              default:
                     printf("\nKey %c is hit",c);
                     break;
       }
}
void main(int argc, char **argv)
{
       glutInit(&argc, argv);
       glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
       glutInitWindowPosition(300,200);
       glutInitWindowSize(320,320);
       glutCreateWindow("Vi du 1.2");
       glutDisplayFunc(myDisplay);
       glutMouseFunc(myMouse);
       glutKeyboardFunc(myKeyboard);
       glutMainLoop();
}
