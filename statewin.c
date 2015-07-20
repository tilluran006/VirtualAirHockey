#include "game.h"

void drawWinnerBlur();
void drawWinner();
void winIcons();

int count=0;
float winIconX[2],winIconY[2];

void stateWin()
{
	float blur;

	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawWinnerBlur();

	blur=127*sin(4*count*M_PI/180)+127;

	glLineWidth(7);
	glPointSize(4);
	if(scoreRight==7)
	{
		glColor4ub(0,0,255,blur);
		glPushMatrix();
		glTranslated(width/2,0,0);
		drawWinner();
		glPopMatrix();
	}
	else
	{
		glColor4ub(255,0,0,blur);
		drawWinner();
	}
	winIcons();

	count++;
}

void drawWinnerBlur()
{
	drawRectangle(width,height);
	drawComponents();
	drawBoundary(width,height);
	calcScore();

	drawLeftBlock(x[1],y[1],height);
	drawRightBlock(x[2],y[2],height);
	drawBall(x[0],y[0],radius,radius);

	if(scoreRight==7)
	{
		glColor4d(1,1,1,0.7);
		glBegin(GL_POLYGON);
		glVertex2d(width/2,0);
		glVertex2d(width,0);
		glVertex2d(width,height);
		glVertex2d(width/2,height);
		glEnd();

		glColor4d(0,0,0,0.7);
		glBegin(GL_POLYGON);
		glVertex2d(0,0);
		glVertex2d(width/2,0);
		glVertex2d(width/2,height);
		glVertex2d(0,height);
		glEnd();
	}else
	{
		glColor4d(1,1,1,0.7);
		glBegin(GL_POLYGON);
		glVertex2d(0,0);
		glVertex2d(width/2,0);
		glVertex2d(width/2,height);
		glVertex2d(0,height);
		glEnd();

		glColor4d(0,0,0,0.7);
		glBegin(GL_POLYGON);
		glVertex2d(width/2,0);
		glVertex2d(width,0);
		glVertex2d(width,height);
		glVertex2d(width/2,height);
		glEnd();
	}
}

void drawWinner()
{
	float wSize;
	wSize=0.05*sin(4*count*M_PI/180)+0.5;
	glPushMatrix();
	glTranslated(width/8,height/2,0);
	glScalef(wSize,wSize,0);
	strokeString("WINNER");
	glPopMatrix();
}

void winIcons()
{
	/////////Icon Restart///////

	glPointSize(2);
	glColor3ub(0,200,0);

	winIconX[0]=4*width/10;
	winIconY[0]=height/8;

	drawColorBall(winIconX[0],winIconY[0],40);

	glColor4ub(0,0,0,40);
	glPointSize(4);
	drawCircle(winIconX[0],winIconY[0],40);

	glLineWidth(8);
	glPointSize(5);
	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(winIconX[0]-18,winIconY[0]-18,0);
	glScalef(0.5,0.5,1);
	strokeString("c");
	glPopMatrix();

	glLineWidth(8);
	glPointSize(4);
	glPushMatrix();
	glTranslated(winIconX[0]+10,winIconY[0]+10,0);
	glScalef(0.6,0.6,1);
	glRotated(-140,0,0,1);
	glBegin(GL_TRIANGLES);
	glVertex2d(20*sin(45*(M_PI/180)),0);
	glVertex2d(-20*cos(45*(M_PI/180)),0);
	glVertex2d(0,30);
	glEnd();
	glPopMatrix();

	/////////////Icon Return///////////
	glPointSize(2);
	glColor3ub(204,0,204);

	winIconX[1]=6*width/10;
	winIconY[1]=height/8;

	drawColorBall(winIconX[1],winIconY[1],40);

	glColor4ub(0,0,0,40);
	glPointSize(4);
	drawCircle(winIconX[1],winIconY[1],40);

	glLineWidth(8);
	glPointSize(5);
	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(winIconX[1]-25,winIconY[1]-5,0);
	glScalef(0.25,0.25,1);
	drawArrow();
	glPopMatrix();

	glLineWidth(4);
	glPointSize(2);
	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(winIconX[1],winIconY[1],0);
	glScalef(1,1,1);
	glBegin(GL_LINES);
	glVertex2d(-10,20);
	glVertex2d(10,20);
	glVertex2d(10,20);
	glVertex2d(10,-20);
	glVertex2d(10,-20);
	glVertex2d(-10,-20);
	glVertex2d(-10,-20);
	glVertex2d(-10,20);
	glEnd();
	glPopMatrix();

}