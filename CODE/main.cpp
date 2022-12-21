
//Project Description:
//Features:
//1.	Falling Sun
//2.	Raising Moon
//3.	Running Cloud
//4.	Day
//5.	Night
//6.	Hill View
//7.	River View
//8.	Building
//9.	Tree
//10.	Grass
//11.	Moving Boat
//12.	Rotating Windmill
//13.	Moving Car, Truck (with speed controlled by keyboard)
//14.	Road
//15.	Bridge


#include <cstdio>
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
#include <unistd.h>
#include<cmath>

# define PI   3.14159265358979323846
using namespace std;

void myDisplay();
int start_flag=0;


const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_8_BY_13;


void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void night(int value);
GLfloat angle = 0.0f;
GLfloat truckPosition = 0.0f;
GLfloat truckSpeed = 0.05f;

void updateTruck(int value)
{
    if(truckPosition > 1.8)
    {
        truckPosition = -1.2f;
    }
    truckPosition += truckSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateTruck, 0);
}

GLfloat carPosition = 0.0f;
GLfloat carSpeed = 0.05f;
void updateCar(int value)
{
    if(carPosition < - 1.5)
    {
        carPosition = 1.2f;
    }
    carPosition -= carSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateCar, 0);
}

GLfloat boatPosition = 0.0f;
GLfloat boatSpeed = 0.005f;

GLfloat cloudPosition = 0.0f;
GLfloat cloudSpeed = 0.005f;

GLfloat cloud1Position = 0.0f;
GLfloat cloud1Speed = 0.007f;

GLfloat moonPosition = 0.0f;
GLfloat moonSpeed = 0.00009f;


void updateFan(int value)
{
    angle += 30.1f;

	glutPostRedisplay();

	glutTimerFunc(1, updateFan, 0);

}


void circleSolid(float x, float y, float radius)
{
	int triangleAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		}
    glEnd();
}

GLfloat sunPosition = 0.0f;
GLfloat sunSpeed = 0.006f;
void updateMoon(int value);

void updateSun(int value)
{
    if(sunPosition < -.9)
        {
            sunPosition = -.9;
            //isItNight = true;
        }

    sunPosition -= sunSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateSun, 0);
}


void updateMoon(int value)
{
    moonPosition += moonSpeed;
    if(moonPosition > 0.8)
        {
            moonPosition = 0.8;
        }
        moonPosition += moonSpeed;

    glutPostRedisplay();

	glutTimerFunc(100, updateMoon, 0);
}


void updateBoat(int value) {

    if(boatPosition > .40)
        {
            boatPosition = -1.0;
        }
    boatPosition += boatSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, updateBoat, 0);
}

void updateCloud(int value)
{
    if(cloudPosition > 0.9)
        {
            cloudPosition = -1.4;
        }
    cloudPosition += cloudSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, updateCloud, 0);
}


void updateCloud1(int value)
{
    if(cloud1Position > 1.3)
        {
            cloud1Position = -1.4;
        }

    cloud1Position += cloudSpeed;

	glutPostRedisplay();

	glutTimerFunc(100, updateCloud1, 0);
}

void windmilStick()
{
    //windmill stick  taha
    glColor3ub (255, 255 , 255);
    glBegin(GL_POLYGON);
    glVertex2f(0.52f, -0.3f);
    glVertex2f(0.51f, -1.0f);
    glVertex2f(0.55f, -1.0f);
    glVertex2f(0.54f, -0.3f);
    glEnd();
}


void windMills()  //// taha
{
    float x1,y1,x2,y2;
    float a;
    double radius=0.027;

    x1=0.53, y1= -0.30;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255,255,255);
    for (a = 1.0f ; a < 360.0f;a += 0.2)
    {
        x2 = x1+sin(a)*radius;
        y2 = y1+cos(a)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();

    //angle+= 0.05;
}

