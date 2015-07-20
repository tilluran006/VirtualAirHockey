#include "game.h"
#include "drawice.c"

float startIconX[4],startIconY[4];

void startIcons();

void stateStart()
{
	static int count=0;
	float angle;
	float ht;

	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	angle=count*M_PI/180;

	///////////Jumping Ball///////////
	glColor3ub(255,0,0);
	ht=120*sin(angle*2);
	ht=abs(ht);
	drawColorBall(width/2-20,ht+3*height/4+20,20);

	//////////Text "BALL"//////////
	glColor3ub(0,255,0);
	glLineWidth(8);
	glPointSize(4);
	glPushMatrix();
	glTranslated(0,0,0);
	glTranslated(width/10-100,3*height/4,0);
	glScalef(1.2,1.2,0);
	glBegin(GL_LINES);
	glVertex2d(343,0);
	glVertex2d(345+500,0);
	glEnd();
	strokeString("Virtual");
	glPopMatrix();

	///////////Text "Air"//////////
	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(4*width/8+50,3*height/4+8,0);
	glScalef(0.7,0.7,0);
	strokeString("Air");
	glPopMatrix();

	////////Text "-"///////
	glBegin(GL_LINES);
	glVertex2d(5*width/8+65,3*height/4+40);
	glVertex2d(5*width/8+35,3*height/4+40);
	glEnd();

	/////////Text "Hockey"///////////
	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(5*width/8+70,3*height/4+8,0);
	glScalef(0.7,0.7,0);
	strokeString("Hockey");
	glPopMatrix();

	/////////Drawing Icons/////////
	startIcons();

	count++;
}

void startIcons()
{
	///////////Icon start////////////

	glColor3ub(200,0,0);
	startIconX[0]=width/2;
	startIconY[0]=height/4+50;
	drawColorBall(startIconX[0],startIconY[0],height/4);

	/*glColor4ub(0,0,0,40);
	glPointSize(7);
	drawCircle(startIconX[0],startIconY[0],height/4);*/

	glColor3ub(255,255,255);
	glLineWidth(7);
	glPointSize(4);
	glPushMatrix();
	glTranslated(width/2-100,height/4+25,0);
	glScalef(0.5,0.5,0.5);	
	strokeString("START");
	glPopMatrix();

	////////////Icon Exit/////////////
	glColor3ub(120,120,120);
	startIconX[1]=3*width/4;
	startIconY[1]=height/8;
	drawColorBall(startIconX[1],startIconY[1],height/12);

	glColor4ub(0,0,0,40);
	glPointSize(7);
	drawCircle(startIconX[1],startIconY[1],height/4);

	glColor3ub(0,0,0);
	glLineWidth(10);
	glPointSize(6);
	glPushMatrix();
	glTranslated(3*width/4-20,height/8-25,0);
	glScalef(0.6,0.5,0.5);	
	strokeString("X");
	glPopMatrix();

	//////////Icon List//////////////
	glColor3ub(255,255,0);
	startIconX[2]=width/4;
	startIconY[2]=height/8;
	drawColorBall(startIconX[2],startIconY[2],height/12);

	glColor4ub(0,0,0,100);
	glPointSize(7);
	drawCircle(startIconX[2],startIconY[2],height/4);

	glColor3ub(0,0,0);
	glLineWidth(10);
	glPointSize(6);
	glPushMatrix();
	glTranslated(width/4-8,height/8-25,0);
	glScalef(0.5,0.5,0.5);	
	strokeString("i");
	glPopMatrix();

	////////////Icon Help////////
	glColor3ub(0,0,255);
	startIconX[3]=width/2;
	startIconY[3]=height/15-40;
	drawColorBall(startIconX[3],startIconY[3],height/15);

	glColor4ub(0,0,0,10);
	glPointSize(6);
	drawCircle(startIconX[3],startIconY[3],height/15);

	glColor3ub(0,0,0);
	glLineWidth(10);
	glPointSize(6);
	glPushMatrix();
	glTranslated(width/2-10,height/15-60,0);
	glScalef(0.4,0.4,0.4);	
	strokeString("h");
	glPopMatrix();

}