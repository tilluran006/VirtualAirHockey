#include "game.h"

void stateRestart()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	////////////////ReSetting Co Ordinates of Objects////////////////
	x[0]=500;
	x[1]=20;
	x[2]=980;
	y[0]=250;
	y[1]=250;
	y[2]=250;

	//////////////ReSetting Scores///////////////
	scoreLeft=scoreRight=0;

	/////////////Resetting speeds///////////
	speedx=0;
	speedy=0;

	////////////Resetting timer//////
	timeCount=0;
}