void tree()
{
    //Tree
    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();
    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    //Tree
    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.0f, -0.3f);
    glVertex2f(-0.0f, -0.7f);
    glVertex2f(-0.08f, -0.7f);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.0f, -0.3f);
    glVertex2f(-0.0f, -0.7f);
    glVertex2f(0.08f, -0.7f);
    glEnd();
    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.02f, -0.7f);
    glVertex2f(-0.02f, -0.8f);
    glVertex2f(0.02f, -0.8f);
    glVertex2f(0.02f, -0.7f);
    glEnd();

    //Tree
    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, -0.32f);
    glVertex2f(0.2f, -0.65f);
    glVertex2f(0.13f, -0.65f);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, -0.32f);
    glVertex2f(0.2f, -0.65f);
    glVertex2f(0.27f, -0.65f);
    glEnd();
    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.18f, -0.65f);
    glVertex2f(0.18f, -0.77f);
    glVertex2f(0.22f, -0.77f);
    glVertex2f(0.22f, -0.65f);
    glEnd();

    //Tree
    glColor3ub (0, 102, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.19f, -0.1f);
    glVertex2f(-0.19f, -0.4f);
    glVertex2f(-0.22f, -0.4f);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.19f, -0.1f);
    glVertex2f(-0.19f, -0.4f);
    glVertex2f(-0.16f, -0.4f);
    glEnd();
    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.20f, -0.4f);
    glVertex2f(-0.20f, -0.45f);
    glVertex2f(-0.18f, -0.45f);
    glVertex2f(-0.18f, -0.4f);
    glEnd();

    //Tree
    glColor3ub (139, 0, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.39f, 0.1f);
    glVertex2f(-0.39f, -0.1f);
    glVertex2f(-0.41f, -0.1f);
    glEnd();
    glColor3ub (215, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.39f, 0.1f);
    glVertex2f(-0.39f, -0.1f);
    glVertex2f(-0.37f, -0.1f);
    glEnd();
    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.398f, -0.1f);
    glVertex2f(-0.398f, -0.13f);
    glVertex2f(-0.388f, -0.13f);
    glVertex2f(-0.388f, -0.1f);
    glEnd();

    //Tree
    glColor3ub (139, 0, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.37f, -0.2f);
    glEnd();
    glColor3ub (215, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.43f, -0.2f);
    glEnd();
    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.39f, -0.2f);
    glVertex2f(0.39f, -0.25f);
    glVertex2f(0.41f, -0.25f);
    glVertex2f(0.41f, -0.2f);
    glEnd();
}


void river ()
{
    glColor3ub(62,103,185);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(-0.8f, -0.1f);
    glVertex2f(-0.68f, -0.13f);
    glVertex2f(-0.3f, -0.13f);
    glVertex2f(-0.4f, -0.32f);
    glVertex2f(-0.19f, -0.49f);
    glVertex2f(-0.25f, -0.67f);
    glVertex2f(-0.04f, -0.79f);
    glVertex2f(0.016f, -0.86f);
    glVertex2f(0.019f, -0.90f);
    glVertex2f(0.021f, -0.905f);
    glVertex2f(0.02f, -0.91f);
    glVertex2f(0.025f, -0.915f);
    glVertex2f(0.023f, -0.920f);
    glVertex2f(0.025f, -0.925f);
    glVertex2f(0.027f, -1.0f);
    glVertex2f(-1.0, -1.0f);
    glEnd();
}


void hills()
{ ///////////////////////////////////////////////////////////////////////////////////////////////
    //Hills 1 left big 1st 2nd
    glColor3ub (139, 69, 19); /////139 69 19                0, 102, 0
    glBegin(GL_POLYGON);
    glVertex2f(-0.55f, 0.36f);
    glVertex2f(-0.8f, -0.1f);
    glVertex2f(-0.68f, -0.13f);
    glEnd();
    glColor3ub (205, 133, 63);      ///// 160 82 45   205 133 63           3, 182, 10
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.55f, 0.36f);
    glVertex2f(-0.68f, -0.13f);
    glVertex2f(-0.3f, -0.13f);
    glEnd();

    //Hills 2 must be kept middle big one for hiding ship
    glColor3ub (139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(-0.15f, 0.3f);
    glVertex2f(-0.4f, -0.32f);
    glVertex2f(-0.24f, -0.38f);
    glEnd();
    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.15f, 0.3f);
    glVertex2f(-0.24f, -0.38f);
    glVertex2f(0.1f, -0.38f);
    glEnd();

    //HILLS 3 left big must be kept
    glColor3ub (139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85f, 0.12f);
    glVertex2f(-1.0f, -0.25f);
    glVertex2f(-1.0f, -0.55f);
    glEnd();
    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.85f, 0.12f);
    glVertex2f(-1.0f, -0.55f);
    glVertex2f(-0.69f, -0.55f);
    glEnd();

    //Hills 4 back middle big- 2 hills
    glColor3ub (139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.25f, 0.28f);
    glVertex2f(-0.045f, -0.0f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.1f, -0.07f);
    glVertex2f(0.2f, -0.05f);
    glEnd();

    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.15f, 0.3f);
    glVertex2f(-0.24f, -0.38f);
    glVertex2f(0.1f, -0.38f);
    glEnd();
    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.25f, 0.28f);
    glVertex2f(0.2f, -0.05f);
    glVertex2f(0.38f, -0.05f);
    glEnd();

    //Hills 5
    glColor3ub (139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.11f, 0.03f);
    glVertex2f(-0.12f, -0.4f);
    glVertex2f(-0.0f, -0.45f);
    glEnd();
    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.11f, 0.03f);
    glVertex2f(0.0f, -0.45f);
    glVertex2f(0.28f, -0.45f);
    glEnd();

    //Hills 6
    glColor3ub (0, 102, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.31f, -0.13f);
    glVertex2f(-0.0f, -0.55f);
    glVertex2f(0.18f, -0.57f);
    glEnd();
    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.31f, -0.13f);
    glVertex2f(0.18f, -0.57f);
    glVertex2f(0.4f, -0.57f);
    glEnd();


}



