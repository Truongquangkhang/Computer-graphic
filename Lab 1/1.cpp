#include <GL/glut.h>

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);    
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   
   glBegin(GL_QUADS);              

   glEnd();
 
   glBegin(GL_TRIANGLES);          
	  glColor3f(1.0, 0.0, 0.0);
	  glVertex3f(0.5, 0.75, 0.0);
	  glVertex3f(0.9, 0.5, 0.0);
	  glVertex3f(0.1, 0.5, 0.0);
   glEnd();
 
   glBegin(GL_POLYGON);            
      glColor3f(1.0f, 1.0f, 0.0f); 
      glVertex3f (0.25, 0.0, 0.0);  
      glVertex3f (0.75, 0.0, 0.0);        
      glVertex3f (0.75, 0.5, 0.0);        
      glVertex3f (0.25, 0.5, 0.0);
   glEnd();
 
   glBegin(GL_POLYGON);
   	  glColor3f(0.0, 0.0, 1.0);
   	  glVertex3f(0.4, 0, 0.0);
   	  glVertex3f(0.4, 0.3, 0.0);
   	  glVertex3f(0.6, 0.3, 0.0);
   	  glVertex3f(0.6, 0, 0.0);
   glEnd();  
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


