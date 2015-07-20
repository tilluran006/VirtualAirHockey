#include "game.h"

float helpIconX,helpIconY;

void writeText(int x,char *str);

void stateHelp()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT );

	glColor3d(0,1,0);
	glLineWidth(3);
	glPointSize(2);
	
	writeText(0,"Welcome to Virtual AirHockey");
	glColor3d(1,1,1);
	writeText(50,"This is a 2-player 2D game, you can enjoy with ");
	writeText(85,"your Buddies");
	writeText(160,"Keys:");
	glColor3d(1,0,0);
	writeText(200,"Player 1: Left-'a', Right-'d' ");
	writeText(240,"          Up-'w'  , Down-'s'");
	glColor3d(0,0,1);
	writeText(290,"Player 2: Left- Left Arrow, Right- Right Arrow");
	writeText(330,"          Up  - Up Arrow  , Down -Down Arrow");
	glColor3d(1,1,0);
	writeText(390,"   'p' for PAUSE and UNPAUSE");

	listIcons();
}

void writeText(int x, char *str)
{
	glPushMatrix();
	glTranslated(0,height-x,0);
	glScalef(0.2,0.25,0.25);
	strokeSpString(str);
	glPopMatrix();
}