void sun()
{
    glPushMatrix();
    glTranslatef(0.0f,sunPosition, 0.0f);

    float x1,y1,x2,y2;
    float a;
    double radius=0.1;

    x1=-0.8, y1= 0.7;

    glBegin(GL_TRIANGLE_FAN); ///////////////////////////////////////////////////////////////////////////
    glColor3f(239,255,0);
    for (a = 0.0f ; a < 360.0f ; a+=0.2)
        {
            x2 = x1+sin(a)*radius;
            y2 = y1+cos(a)*radius;
            glVertex2f(x2,y2);
        }

       glEnd();

    glPopMatrix();
}


void moon()
{
    glPushMatrix();
    glTranslatef(0.0f,moonPosition, 0.0f);
    float x1,y1,x2,y2;
    float a;
    double radius=0.08;

    x1=-0.8, y1= -0.5;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(255,255,255);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x2 = x1+sin(a)*radius;
            y2 = y1+cos(a)*radius;
            glVertex2f(x2,y2);
        }

        glEnd();

    glPopMatrix();
}

void clouds1()
{
    glPushMatrix();
    glTranslatef(cloud1Position,0.0f, 0.0f);
    float x1,y1,x2,y2;
    float x3,y3,x4,y4;
    float x5,y5,x6,y6;
    float x7,y7,x8,y8;
    float x9,y9,x0,y0;
    float x11,y11,x12,y12;
    float x13,y13,x14,y14;
    float a;
    double radius=0.07;

    x1=-0.4, y1= 0.65;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x2 = x1+sin(a)*radius;
            y2 = y1+cos(a)*radius;
            glVertex2f(x2,y2);
        }
        glEnd();

    x3=-0.35, y3= 0.56;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x4 = x3+sin(a)*radius;
            y4 = y3+cos(a)*radius;
            glVertex2f(x4,y4);
        }
        glEnd();

    x5=-0.35, y5= 0.7;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x6 = x5+sin(a)*radius;
            y6 = y5+cos(a)*radius;
            glVertex2f(x6,y6);
        }
        glEnd();

    x7=-0.26, y7= 0.56;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x8 = x7+sin(a)*radius;
            y8 = y7+cos(a)*radius;
            glVertex2f(x8,y8);
        }
        glEnd();

    x9=-0.26, y9= 0.7;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x0 = x9+sin(a)*radius;
            y0 = y9+cos(a)*radius;
            glVertex2f(x0,y0);
        }
        glEnd();

    x11=-0.18, y11= 0.63;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x12 = x11+sin(a)*radius;
            y12 = y11+cos(a)*radius;
            glVertex2f(x12,y12);
        }
        glEnd();

    x13=-0.3, y13= 0.63;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x14 = x13+sin(a)*radius;
            y14 = y13+cos(a)*radius;
            glVertex2f(x14,y14);
        }
        glEnd();

    glPopMatrix();
}

void clouds2()
{
    glPushMatrix();
    glTranslatef(cloudPosition,0.0f, 0.0f);
    float x1,y1,x2,y2;
    float x3,y3,x4,y4;
    float x5,y5,x6,y6;
    float x7,y7,x8,y8;
    float x9,y9,x0,y0;
    float x11,y11,x12,y12;
    float x13,y13,x14,y14;
    float a;
    double radius=0.07;

    x1=0.5, y1= 0.65;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x2 = x1+sin(a)*radius;
            y2 = y1+cos(a)*radius;
            glVertex2f(x2,y2);
        }
        glEnd();

    x3=0.45, y3= 0.56;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x4 = x3+sin(a)*radius;
            y4 = y3+cos(a)*radius;
            glVertex2f(x4,y4);
        }
        glEnd();

    x5=0.45, y5= 0.7;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x6 = x5+sin(a)*radius;
            y6 = y5+cos(a)*radius;
            glVertex2f(x6,y6);
        }
        glEnd();

    x7=0.36, y7= 0.56;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x8 = x7+sin(a)*radius;
            y8 = y7+cos(a)*radius;
            glVertex2f(x8,y8);
        }
        glEnd();

    x9=0.36, y9= 0.7;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x0 = x9+sin(a)*radius;
            y0 = y9+cos(a)*radius;
            glVertex2f(x0,y0);
        }
        glEnd();

       x11=0.28, y11= 0.63;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x12 = x11+sin(a)*radius;
            y12 = y11+cos(a)*radius;
            glVertex2f(x12,y12);
        }
        glEnd();

    x13=0.4, y13= 0.63;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,84);
    for (a=0.0f; a<360.0f; a+=0.2)
        {
            x14 = x13+sin(a)*radius;
            y14 = y13+cos(a)*radius;
            glVertex2f(x14,y14);
        }
        glEnd();

        glPopMatrix();
}
void sky(int value)
{
    glBegin(GL_POLYGON); //Sky
    glColor3f(0.4f, 0.5f, 1.0f);////
    glVertex2f(-1,1);
    glVertex2f(1, 1);
    glColor3f(0.7, 0.7, 1.0);
    glVertex2f(1, -.1);
    glVertex2f(-1, -.1);
    glEnd();

    glutPostRedisplay();
    glutTimerFunc(5, sky, 0);
}

