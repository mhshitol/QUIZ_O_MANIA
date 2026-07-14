#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>


using namespace std;


void init()
{
    glClearColor(0.0,0.5,0.8,1.0);
	gluOrtho2D(0.0,1280,0.0,720);
}

void Land()
{
	glColor3ub(0,130, 50);
	glBegin(GL_QUADS);
    glVertex2i(0, 170);///BottomLeft
    glVertex2i(1280, 150);///BottomRight
	glVertex2i(1280, 450);///TopRight
	glVertex2i(0, 450);///TopLeft
	glEnd();
}
void Sky(){
    glColor3ub(45, 139, 237);
	glBegin(GL_QUADS);
    glVertex2i(0, 720);
    glVertex2i(1280, 720);
	glVertex2i(1280, 100);
	glVertex2i(0, 100);
	glEnd();
}
void River()
{
    glColor3ub(0,180,250);///color
    glBegin(GL_QUADS);
    glVertex2i(0, 170);///TopLeft
    glVertex2i(1280, 150);///TopRight
	glVertex2i(1280, 0);///BottomRight
	glVertex2i(0, 0);///BottomLeft
	glEnd();
}

void Hill()
{
    glColor3ub(112,77, 12);
    glBegin(GL_QUADS);
    glVertex2i(0,450);
    glVertex2i(0,500);
    glVertex2i(100,550);
    glVertex2i(200,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(100,450);
    glVertex2i(300,650);
    glVertex2i(500,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(260,450);
    glVertex2i(500,630);
    glVertex2i(700,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(480,450);
    glVertex2i(750,630);
    glVertex2i(1100,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(800,450);
    glVertex2i(1000,650);
    glVertex2i(1200,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(1000,500);
    glVertex2i(1200,650);
    glVertex2i(1270,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(1100,450);
    glVertex2i(1280,580);
    glVertex2i(1280,450);
    glEnd();
}

void Sun()
{
    glPushMatrix();
    glTranslatef(600,660, 0);
    glBegin(GL_POLYGON);
    glColor3ub(249,215,28);
for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();
}

void HighWay()
{
    ///main road
    glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(0,250);
	glVertex2i(1280,250);
	glVertex2i(1280,200);
	glVertex2i(0,200);
	glEnd();

    ///sub road 1
	glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(300,250);
	glVertex2i(330-10,250);
	glVertex2i(300-10,450);
	glVertex2i(270,450);
	glEnd();

    ///sub road 2
    glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(940,450);
	glVertex2i(960,450);
	glVertex2i(960,250);
	glVertex2i(940,250);
	glEnd();

	///sub road 3
	glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(0,375);
	glVertex2i(0,365);
	glVertex2i(300,365);
	glVertex2i(300,375);
	glEnd();

    ///divider
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2i(0,222);
	glVertex2i(1280,222);
	glVertex2i(0,225);
	glVertex2i(1280,225);
	glEnd();

}

void RoadLights1()
{
    float a;
	for(a=0; a<=1280; a+=70)
    {
        float b=a+3;
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(a,200);
        glVertex2i(b,200);
        glVertex2i(b,218);
        glVertex2i(a,218);
        glEnd();
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glVertex2i(a,218);
        glVertex2i(b,218);
        glVertex2i(b,223);
        glVertex2i(a,223);
        glEnd();
    }
}

void RoadLights2()
{
	float a;
	for(a=35; a<=1280; a+=70)
    {
        float b=a+3;
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(a,250);
        glVertex2i(b,250);
        glVertex2i(b,268);
        glVertex2i(a,268);
        glEnd();
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glVertex2i(a,268);
        glVertex2i(b,268);
        glVertex2i(b,273);
        glVertex2i(a,273);
        glEnd();
    }
}
void Building1(int a, int b , int c , int d, int color[3])
{
        ///for x axis /// difference = 80
        ///for y axis /// difference = 40

        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c);
        glVertex2i(b,c);
        glVertex2i(b,d);
        glVertex2i(a,d);
        glEnd();
        glColor3ub(225,225,225);
        glBegin(GL_QUADS);
        glVertex2i(a+20,c);
        glVertex2i(b-20,c);
        glVertex2i(b-20,d-20);
        glVertex2i(a+20,d-20);
        glEnd();
        ///second floor
        glColor3ub(22, 150, 219);
        glBegin(GL_QUADS);
        glVertex2i(a+5,c+40);
        glVertex2i(b-5,c+40);
        glVertex2i(b-5,d+40);
        glVertex2i(a+5,d+40);
        glEnd();
        ///third floor
        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a+10,c+80);
        glVertex2i(b-10,c+80);
        glVertex2i(b-10,d+80);
        glVertex2i(a+10,d+80);
        glEnd();
        ///fourth floor
        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a+15,c+120);
        glVertex2i(b-15,c+120);
        glVertex2i(b-15,d+120);
        glVertex2i(a+15,d+120);
        glEnd();
        glColor3ub(175, 179, 179);
        glBegin(GL_QUADS);
        glVertex2i(a+39,c+160);
        glVertex2i(b-39,c+160);
        glVertex2i(b-39,d+140);
        glVertex2i(a+39,d+140);
        glEnd();
}

void PlayGroud()
{
        glColor3ub(52, 186, 60);
        glBegin(GL_QUADS);
        glVertex2i(40,270);
        glVertex2i(200,270);
        glVertex2i(185,350);
        glVertex2i(30,350);
        glEnd();

        glLineWidth(1.5);
        glBegin(GL_LINES);///Bottom line
        glColor3ub(255,255,255);
        glVertex2i(40,270);
        glVertex2i(200,270);
        glEnd();

        glBegin(GL_LINES);///Top line
        glColor3ub(255,255,255);
        glVertex2i(185,350);
        glVertex2i(30,350);
        glEnd();

        glBegin(GL_LINES);///Left line
        glColor3ub(255,255,255);
        glVertex2i(40,270);
        glVertex2i(30,350);
        glEnd();

        glBegin(GL_LINES);///Right line
        glColor3ub(255,255,255);
        glVertex2i(200,270);
        glVertex2i(185,350);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2i(120,270);
        glVertex2i(105,350);
        glEnd();

        glColor3ub(78, 237, 88);
        glBegin(GL_QUADS);
        glVertex2i(40,280);
        glVertex2i(80,280);
        glVertex2i(70,340);
        glVertex2i(32,340);
        glEnd();

        glColor3ub(78, 237, 88);
        glBegin(GL_QUADS);
        glVertex2i(197,280);
        glVertex2i(157,280);
        glVertex2i(144,340);
        glVertex2i(186,340);
        glEnd();
}
void HillTree1(int y1, int y2)
{
    ///difference = 15
    for(int a=10;a<1280;a+=50)
    {
        int b=a+2;
        glColor3ub(77, 53, 12);
        glBegin(GL_QUADS);
        glVertex2i(a, y1);
        glVertex2i(b, y1);
        glVertex2i(b, y2);
        glVertex2i(a, y2);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, y2);
        glVertex2i(b+5, y2);
        glVertex2i(a+1,y2+10);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, y2+4);
        glVertex2i(b+5, y2+4);
        glVertex2i(a+1,y2+14);
        glEnd();
    }
}

void HillTree2(int y1, int y2)
{
    ///difference = 15
    for(int a=30;a<1280;a+=50)
    {
        int b=a+2;
        glColor3ub(77, 53, 12);
        glBegin(GL_QUADS);
        glVertex2i(a, y1);
        glVertex2i(b, y1);
        glVertex2i(b, y2);
        glVertex2i(a, y2);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, y2);
        glVertex2i(b+5, y2);
        glVertex2i(a+1,y2+10);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, y2+4);
        glVertex2i(b+5, y2+4);
        glVertex2i(a+1,y2+14);
        glEnd();
    }
}

