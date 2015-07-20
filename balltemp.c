#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "game.h"
#include "statestart.c"
#include "staterun.c"
#include "stateout.c"
#include "statepause.c"
#include "staterestart.c"
#include "statelist.c"
#include "statewin.c"

int width=1000,height=500;
int up[]={0,0},down[]={0,0},right[]={0,0},left[]={0,0};
int radius=15;
int leftb=1,rightb=0;
int out=0;
int loopTime=0;
int scoreLeft=0,scoreRight=0;
double xspeeder,yspeeder;
double yi,xi;
double speedx=0,speedy=0;

bool play=false,restart=false,pReturn=false;
bool start=false,list=false,quit=false;
bool back=false;
bool retrn=false,wRestart=false;

float distPlay=0,distRestart=0,distPReturn=0;
float distStart=0,distExit=0,distList=0;
float distBack=0;
float distReturn=0,distWRestart=0;

enum STATE
{
	START,
	RUNNING,
	PAUSE,
	OUT,
	EXIT,
	RESTART,
	LIST,
	WIN
}state;

double x[3]={500,20,980},y[3]={250,250,250};

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50,width+50,-50,height+100);
	state=START;
}

void display()
{

	if(state==START){
		stateRestart();
		stateStart();

		if(start==true)
		{
			glColor4ub(255,255,255,5-distStart*5/(height*height/16));
			drawColorBall(startIconX[0],startIconY[0],height/4);
		}

		if(list==true)
		{
			glColor4ub(255,255,255,4-distList*4/(height*height/144));
			drawColorBall(startIconX[2],startIconY[2],height/12);
		}

		if(quit==true)
		{
			glColor4ub(255,255,255,4-distExit*4/(height*height/144));
			drawColorBall(startIconX[1],startIconY[1],height/12);
		}
	}

	if(state==RUNNING)
	{
		if(scoreRight==7 || scoreLeft==7)
		{
				state=WIN;
		}
		else
		{
		if(x[0]+radius>=width)
			if(y[0]<height*3/4 && y[0]>height/4)
				state=OUT;

		if(x[0]-radius<=0)	
			if(y[0]<height*3/4 && y[0]>height/4)
				state=OUT;
		}
		stateRunning();

	}

	if(state==OUT)
	{
		stateOut();
		state=RUNNING;
	}

	if(state==PAUSE)
	{
		statePauseOn();
		if(play==true)
		{
			glColor4ub(255,255,255,6-6*distPlay/(40*40));
			drawColorBall(pauseIconX[0],pauseIconY[0],40);
		}
		if(restart==true)
		{
			glColor4ub(255,255,255,6-6*distRestart/(40*40));
			drawColorBall(pauseIconX[1],pauseIconY[1],40);
		}
		if(pReturn==true)
		{
			glColor4ub(255,255,255,10-10*distPReturn/(40*40));
			drawColorBall(pauseIconX[2],pauseIconY[2],40);
		}
	}

	if(state==EXIT)
		exit(0);

	if(state==LIST)
	{
		stateList();
		if(back==true)
		{
			glColor4ub(255,255,255,8-8*distBack/(40*40));
			drawColorBall(listIconX[0],listIconY[0],40);
		}
	}

	if(state==RESTART)
	{
		stateRestart();
		state=RUNNING;
	}

	if(state==WIN)
	{
		stateWin();
		if(wRestart==true)
		{
			glColor4ub(255,255,255,10-10*distWRestart/(40*40));
			drawColorBall(winIconX[0],winIconY[0],40);
		}

		if(retrn==true)
		{
			glColor4ub(255,255,255,6-6*distReturn/(40*40));
			drawColorBall(winIconX[1],winIconY[1],40);
		}
	}

	glutSwapBuffers();
}

void key(unsigned char k,int x,int y)
{	
	if(k=='w')
	{
		up[0]=1;
	}

	if(k=='s')
	{	
		down[0]=1;
	}

	if(k=='a')
	{
		left[0]=1;
	}

	if(k=='d')
	{
		right[0]=1;
	}

	if(k=='p')
	{
		if(state == PAUSE)
		{
			statePauseOff();
			state=RUNNING;
		}
		else if(state == RUNNING)
		{
			state=PAUSE;		
		}	
	}

	glutPostRedisplay();
}