void night(int value)
{
    glBegin(GL_POLYGON); //Sky
	glColor3ub(0, 0, 0); /////
	glVertex2f(-1,1);
	glVertex2f(1, 1);
	glColor3f(0.7, 0.7, 1.0);
	glVertex2f(1, -.1);
	glVertex2f(-1, -.1);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(0,58,0);
	glVertex2f(0.0f, 0.0f);
    glColor3ub(0,58,0);
    glVertex2f(-0.4f, -0.33f);
    glColor3ub(0,58,0);
    glVertex2f(-0.4f,-1.0);
    glVertex2f(1.0f,-1.0);
    glVertex2f(1.0f,0.05f);
	glEnd();

    glutPostRedisplay();
    glutTimerFunc(1000, updateMoon, 0);


/////////////////////////////////////////////////////

    //Tree
    glColor3ub (20,30, 40);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();
    glColor3ub (20, 30, 40);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();
    glColor3ub (20, 30, 40);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();

    glutPostRedisplay();
    glutTimerFunc(1000, updateMoon, 0);


////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////
void ship()
{
    //base
    glPushMatrix();
    glTranslatef(boatPosition,0.0f, 0.0f);
    glColor3ub(255,110,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.69f, -0.30f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.58f, -0.24f);
    glVertex2f(-0.73f, -0.24f);
    glEnd();

    //stick
    glColor3ub(160,82,35);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-0.65,-0.24);
    glVertex2f(-0.65,-0.1);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.655,-0.13);
    glVertex2f(-0.655,-0.24);
    glVertex2f(-0.71,-0.24);
    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.648,-0.08);
    glVertex2f(-0.648,-0.24);
    glVertex2f(-0.59,-0.24);
    glVertex2f(-0.59,-0.18);
    glVertex2f(-0.6,-0.19);
    glVertex2f(-0.61,-0.16);
    glVertex2f(-0.63,-0.12);
    glEnd();

    glPopMatrix();

    //Hill 2 for hiding the ship
    glColor3ub (139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(-0.15f, 0.3f);
    glVertex2f(-0.4f, -0.32f);
    glVertex2f(-0.24f, -0.38f);
    glEnd();

    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.15f, 0.3f);
    glVertex2f(-0.24f, -0.38f);
    glVertex2f(0.1f, -0.38f);
    glEnd();

    glColor3ub (139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.11f, 0.03f);
    glVertex2f(-0.12f, -0.4f);
    glVertex2f(-0.0f, -0.45f);
    glEnd();

    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.11f, 0.03f);
    glVertex2f(0.0f, -0.45f);
    glVertex2f(0.28f, -0.45f);
    glEnd();
     //middle tree
    glColor3ub (139, 0, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.19f, -0.1f);
    glVertex2f(-0.19f, -0.4f);
    glVertex2f(-0.22f, -0.4f);
    glEnd();

    glColor3ub (215, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.19f, -0.1f);
    glVertex2f(-0.19f, -0.4f);
    glVertex2f(-0.16f, -0.4f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.20f, -0.4f);
    glVertex2f(-0.20f, -0.45f);
    glVertex2f(-0.18f, -0.45f);
    glVertex2f(-0.18f, -0.4f);
    glEnd();

    //Hills 6
    glColor3ub (139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(0.31f, -0.13f);
    glVertex2f(-0.0f, -0.55f);
    glVertex2f(0.18f, -0.57f);
    glEnd();

    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.31f, -0.13f);
    glVertex2f(0.18f, -0.57f);
    glVertex2f(0.4f, -0.57f);
    glEnd();

    //Tree
    glColor3ub (139, 0, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.0f, -0.3f);
    glVertex2f(-0.0f, -0.7f);
    glVertex2f(-0.08f, -0.7f);
    glEnd();

    glColor3ub (215, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.0f, -0.3f);
    glVertex2f(-0.0f, -0.7f);
    glVertex2f(0.08f, -0.7f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.02f, -0.7f);
    glVertex2f(-0.02f, -0.8f);
    glVertex2f(0.02f, -0.8f);
    glVertex2f(0.02f, -0.7f);
    glEnd();

    //Tree
    glColor3ub (139, 0, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, -0.32f);
    glVertex2f(0.2f, -0.65f);
    glVertex2f(0.13f, -0.65f);
    glEnd();

    glColor3ub (215, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, -0.32f);
    glVertex2f(0.2f, -0.65f);
    glVertex2f(0.27f, -0.65f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.18f, -0.65f);
    glVertex2f(0.18f, -0.77f);
    glVertex2f(0.22f, -0.77f);
    glVertex2f(0.22f, -0.65f);
    glEnd();

    //HILLS 3
    glColor3ub (139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2f(-0.85f, 0.12f);
    glVertex2f(-1.0f, -0.25f);
    glVertex2f(-1.0f, -0.55f);
    glEnd();

    glColor3ub (205, 133, 63);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.85f, 0.12f);
    glVertex2f(-1.0f, -0.55f);
    glVertex2f(-0.69f, -0.55f);
    glEnd();

    //Tree
    glColor3ub (139, 0, 0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (215, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.85f, -0.7f);
    glVertex2f(-0.85f, -0.35f);
    glEnd();

    glColor3ub (102, 53, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.87f, -0.7f);
    glVertex2f(-0.87f, -0.8f);
    glVertex2f(-0.83f, -0.8f);
    glVertex2f(-0.83f, -0.7f);
    glEnd();
}


