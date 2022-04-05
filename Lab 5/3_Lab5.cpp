#include <iostream>

#include <stdlib.h>

#include<iomanip>

#include <stdlib.h>

#include <windows.h>

#include <GL/glut.h>

#include<math.h> 

using namespace std;

 

const int VERTEX = 8;

const float _angle = 13.0f;

GLfloat V[VERTEX][3];

 

//Initializes 3D rendering

void initRendering()

{

    glEnable(GL_DEPTH_TEST);

 

}

 

 

void Square(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[]){

    glBegin(GL_POLYGON);

    glVertex3fv(A);

    glVertex3fv(B);

    glVertex3fv(C);

    glVertex3fv(D);

    glEnd();

}

 

void Cube(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[],GLfloat V5[],GLfloat V6[],GLfloat V7[]) {

    //front

    glColor3f(1,0,0);

    Square(V0,V1,V2,V3);

   

    //back

    glColor3f(0,1,1);

    Square(V4,V5,V6,V7);

   

    //left

    glColor3f(0,1,0);

    Square(V0,V4,V7,V3);

   

    //right

    glColor3f(0,0,1);

    Square(V1,V5,V6,V2);

   

    //down

    glColor3f(1,1,0);

    Square(V3,V2,V7,V6);

   

    //top

    glColor3f(1,1,1);

    Square(V0,V1,V5,V4);

}

 

//print coordinate of vertexs of cube

void printVertexCoodinates (GLfloat V[][3]) {

    for (int i = 0; i <VERTEX ; i++){

          cout<<"Vertex "<<i+1<<": ";

          for (int j = 0; j <3; j ++){

                cout<<setprecision(2)<<setw(10)<<V[i][j] ;

          }

          cout<<endl;

    }

    cout<<endl;

}

 

//void printTransformMatrix

void printTransferMatrix(GLfloat matrix[4][4]) {

    cout<<"Transfer matrix:"<<endl;

    for (int i = 0; i <4 ; i++){

    cout<<"|";

    for (int j = 0; j <4; j ++){

          cout<<setprecision(2)<<setw(5)<<matrix[i][j] ;

    }

    cout<<"|"<<endl;

    }

}

 

// multiply transfer matrix with vecto

void matrixMultiply(GLfloat mat1[4][4], GLfloat input[3], GLfloat res[3])

{

    GLfloat prepareMatrix[4] = {input[0],input[1],input[2],1};

    GLfloat resultMatrix[4];

    GLfloat sum = 0;

    for (int row = 0 ; row < 4; row++) {

          for (int col = 0 ; col <4 ; col++) {

                sum += mat1[row][col] * prepareMatrix[col];

          }

          resultMatrix[row] = sum;

          sum =0;

    }

   

    for (int i = 0; i< 3; i ++){

          res[i] = resultMatrix[i]/resultMatrix[3];

    }

}

 

//orthographic projection

void orthoTransferMatrix(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar, GLfloat V[][3]) {

    GLfloat tx = - (right+left)/(right -left);

    GLfloat ty = - (top+bottom)/(top-bottom);

    GLfloat tz = - (zFar+zNear)/(zFar-zNear);

    GLfloat transferMatrix[4][4] = {

                                                    {2/(right-left), 0,0,tx},

                                                    {0, 2/(top-bottom),0,ty},

                                                    {0, 0,-2/(zFar-zNear),tz},

                                                    {0, 0,0,1},

                                                    };

 

    //print transfer matrix

    printTransferMatrix(transferMatrix);

   

    // Declare matrix to save all vertex after handle

     GLfloat vertex[VERTEX][3];

     

     //multiply all coodinates of vertex of cube with transferMatrix

     for(int row =0 ;row < VERTEX ; row ++) {

          matrixMultiply(transferMatrix, V[row],vertex[row]);

     }

 

     // draw cube after handle projection

     Cube(vertex[0],vertex[1],vertex[2],vertex[3],vertex[4],vertex[5],vertex[6], vertex[7]);

}

 

// calculate cotan

float cot( float alpha) {

    return cos(alpha)/sin(alpha);

}

 

// oblique projection

