#include "game.h"

void drawPauseSpace();
void pauseIcons();

double size=1;

int n;

int timeCount=0;
float pauseIconX[3],pauseIconY[3];


void statePauseOn()
{
	static int color=0;
	drawPauseSpace();
	float angle=timeCount*(M_PI/180)*2;

	size=0.05*sin(angle)+0.55;
	double alpha=255*sin(angle)/2+255/2;
	srand(time(NULL));

	glLineWidth(20);
	glPointSize(5);
	glColor4ub(255,50,50,alpha);

	glPushMatrix();
	glTranslated(3*width/8,height/2,0);
	glScalef(size,size,1);;
	strokeString("PAUSED");
	glPopMatrix();

	pauseIcons();

	timeCount++;
}

void statePauseOff()
{
	timeCount=0;
}

void drawPauseSpace()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	drawRectangle(width,height);

	drawComponents();
	drawBoundary(width,height);
	calcScore();

	drawLeftBlock(x[1],y[1],height);
	drawRightBlock(x[2],y[2],height);
	drawBall(x[0],y[0],radius,radius);

	glColor4d(1,1,1,0.7);
	glBegin(GL_POLYGON);
	glVertex2d(-50,-50);
	glVertex2d(width+50,-50);
	glVertex2d(width+50,height+100);
	glVertex2d(-50,height+100);
	glEnd();
}

void pauseIcons()
{	
	////////Play icon///////
	glPointSize(2);
	glColor3ub(200,0,0);

	pauseIconX[0]=3*width/9;
	pauseIconY[0]=3*height/8;

	drawColorBall(pauseIconX[0],pauseIconY[0],40);

	glColor4ub(0,0,0,40);
	glPointSize(4);
	drawCircle(pauseIconX[0],pauseIconY[0],40);

	glPointSize(2);
	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(3*width/9-15,3*height/8,0);
	glRotated(-90,0,0,1);
	glBegin(GL_TRIANGLES);
	glVertex2d(35*sin(45*(M_PI/180)),0);
	glVertex2d(-35*cos(45*(M_PI/180)),0);
	glVertex2d(0,40);
	glEnd();
	glPopMatrix();

	////////////Restart Icon///////////

	glPointSize(2);
	glColor3ub(0,200,0);

	pauseIconX[1]=2*width/3;
	pauseIconY[1]=3*height/8;

	drawColorBall(pauseIconX[1],pauseIconY[1],40);

	glColor4ub(0,0,0,40);
	glPointSize(4);
	drawCircle(pauseIconX[1],pauseIconY[1],40);

	glLineWidth(8);
	glPointSize(5);
	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(pauseIconX[1]-18,pauseIconY[1]-18,0);
	glScalef(0.5,0.5,1);
	strokeString("c");
	glPopMatrix();

	glLineWidth(8);
	glPointSize(4);
	glPushMatrix();
	glTranslated(pauseIconX[1]+10,pauseIconY[1]+10,0);
	glScalef(0.6,0.6,1);
	glRotated(-140,0,0,1);
	glBegin(GL_TRIANGLES);
	glVertex2d(20*sin(45*(M_PI/180)),0);
	glVertex2d(-20*cos(45*(M_PI/180)),0);
	glVertex2d(0,30);
	glEnd();
	glPopMatrix();

	///////////Return Icon////////////
	glPointSize(2);
	glColor3ub(204,0,204);

	pauseIconX[2]=width/2;
	pauseIconY[2]=height/8;

	drawColorBall(pauseIconX[2],pauseIconY[2],40);

	glColor4ub(0,0,0,40);
	glPointSize(4);
	drawCircle(pauseIconX[2],pauseIconY[2],40);

	glLineWidth(8);
	glPointSize(5);
	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(pauseIconX[2]-25,pauseIconY[2]-5,0);
	glScalef(0.25,0.25,1);
	drawArrow();
	glPopMatrix();

	glLineWidth(4);
	glPointSize(2);
	glColor3ub(255,255,255);
	glPushMatrix();
	glTranslated(pauseIconX[2],pauseIconY[2],0);
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