void mouse(int btn,int st,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON)
		printf("%d %d\n",x,y);

	if(state==START)
	{
		distStart=(550-x)*(550-x)+(425-y)*(425-y);
		if(distStart<height*height/16)
		{
			if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
				state=RUNNING;
		}

		distExit=(800-x)*(800-x)+(540-y)*(540-y);
		if(distExit<height*height/144)
		{
			if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
				state=EXIT;
		}

		distList=(300-x)*(300-x)+(538-y)*(538-y);
		if(distList<height*height/144)
		{
			if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
				state=LIST;
		}		
	}

	if(state==LIST)
	{
		distBack=(99-x)*(99-x)+(568-y)*(568-y);
		if(distBack<40*40)
		{
			if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
				state=START;

		}
	}

	if(state==PAUSE)
	{
		distPlay=((384-x)*(384-x))+((413-y)*(413-y));
		if(distPlay<40*40)
		{
			if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)	
				state=RUNNING;
		}

		distRestart=((717-x)*(717-x))+((413-y)*(413-y));
		if(distRestart<40*40)
		{
			if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)	
				state=RESTART;
		}

		distPReturn=(550-x)*(550-x)+(538-y)*(538-y);
		if(distPReturn<40*40)
		{
			if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
				state=START;
		}
	}

	if(state==WIN)
	{
		distWRestart=(450-x)*(450-x)+(539-y)*(539-y);
		if(distWRestart<40*40)
		{
			if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
				state=RESTART;
		}

		distReturn=(650-x)*(650-x)+(535-y)*(535-y);
		if(distReturn<40*40)
		{
			if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
				state=START;
		}
	}

	glutPostRedisplay();
}

void mouseMove(int x,int y)
{
	if(state==START)
	{
		/////////for Start Icon//////////
		distStart=(550-x)*(550-x)+(425-y)*(425-y);
		if(distStart<height*height/16)
			start=true;
		else
			start=false;

		////////////for List Icon////////
		distList=(300-x)*(300-x)+(538-y)*(538-y);
		if(distList<height*height/144)
			list=true;
		else
			list=false;

		////////////for Exit Icon//////////
		distExit=(800-x)*(800-x)+(540-y)*(540-y);
		if(distExit<height*height/144)
			quit=true;
		else
			quit=false;
	}

	if(state==LIST)
	{
		///////////for Back Icon///////
		distBack=(99-x)*(99-x)+(568-y)*(568-y);
		if(distBack<40*40)
			back=true;
		else
			back=false;
	}

	if(state==PAUSE)
	{
		////////for play icon
		distPlay=((384-x)*(384-x))+((413-y)*(413-y));
		if(distPlay<40*40)
		{
			play=true;
		}
		else
			play=false;

		/////////////for restart icon
		distRestart=((717-x)*(717-x))+((413-y)*(413-y));
		if(distRestart<40*40)
		{
			restart=true;
		}else
			restart=false;

		///////for return icon////////
		distPReturn=(550-x)*(550-x)+(538-y)*(538-y);
		if(distPReturn<40*40)
		{
			pReturn=true;
		}else
			pReturn=false;
	}

	if(state==WIN)
	{
		distWRestart=(450-x)*(450-x)+(539-y)*(539-y);
		if(distWRestart<40*40)
		{
			wRestart=true;
		}else
		{
			wRestart=false;
		}
		distReturn=(650-x)*(650-x)+(535-y)*(535-y);
		if(distReturn<40*40)
		{
			retrn=true;
		}else
			retrn=false;
	}

	glutPostRedisplay();
}

void keyUp(unsigned char k,int x,int y)
{	
	if(k=='w')
	{
		up[0]=0;
		yspeeder=0;
	}

	if(k=='s')
	{	
		down[0]=0;
		yspeeder=0;
	}

	if(k=='a')
	{
		left[0]=0;
		xspeeder=0;
	}

	if(k=='d')
	{
		right[0]=0;
		xspeeder=0;
	}

	glutPostRedisplay();
}

void specialKey(int k,int x,int y)
{
	if(k==GLUT_KEY_UP)
	{
		up[1]=1;
	}

	if(k==GLUT_KEY_DOWN)
	{
		down[1]=1;
	}

	if(k==GLUT_KEY_LEFT)
	{
		left[1]=1;
	}

	if(k==GLUT_KEY_RIGHT)
	{
		right[1]=1;
	}
	glutPostRedisplay();
}

void specialKeyUp(int k,int x,int y)
{
	if(k==GLUT_KEY_UP)
	{
		up[1]=0;
		yspeeder=0;
	}

	if(k==GLUT_KEY_DOWN)
	{
		down[1]=0;
		yspeeder=0;
	}

	if(k==GLUT_KEY_LEFT)
	{
		left[1]=0;
		xspeeder=0;
	}

	if(k==GLUT_KEY_RIGHT)
	{
		right[1]=0;
		xspeeder=0;
	}
	glutPostRedisplay();
}

void resize(int w,int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50,width+50,-50,height+100);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	drawRectangle(width,height);
	drawBoundary(width,height);
}

void idle(void)
{
	glutPostRedisplay();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowPosition(150,50);
	glutInitWindowSize(1100,650);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("BALL GAME");

	init();
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutKeyboardUpFunc(keyUp);
    glutIdleFunc(idle);
    glutSpecialFunc(specialKey);
    glutSpecialUpFunc(specialKeyUp);

    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutMainLoop();
}