void grass1()
{
    glColor3ub(189, 183, 107); ///////////189 183 107     28,230,0      right
    glBegin(GL_POLYGON);
    glVertex2f(-0.69f, -0.55f);
    glVertex2f(-1.0f, -0.55f);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-0.57,-1.0);
    glVertex2f(-0.57,-0.72);
    glVertex2f(-0.55,-0.69);
    glVertex2f(-0.53,-0.67);
    glVertex2f(-0.51,-0.65);
    glVertex2f(-0.55,-0.63);
    glVertex2f(-0.59,-0.6);
    glEnd();
}

void road1()
{
    glColor3ub(32,32,32);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-0.57f, -1.0f);
    glVertex2f(-0.57f,-0.82);
    glVertex2f(-1.0f,-0.82);
    glEnd();

    glColor3ub(255,255,255);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-0.98,-0.91);
    glVertex2f(-0.92,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.85,-0.91);
    glVertex2f(-0.79,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.73,-0.91);
    glVertex2f(-0.67,-0.91);
    glEnd();
}
void grass2()
{
    glColor3ub(34,139,34); /////////////////////////////////// green back middle
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glColor3ub(50,205,50);
    glVertex2f(-0.4f, -0.33f);
    glColor3ub(189, 183, 107); /////////////////////////////////////// 28,230
    glVertex2f(-0.4f,-1.0);
    glVertex2f(1.0f,-1.0);
    glVertex2f(1.0f,0.05f);
    glEnd();
}

void road2()
{
    glColor3ub(32,32,32);
    glBegin(GL_POLYGON);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.82f);
    glVertex2f(-0.17f,-0.82f);
    glVertex2f(-0.17f,-1.0f);
    glEnd();

    glColor3ub(255,255,255);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(0.28,-0.91);
    glVertex2f(0.34,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.4,-0.91);
    glVertex2f(0.46,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.52,-0.91);
    glVertex2f(0.58,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.64,-0.91);
    glVertex2f(0.7,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.76,-0.91);
    glVertex2f(0.82,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.88,-0.91);
    glVertex2f(0.94,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.22,-0.91);
    glVertex2f(0.16,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.1,-0.91);
    glVertex2f(0.04,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.02,-0.91);
    glVertex2f(-0.08,-0.91);
    glEnd();
}

void bridge()
{
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.57f,-0.82);
    glVertex2f(-0.57f, -1.0f);
    glVertex2f(-0.17f,-1.0f);
    glVertex2f(-0.17f,-0.82f);
    glEnd();

    //some grass
    glColor3ub(189, 210, 107);/////////////////////////////////////triangle grass
    glBegin(GL_POLYGON);
    glVertex2f(-0.17f, -0.82f);
    glVertex2f(-0.0f, -0.82f);
    glVertex2f(-0.07f,-0.65f);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-0.54,-0.91);
    glVertex2f(-0.48,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.42,-0.91);
    glVertex2f(-0.36,-0.91);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.30,-0.91);
    glVertex2f(-0.24,-0.91);
    glEnd();
}