void Hospital(int a, int b , int c , int d, int color[3])
{
        ///for x axis /// difference = 80
        ///for y axis /// difference = 40

        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c);
        glVertex2i(b,c);
        glVertex2i(b,d);
        glVertex2i(a,d);
        glEnd();
        glColor3ub(200,200,200);
        glBegin(GL_QUADS);
        glVertex2i(a+20,c);
        glVertex2i(b-20,c);
        glVertex2i(b-20,d-20);
        glVertex2i(a+20,d-20);
        glEnd();
        ///second floor
        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c+40);
        glVertex2i(b,c+40);
        glVertex2i(b,d+40);
        glVertex2i(a,d+40);
        glEnd();
        glColor3ub(141, 142, 145);
        glBegin(GL_QUADS);
        glVertex2i(a+10,c+50);
        glVertex2i(a+30,c+50);
        glVertex2i(a+30,d+30);
        glVertex2i(a+10,d+30);
        glEnd();
        glBegin(GL_QUADS);
        glVertex2i(a+45,c+50);
        glVertex2i(a+65,c+50);
        glVertex2i(a+65,d+30);
        glVertex2i(a+45,d+30);
        glEnd();
        glBegin(GL_QUADS);
        glVertex2i(a+80,c+50);
        glVertex2i(a+100,c+50);
        glVertex2i(a+100,d+30);
        glVertex2i(a+80,d+30);
        glEnd();

        ///third floor
        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c+80);
        glVertex2i(b,c+80);
        glVertex2i(b,d+80);
        glVertex2i(a,d+80);
        glEnd();

        glColor3ub(141, 142, 145);
        glBegin(GL_QUADS);
        glVertex2i(a+10,c+90);
        glVertex2i(a+30,c+90);
        glVertex2i(a+30,d+70);
        glVertex2i(a+10,d+70);
        glEnd();
        glBegin(GL_QUADS);
        glVertex2i(a+45,c+90);
        glVertex2i(a+65,c+90);
        glVertex2i(a+65,d+70);
        glVertex2i(a+45,d+70);
        glEnd();
        glBegin(GL_QUADS);
        glVertex2i(a+80,c+90);
        glVertex2i(a+100,c+90);
        glVertex2i(a+100,d+70);
        glVertex2i(a+80,d+70);
        glEnd();

        ///fourth floor
        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c+120);
        glVertex2i(b,c+120);
        glVertex2i(b,d+120);
        glVertex2i(a,d+120);
        glEnd();

        glColor3ub(141, 142, 145);
        glBegin(GL_QUADS);
        glVertex2i(a+10,c+130);
        glVertex2i(a+30,c+130);
        glVertex2i(a+30,d+110);
        glVertex2i(a+10,d+110);
        glEnd();
        glBegin(GL_QUADS);
        glVertex2i(a+45,c+130);
        glVertex2i(a+65,c+130);
        glVertex2i(a+65,d+110);
        glVertex2i(a+45,d+110);
        glEnd();
        glBegin(GL_QUADS);
        glVertex2i(a+80,c+130);
        glVertex2i(a+100,c+130);
        glVertex2i(a+100,d+110);
        glVertex2i(a+80,d+110);
        glEnd();
}

