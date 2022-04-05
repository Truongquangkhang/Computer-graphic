#include<iostream>

#include<math.h>

#include<GL/glut.h>

using namespace std;

 

typedef float Matrix4 [4][4];

 

Matrix4 theMatrix;

//static GLfloat input[8][3]=

//{

//    {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},

//    {30,30,0},{80,30,0},{80,80,0},{30,80,0}

//

//};

 

static GLfloat input[8][3] ;

float output[8][3];

float tx,ty,tz;

float sx,sy,sz;

float angle;

float Iz; //toa do cua tam chieu nam tren truc OZ

int choice,choiceRot;

 

void inputSquare(){

    float size ;

    cout<<"Enter the length of the cube:"; cin>>size;

    float insertArr [8][3] =

    {

    {0,0,size},{size,0,size},{size,size,size},{0,size,size},

    {0,0,0},{size,0,0},{size,size,0},{0,size,0}

 

    };

   

    for(int i=0;i<8;i++)

    {

        for(int j=0;j<3;j++)

        {

          if(j==2) input[i][j] = insertArr[i][j] + 60;

          else input[i][j] = insertArr[i][j] ;

           

        }

    }

}

 

void printSquare(float a[8][3]){

    cout<<"==========================\n";

    for(int i=0;i<8;i++)

    {

        for(int j=0;j<3;j++)

        {

            cout<<a[i][j] << "\t";

        }

        cout<<"\n";

    }

    cout<<"==========================\n";

}

 

void setIdentityM(Matrix4 m)

{

    for(int i=0;i<4;i++)

    for(int j=0;j<4;j++)   m[i][j]=(i==j);

}

 

void perspective(float Iz){

//  float perArr [8][3] =

//  {

//        {0,0,size},{size,0,size},{size,size,size},{0,size,size},

//        {0,0,0},{size,0,0},{size,size,0},{0,size,0}

//

//  };

 

    float r = -1/Iz;

    for(int i=0;i<8;i++){

          for(int j=0;j<3;j++){

                if(j==2)    output[i][j] = 0;

                else        output[i][j] = input[i][j]/(r+1);

          }

    }

}

 

void scale(int sx,int sy,int sz)

{

    theMatrix[0][0]=sx;

    theMatrix[1][1]=sy;

    theMatrix[2][2]=sz;

}

 

void RotateX(float angle) //Parallel to x

{

 angle = angle*3.142/180;

 theMatrix[1][1] = cos(angle);

 theMatrix[1][2] = -sin(angle);

 theMatrix[2][1] = sin(angle);

 theMatrix[2][2] = cos(angle);

}

 

void RotateY(float angle) //parallel to y

{

 angle = angle*3.14/180;

 theMatrix[0][0] = cos(angle);

 theMatrix[0][2] = -sin(angle);

 theMatrix[2][0] = sin(angle);

 theMatrix[2][2] = cos(angle);

}

 

void RotateZ(float angle) //parallel to z

{

 angle = angle*3.14/180;

 theMatrix[0][0] = cos(angle);

 theMatrix[0][1] = sin(angle);

 theMatrix[1][0] = -sin(angle);

 theMatrix[1][1] = cos(angle);

}

 

void multiplyM()

{

//We Don't require 4th row and column in scaling and rotation

//[8][3]=[8][3]*[3][3] //4th not used

for(int i=0;i<8;i++)

{

    for(int j=0;j<3;j++)

    {

        output[i][j]=0;

        for(int k=0;k<3;k++) output[i][j]=output[i][j]+input[i][k]*theMatrix[k][j];

    }

}

 

}

void Axes(void)

{

  glBegin(GL_LINES);

  glColor3f(1.0, 0.0, 0.0);

  glVertex3f(-1000.0, 0.0, 0.0);

  glVertex3f(1000.0, 0.0, 0.0);

  glEnd();

 

  glBegin(GL_LINES);

  glColor3f(0.0, 1.0, 0.0);

  glVertex3f(0.0, -1000.0, 0.0);

  glVertex3f(0.0, 1000.0, 0.0);

  glEnd();

 

  glBegin(GL_LINES);

  glColor3f(0.0, 0.0, 1.0);

  glVertex3f(0.0, 0.0, -5000.0);

  glVertex3f(0.0, 0.0, 5000.0);

  glEnd();

}

 

void drawInput(float a[8][3])