void hut()
{
    glBegin(GL_QUADS);//left first building 1st floor
      glColor3ub(87, 87, 87);
      glVertex2f(0.99f, 0.02f);
      glVertex2f( 1.20f, 0.02f);
      glVertex2f( 1.20f,  0.20f);
      glVertex2f(0.99f,  0.20f);
    glEnd();


    glBegin(GL_QUADS);//left first building 1st floor left window
      glColor3f(00.80f, 1.0f, 0.20f);
       glVertex2f(1.02f, 0.07f);
       glVertex2f(1.08f, 0.07f);
       glVertex2f(1.08f, 0.13f);
       glVertex2f(1.02f, 0.13f);
     glEnd();


     glBegin(GL_QUADS);//left first building 1st floor right window
        glColor3f(00.80f, 1.0f, 0.20f);
        glVertex2f(1.11f, 0.07f);
        glVertex2f(1.17f, 0.07f);
        glVertex2f(1.17f, 0.13f);
        glVertex2f(1.11f, 0.13f);

     glEnd();


    glBegin(GL_QUADS);//left first building 2nd floor
        glColor3ub(140, 140, 140);
        glVertex2f(0.99f,  0.20f);
        glVertex2f( 1.20f,  0.20f);
        glVertex2f( 1.20f,  0.40f);
        glVertex2f(0.99f,  0.40f);
    glEnd();


    glBegin(GL_QUADS);//left first building 2nd floor left window
      glColor3f(00.80f, 1.0f, 0.20f);
       glVertex2f(1.02f, 0.27f);
       glVertex2f(1.08f, 0.27f);
       glVertex2f(1.08f, 0.33f);
       glVertex2f(1.02f, 0.33f);
     glEnd();


     glBegin(GL_QUADS);//left first building 2nd floor right window
        glColor3f(00.80f, 1.0f, 0.20f);
        glVertex2f(1.11f, 0.27f);
        glVertex2f(1.17f, 0.27f);
        glVertex2f(1.17f, 0.33f);
        glVertex2f(1.11f, 0.33f);

     glEnd();


    glBegin(GL_QUADS);//left first building 3rd floor
        glColor3ub(153, 153, 153);
        glVertex2f(0.99f,  0.40f);
        glVertex2f( 1.20f,  0.40f);
        glVertex2f( 1.20f,  0.60f);
        glVertex2f(0.99f,  0.60f);
    glEnd();


    glBegin(GL_QUADS);//left first building 3rd floor left window
      glColor3f(00.80f, 1.0f, 0.20f);
       glVertex2f(1.02f, 0.47f);
       glVertex2f(1.08f, 0.47f);
       glVertex2f(1.08f, 0.53f);
       glVertex2f(1.02f, 0.53f);
     glEnd();


     glBegin(GL_QUADS);//left first building 3rd floor right window
        glColor3f(00.80f, 1.0f, 0.20f);
        glVertex2f(1.11f, 0.47f);
        glVertex2f(1.17f, 0.47f);
        glVertex2f(1.17f, 0.53f);
        glVertex2f(1.11f, 0.53f);

     glEnd();


}

void farm()
{
    glBegin(GL_QUADS);//farm house
      glColor3ub(139,136,120);
      glVertex2f( 0.46f, -0.40f);
      glVertex2f( 1.0f, -0.40f);
      glVertex2f( 1.0f,  -0.10f);
      glVertex2f( 0.46f,  -0.10f);
    glEnd();


  glBegin(GL_QUADS);//farm house upper part
      glColor3ub(1176,196,222);
      glVertex2f(0.46f, -0.10f);
      glVertex2f( 1.0f, -0.10f);
      glVertex2f( 0.92f, 0.0f);
      glVertex2f( 0.56f,  0.0f);
    glEnd();

    glBegin(GL_QUADS);//farm house left door
      glColor3f(0.80f, 1.0f, 0.80f);
      glVertex2f( 0.52f, -0.40f);
      glVertex2f( 0.59f, -0.40f);
      glVertex2f( 0.59f,  -0.24f);
      glVertex2f( 0.52f,  -0.24f);
    glEnd();

    glBegin(GL_QUADS);//farm house middle left door
      glColor3f(0.80f, 1.0f, 0.80f);
      glVertex2f( 0.64f, -0.40f);
      glVertex2f( 0.71f, -0.40f);
      glVertex2f( 0.71f,  -0.24f);
      glVertex2f( 0.64f,  -0.24f);
    glEnd();

     glBegin(GL_QUADS);//farm house middle right door
      glColor3f(0.80f, 1.0f, 0.80f);
      glVertex2f( 0.76f, -0.40f);
      glVertex2f( 0.83f, -0.40f);
      glVertex2f( 0.83f,  -0.24f);
      glVertex2f( 0.76f,  -0.24f);
    glEnd();

    glBegin(GL_QUADS);//farm house right door
      glColor3f(0.80f, 1.0f, 0.80f);
      glVertex2f( 0.88f, -0.40f);
      glVertex2f( 0.95f, -0.40f);
      glVertex2f( 0.95f,  -0.24f);
      glVertex2f( 0.88f,  -0.24f);
    glEnd();

}


void vehicle()//This is the truck
{

    glPushMatrix();
    glTranslatef(truckPosition,0.0f, 0.0f);

   //body
    glColor3ub(0,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.68f, -0.86f);
    glVertex2f(-0.68f,-0.67f);
    glVertex2f(-0.9f,-0.67f);
    glEnd();

    //base of the truck
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.9f);
    glVertex2f(-0.9f,-0.9f);
    glEnd();

    //front
    glColor3ub(240,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.67f,-0.86f);
    glVertex2f(-0.58f, -0.86f);
    glVertex2f(-0.58f,-0.79f);
    glVertex2f(-0.61f,-0.735f);
    glVertex2f(-0.67f,-0.735f);
    glEnd();

    //wheels
    glColor3ub(20,20,120);
    circleSolid(-0.84f,-0.88f,0.034);
    circleSolid(-0.64f,-0.88f,0.034);
    glColor3ub(130,130,130);
    circleSolid(-0.84f,-0.88f,0.02);
    circleSolid(-0.64f,-0.88f,0.02);

    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(-.59619,-0.815);
    glVertex2f(-0.61,-0.815);
    glEnd();

    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(-0.66,-0.797);
    glVertex2f(-0.596,-0.797);
    glVertex2f(-0.596,-0.781);
    glColor3ub(100,149,237);
    glVertex2f(-0.615,-0.747);
    glVertex2f(-0.66,-0.747);
    glEnd();
    glPopMatrix();

}