void obliqueTransferMatrix(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar,float theta, float phi, GLfloat V[][3]) {

    GLfloat tx = - (right+left)/(right -left);

    GLfloat ty = - (top+bottom)/(top-bottom);

    GLfloat tz = - (zFar+zNear)/(zFar-zNear);

    GLfloat transferMatrix[4][4] = {

                                                    {2/(right-left), 0,-2*cot(theta)/(right-left),tx},

                                                    {0, 2/(top-bottom),-2*cot(phi)/(top-bottom),ty},

                                                    {0, 0,0,0},

                                                    {0, 0,0,1},

                                                    };

   

    //print transfer matrix

    printTransferMatrix(transferMatrix);

   

    // Declare matrix to save all vertex after handle

     GLfloat vertex[VERTEX][3];

     

     //multiply all coodinates of vertex of cube with transferMatrix

     for(int row =0 ;row < VERTEX ; row ++) {

          matrixMultiply(transferMatrix, V[row],vertex[row]);

     }

 

     // draw cube after handle projection

     Cube(vertex[0],vertex[1],vertex[2],vertex[3],vertex[4],vertex[5],vertex[6], vertex[7]);

}

 

 

void drawOrthoGraphic()

{  

    GLfloat left,right,top,bottom,zNear,zFar;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode(GL_MODELVIEW);

    cout<<"left !=right, bottom !=top, zNear!= zFar"<<endl;

    cout<<"left: "; cin>>left;

    cout<<"right: "; cin>>right;

    cout<<"bottom: "; cin>>bottom;

    cout<<"top: "; cin>>top;

    cout<<"zNear: "; cin>>zNear;

    cout<<"zFar: "; cin>>zFar;

//  orthoTransferMatrix(-1,2,-1,3,1,-1,V);

    orthoTransferMatrix(left,right,bottom,top,zNear,zFar,V);

    glutSwapBuffers();

}

 

void drawOblique()

{  

    GLfloat left,right,top,bottom,zNear,zFar,theta,phi;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode(GL_MODELVIEW);

    cout<<"left !=right, bottom !=top, zNear!= zFar, 0<= theta|phi <= 90"<<endl;

    cout<<"left: "; cin>>left;

    cout<<"right: "; cin>>right;

    cout<<"bottom: "; cin>>bottom;

    cout<<"top: "; cin>>top;

    cout<<"zNear: "; cin>>zNear;

    cout<<"zFar: "; cin>>zFar;

    cout<<"theta:"; cin>>theta;

    cout<<"phi: ";cin>>phi;

    obliqueTransferMatrix(left,right,bottom,top,zNear,zFar,theta,phi,V);

    glutSwapBuffers();

}

 

void setCubeCoodinate( GLfloat V[VERTEX][3]){

    GLfloat a;

    cout<<"Type a:";

    cin>>a;

 

    V[0][0] = -a/2; V[0][1] = a/2; V[0][2] = a/2;

    V[1][0] = a/2; V[1][1] = a/2; V[1][2] = a/2;

    V[2][0] = a/2; V[2][1] = -a/2; V[2][2] = a/2;

    V[3][0] = -a/2; V[3][1] = -a/2; V[3][2] = a/2;

    V[4][0] = -a/2; V[4][1] = a/2; V[4][2] = -a/2;

    V[5][0] = a/2; V[5][1] = a/2; V[5][2] = -a/2;

    V[6][0] = a/2; V[6][1] = -a/2; V[6][2] = -a/2;

    V[7][0] = -a/2; V[7][1] = -a/2; V[7][2] = -a/2;

   

    cout<<"Coodinate of cube:"<<endl;

    printVertexCoodinates(V);

}

 

int main(int argc, char **argv)

{

    //Initialize GLUT

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

    glutInitWindowSize(400, 400);

 

 

    //Create the window

    glutCreateWindow("Cube");

    initRendering();

   

    setCubeCoodinate(V);

   

    int options=1;

    while(options) {

          cout<<"Choose mode(1-orthoGraphic, 2-oblique, 0-exit):"<<endl;

          cin>>options;

          if (options == 1) {

                cout<<"Drawing orthographic projection"<<endl;

                glutDisplayFunc(drawOrthoGraphic);

                glutMainLoop();

          }

          if (options ==2) {

                cout<<"Drawing oblique projection"<<endl;

                glutDisplayFunc(drawOblique);

                glutMainLoop();

          }

    }

 

//Set handler functions

//    glutDisplayFunc(drawScene);

//    glutMainLoop();

    return 0;

}//end