{

    glBegin(GL_QUADS);

    glColor3f(0.7,0.4,0.5); //behind

    glVertex3fv(a[0]);

    glVertex3fv(a[1]);

    glVertex3fv(a[2]);

    glVertex3fv(a[3]);

 

   glColor3f(0.8,0.2,0.4);  //bottom

   glVertex3fv(a[0]);

   glVertex3fv(a[1]);

   glVertex3fv(a[5]);

   glVertex3fv(a[4]);

 

   glColor3f(0.3,0.6,0.7); //left

   glVertex3fv(a[0]);

   glVertex3fv(a[4]);

   glVertex3fv(a[7]);

   glVertex3fv(a[3]);

 

  glColor3f(0.2,0.8,0.2);  //right

  glVertex3fv(a[1]);

  glVertex3fv(a[2]);

  glVertex3fv(a[6]);

  glVertex3fv(a[5]);

 

 glColor3f(0.7,0.7,0.2); //up

 glVertex3fv(a[2]);

 glVertex3fv(a[3]);

 glVertex3fv(a[7]);

 glVertex3fv(a[6]);

 

 glColor3f(1.0,0.1,0.1);

 glVertex3fv(a[4]);

 glVertex3fv(a[5]);

 glVertex3fv(a[6]);

 glVertex3fv(a[7]);

 

glEnd();

 

}

 

void drawOutput(float a[8][3])

{

    glBegin(GL_QUADS);

    glColor3f(0.0, 0.0, 1.0); //behind

    glVertex3fv(a[0]);

    glVertex3fv(a[1]);

    glVertex3fv(a[2]);

    glVertex3fv(a[3]);

 

   glColor3f(0.0, 0.0, -1.0);  //bottom

   glVertex3fv(a[0]);

   glVertex3fv(a[1]);

   glVertex3fv(a[5]);

   glVertex3fv(a[4]);

 

   glColor3f(0.0, 1.0, 0.0);//left

   glVertex3fv(a[0]);

   glVertex3fv(a[4]);

   glVertex3fv(a[7]);

   glVertex3fv(a[3]);

 

  glColor3f(0.0, -1.0, 0.0);  //right

  glVertex3fv(a[1]);

  glVertex3fv(a[2]);

  glVertex3fv(a[6]);

  glVertex3fv(a[5]);

 

 glColor3f(1.0, 0.0, 0.0);//up

 glVertex3fv(a[2]);

 glVertex3fv(a[3]);

 glVertex3fv(a[7]);

 glVertex3fv(a[6]);

 

 glColor3f(-1.0, 0.0, 0.0);

 glVertex3fv(a[4]);

 glVertex3fv(a[5]);

 glVertex3fv(a[6]);

 glVertex3fv(a[7]);

 

 glEnd();

 

}

 

void init()

{

    glClearColor(1.0,1.0,1.0,1.0); //set backgrond color to white

    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);

    // Set the no. of Co-ordinates along X & Y axes and their gappings

    glEnable(GL_DEPTH_TEST);

     // To Render the surfaces Properly according to their depths

}

 

void display()

{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    gluLookAt(3.0, 2.0, 25.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    Axes();

   

    drawInput(input);

    setIdentityM(theMatrix);

    switch(choice)

    {

          case 1:

                perspective(Iz);

                break;

          case 2:

          scale(sx,sy,sz);

                multiplyM();

               

          break;

          case 3:

          switch (choiceRot) {

                case 1:

                            RotateX(angle);

                      break;

                case 2:

                            RotateY(angle);

                      break;

                case 3:

                      RotateZ(angle);

                      break;

                default:

                      break;

               

          }

                multiplyM();

          break;

         

    }

    cout<<"================\n";

    cout<<"matrix later\n";

    printSquare(output);

    drawOutput(output);

 

    glFlush();

}

 

int main(int argc, char** argv)

{

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(1362,750);

    glutInitWindowPosition(0,0);

    glutCreateWindow("3D TRANSFORMATIONS");

  

  

    inputSquare();

    cout<<"================\n";

    cout<<"original matrix\n";

    printSquare(input);

    init();

    cout<<"Enter your choice number:\n1.Perspective\n2.Scaling\n3.Rotation\n=>";

    cin>>choice;

    switch (choice) {

   case 1:

          cout<<"\nEnter Iz(coordinate center of projection on the axis Oz): ";

        cin>>Iz;

        break;

    case 2:

        cout<<"\nEnter Sx,Sy & Sz: \n";

        cin>>sx>>sy>>sz;

        break;

    case 3:

        cout<<"Enter your choice for Rotation about axis:\n1.parallel to X-axis."

             <<"(y& z)\n2.parallel to Y-axis.(x& z)\n3.parallel to Z-axis."

              <<"(x& y)\n =>";

        cin>>choiceRot;

        switch (choiceRot) {

        case 1:

            cout<<"\nENter Rotation angle: ";

            cin>>angle;

            break;

        case 2:

            cout<<"\nENter Rotation angle: ";

            cin>>angle;

            break;

        case 3:

            cout<<"\nENter Rotation angle: ";

            cin>>angle;

            break;

        default:

            break;

        }

        break;

   

    default:

        break;

    }

    glutDisplayFunc(display);

    glutMainLoop();

   

return 0;

}//end