void hut2()

{
     glColor3ub(255,100,0);//big hut
    glBegin(GL_QUADS);
    glVertex2f(-.80,-0.72);
    glVertex2f(-0.68,-0.72);
    glVertex2f(-0.68,-0.50);
    glVertex2f(-0.80,-0.50);
    glEnd();


    glColor3ub(55,40,79);//big hut door
    glBegin(GL_QUADS);
    glVertex2f(-.76,-0.72);
    glVertex2f(-0.72,-0.72);
    glVertex2f(-0.72,-0.63);
    glVertex2f(-0.76,-0.63);
    glEnd();




    glColor3ub(255,50,0);//small hut
    glBegin(GL_QUADS);
    glVertex2f(-0.68,-0.72);
    glVertex2f(-0.62,-0.72);
    glVertex2f(-0.62,-0.30);
    glVertex2f(-0.68,-0.30);
    glEnd();


    glColor3ub(55,50,80);//small hut window
    glBegin(GL_QUADS);
    glVertex2f(-0.66,-0.44);
    glVertex2f(-0.64,-0.44);
    glVertex2f(-0.64,-0.39);
    glVertex2f(-0.66,-0.39);
    glEnd();


    glBegin(GL_TRIANGLES);// big hut roof
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.80f,-0.50f);
    glVertex2f(-0.68f,-0.50f);
    glVertex2f(-0.74f,-0.42f);
    glEnd();


    glBegin(GL_TRIANGLES);// small hut roof
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.68f,-0.30f);
    glVertex2f(-0.62f,-0.30f);
    glVertex2f(-0.65f,-0.25f);
    glEnd();


     glBegin(GL_TRIANGLES);// big hut roof
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.80f,-0.50f);
    glVertex2f(-0.68f,-0.50f);
    glVertex2f(-0.74f,-0.42f);


    glBegin(GL_TRIANGLES);// small hut roof
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2f(-0.68f,-0.30f);
    glVertex2f(-0.62f,-0.30f);
    glVertex2f(-0.65f,-0.25f);


    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 1.0f);
    glVertex2f(-0.65f, -0.27f);
    glVertex2f(-0.63f, -0.04f);
    glVertex2f(-0.67f, -0.04f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 1.0f);
    glVertex2f(-0.65f, -0.27f);
    glVertex2f(-0.81f, -0.30f);
    glVertex2f(-0.81f, -0.24f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 1.0f);
    glVertex2f(-0.65f, -0.27f);
    glVertex2f(-0.63f, -0.50f);
    glVertex2f(-0.67f, -0.50f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 1.0f);
    glVertex2f(-0.65f, -0.27f);
    glVertex2f(-0.49f, -0.30f);
    glVertex2f(-0.49f, -0.24f);
    glEnd();


}

void drawWindmill()
{
	int i;

	glTranslatef(0.53, -0.3, 0);
	glRotated(angle * (180.0/46), 0, 0, 1);
	glColor3f(255.0f, 255.0f, 255.0f);
	for (i = 0 ; i < 3 ; i++)
        {
            glRotated(120, 0, 0, 1);  // Note: These rotations accumulate.
            glBegin(GL_POLYGON);
            glVertex2f(0.035,0);
            glVertex2f(0.15f, -0.03f);
            glVertex2f(0.3f,0.0f);
            glVertex2f(0.15f, 0.03f);
            glEnd();
        }
}

