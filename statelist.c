#include "game.h"

void listIcons();
void drawArrow();

float listIconX[1],listIconY[1];

void stateList()
{
	static int count=0;
	float angle=count*M_PI/180;
	float size;
	float pos;
	float rot;

	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//////////Text "Created By"////////
	size=0.1*sin(angle)+0.9;
	glColor3ub(200,200,200);
	glLineWidth(10);
	glPointSize(5);
	glPushMatrix();
	glTranslated(width/8,7*height/8,0);
	glScalef(size,size,0);
	strokeString("Created By");
	glPopMatrix();

	////////Text "Akshay CD"/////

	pos=10*sin(angle*5);
	rot=0.25*sin(angle*5-5);
	glColor3ub(238,50,29);
	glLineWidth(4);
	glPointSize(2);
	glPushMatrix();
	glRotated(rot,0,0,1);
	glTranslated(width/3+pos,height/1.5-20,0);
	glScalef(0.35,0.35,0);
	strokeString("Akshay CD");
	glPopMatrix();

	//////Text "Samanvith A"////////

	pos=10*sin(angle*5-10);
	rot=0.25*sin(angle*5+5);
	glColor3ub(0,255,0);
	glLineWidth(4);
	glPointSize(2);
	glPushMatrix();
	glRotated(rot,0,0,1);
	glTranslated(width/3+pos,(height/1.5)*4/5-25,0);
	glScalef(0.35,0.35,0);
	strokeString("Samanvith A");
	glPopMatrix();

	/////////Text "Manith S"/////////

	pos=10*sin(angle*5+10);
	rot=0.25*sin(angle*5+10);
	glColor3ub(255,0,127);
	glLineWidth(4);
	glPointSize(2);
	glPushMatrix();
	glRotated(rot,0,0,1);
	glTranslated(width/3+pos,(height/1.5)*3/5-30,0);
	glScalef(0.35,0.35,0);
	strokeString("Manith Shetty");
	glPopMatrix();

	////////////Text "Rohan P"////////

	pos=10*sin(angle*5-20);
	rot=0.25*sin(angle*5-10);
	glColor3ub(0,0,255);
	glLineWidth(4);
	glPointSize(2);
	glPushMatrix();
	glRotated(rot,0,0,1);
	glTranslated(width/3+pos,(height/1.5)*2/5-35,0);
	glScalef(0.35,0.35,0);
	strokeString("Rohan P");
	glPopMatrix();

	//////////////Text "Tilak Raj"/////////

	pos=10*sin(angle*5+20);
	rot=0.25*sin(angle*5);
	glColor3ub(140,46,164);
	glLineWidth(4);
	glPointSize(2);
	glPushMatrix();
	glRotated(rot,0,0,1);
	glTranslated(width/3+pos,(height/1.5)*1/5-40,0);
	glScalef(0.35,0.35,0);
	strokeString("Tilak Raj");
	glPopMatrix();

	listIcons();

	count++;
}

void listIcons()
{
	glColor3ub(0,153,0);
	listIconX[0]=width/20;
	listIconY[0]=height/15;
	drawColorBall(listIconX[0],listIconY[0],40);

	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(listIconX[0],listIconY[0],0);
	glScalef(0.5,0.5,0);
	glTranslated(-28,-15,0);
	drawArrow();
	glPopMatrix();
}