void Building2(int a, int b , int c , int d, int color[3])
{
        ///for x axis /// difference = 80
        ///for y axis /// difference = 40

        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c);
        glVertex2i(a+50,c);
        glVertex2i(a+50,d);
        glVertex2i(a,d);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2i(a+60,c);
        glVertex2i(b,c);
        glVertex2i(b,d);
        glVertex2i(a+60,d);
        glEnd();

        for(int i=c;  i<d;  i+=3){
        glBegin(GL_LINES);
        glColor3ub(69, 69, 69);
        glVertex2i(a,i);
        glVertex2i(a+50,i);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(69, 69, 69);
        glVertex2i(a+60,i);
        glVertex2i(b,i);
        glEnd();
        }
        glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex2i(a+25,d);
        glVertex2i(a+25,d+20);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex2i(a+60+25,d);
        glVertex2i(a+60+25,d+20);
        glEnd();

}
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Sky();
    Land();
    Sun();
    Hill();
    HillTree1(440,465);

    River();
    HighWay();

    int color[3]={45, 93, 168};
    Building1(10,90,380,420,color); ///a //b //c //d //color

    int color1[3]={30, 103, 217};
    Building1(100,180,380,420,color1);

    int color2[3]={45, 93, 168};
    Building1(190,270,380,420,color2);

    ///
    int color7[3]={99, 122, 194};
    Hospital(320,430,310,350,color7);

    int color8[3]={70, 160, 179};
    Hospital(440,550,310,350,color8);

    int color9[3]={99, 122, 194};
    Hospital(680,790,310,350,color9);

    int color10[3]={70, 160, 179};
    Hospital(800,910,310,350,color10);

    Building1(560,640,370,410,color10);
    ///

    int color3[3]={45, 93, 168};
    Hospital(340,450,270,310,color3);

    int color4[3]={45, 112, 128};
    Hospital(460,570,270,310,color4);

    int color5[3]={45, 93, 168};
    Hospital(700,810,270,310,color5);

    int color6[3]={44, 73, 133};
    Hospital(820,930,270,310,color6);

    int color11[3]={169, 174, 176};
    Building2(580,690,270,600,color11);

    PlayGroud();
    RoadLights1();
    HillTree1(255,270);
    HillTree1(180,205);
    HillTree2(170,195);
    RoadLights2();

    glFlush();
}


int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Urban Landscape");
	glutDisplayFunc(Display);
    init();

	glutMainLoop();
	return 0;
}