void vehicle2()//This is the car
{
    glPushMatrix();
    glTranslatef(carPosition,0.0f, 0.0f);
    //body
    glColor3ub(255,255,0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();
    //wheels
    glColor3ub(233,0,0);
    circleSolid(0.07,-0.938,0.035);
    circleSolid(0.2,-0.938,0.035);
    //
    glColor3ub(0,0,0);
    glLineWidth(1.1);
    glBegin(GL_LINES);
    glVertex2f(0.141f,-0.758f);
    glVertex2f(0.141f,-0.842f);
    glEnd();
    //window
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();
    glColor3ub(153,206,250);
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();
    //door
    glColor3ub(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();
    glPopMatrix();
}

void fristDesign()
{


    glColor3ub(180, 20, 20);
    renderBitmapString(-.21, 0.4,(void *)font1,"Computer Graphics Project");

    glColor3ub(220, 220, 220);
    renderBitmapString(-.21, 0.26,(void *)font1,"Industrial View with wind mill");

    glColor3ub(0, 0, 0);
    renderBitmapString(-.15, 0.15,(void *)font1,"    Nusrat Jevin Nir (16-31222-1)");

    glColor3ub(0, 0, 0);
    renderBitmapString(-.15, 0.04,(void *)font1,"    Fatema Tuj Johura (18-37537-1)");

    glColor3ub(0, 0, 0);
    renderBitmapString(-.15, -0.07,(void *)font1,"    Niloy Md Bakhtiar Azim (19-41011-2)");

    glColor3ub(0, 0, 0);
    renderBitmapString(-.15, -0.18,(void *)font1,"    Rahemin Ahmed (20-43510-1)");

    glColor3ub(255, 179, 255);
    renderBitmapString(-.21, -0.29,(void *)font1,"Press SPACE to START");

}

void LastDesign()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1);
    //menu
    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
    glVertex2f(-.28,-.5);
    glVertex2f(.28,-0.5);
    glVertex2f(0.28,0.5);
    glVertex2f(-0.28,0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-.28,-.5);
    glVertex2f(0.28,0.5);
    glVertex2f(-0.38,0.15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-.28,-.5);
    glVertex2f(0.28,0.5);
    glVertex2f(0.38,0.05);
    glEnd();

    glColor3ub(20, 222, 100);
    renderBitmapString(-.11,0.06,(void *)font1,"Thank You !");
}


void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(2.0);
    if(start_flag ==0 )
        {
            fristDesign();
        }
    else if(start_flag == 1)
        {
            sky(1);

            if(sunPosition < -.75)
                {
                    night(1);
                }
            sun();

            moon();

            grass2();

            river();

            hills();

            grass1();

            road1();

            road2();

            clouds1();

            clouds2();

            hut();
            farm();

            bridge();
///////////////////////////////////////////////////////////////////////////////////////////

    glTranslatef(-0.62, -0.001, 0);  ///left building
    hut();
    glLoadIdentity();


    glTranslatef(-0.38, 0.0, 0);   ///middle building
    hut();
    glLoadIdentity();


    glTranslatef(-0.14, 0.0, 0);   ///right building
    hut();
    glLoadIdentity();

    glTranslatef(-0.28, 0.43, 0);   ///windmilfan
    drawWindmill();
    glLoadIdentity();

    glTranslatef(-0.28, 0.43, 0);   ///windmilstick
    windmilStick();
    glLoadIdentity();

    glTranslatef(-0.28, 0.43, 0);   ///windmilhead
    windMills();
    glLoadIdentity();
///////////////////////////////////////////////////////////////////////////////////////////////
            tree();

            ship();

            hut2();

            vehicle();

            vehicle2();

            windMills();

            windmilStick();

            drawWindmill();
        }

     else if(start_flag == 2)
        {
            LastDesign();
        }


    glFlush ();
}


void myKeyboard(unsigned char key, int x, int y)
{
    switch(key)       //////////////a d j k
    {

        case 'a'://press a to slow truck
            truckSpeed -= 0.03f;
            break;

        case 'd'://press d to fast truck
            truckSpeed += 0.05f;
            break;

        case 'k'://press j to fast car
            carSpeed -= 0.03f;
            break;

        case 'j'://press k to slow car
            carSpeed += 0.05f;
            break;

        case ' ':
            if(start_flag==0)
                {
                    start_flag = 1;
                }
            else if(start_flag == 1)
                {
                    start_flag = 2;
                }
            break;

        case 10 :
            exit(0);
            break;

        default:
            break;

        glutPostRedisplay();

    }

}
void myInit (void)
{
    glClearColor(0.5f, 0.5f, 0.5f, 1);
}

int main(int argc, char** argv)
{

    cout << endl << "Project"<< endl << endl;

    cout << endl << "Keyboard Interaction"<< endl << endl;

    cout << endl << "For Truck:"<< endl;

    cout << "Press a : To Slow down the Truck" << endl;
    cout << "Press d: To make the truck drive faster" << endl << endl;

    cout << endl << "For Car:"<< endl;

    cout << "Press  k: To Slow down the car" << endl;
    cout << "Press  j: To make the car drive faster" << endl << endl;



    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 680);
    glutInitWindowPosition (50, 10);
    glutCreateWindow ("Industrial View With Windmill");

    myInit();

    glutDisplayFunc(myDisplay);

    glutKeyboardFunc(myKeyboard);

    glutTimerFunc(1000, updateBoat, 0);
    glutTimerFunc(1000, updateCloud, 0);
    glutTimerFunc(1000, updateCloud1, 0);
    glutTimerFunc(1000, updateFan, 0);
    glutTimerFunc(1000, updateTruck, 0);
    glutTimerFunc(1000, updateCar, 0);
    glutTimerFunc(1000, updateSun, 0);

    glutMainLoop();
}

