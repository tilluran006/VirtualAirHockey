#include "game.h"

void strokeSpString(char *string)
{
	char *c;
  for (c=string; *c != '\0'; c++)
  {
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *c);
  }
}

void strokeString(char *string)
{
	char *c;
  for (c=string; *c != '\0'; c++)
  {
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
  }
}


void drawCircle(double tempX, double tempY, double tempR)
{
	double angle,i;
	glBegin(GL_POINTS);
	for(i=0;i<360;i++)
	{
		angle=i*(M_PI/180);
		glVertex2d(tempX+(tempR*cos(angle)),tempY+(tempR*sin(angle)));
	}
	glEnd();
}

void drawColorBall(float x,float y,int rad)
{
	if(rad!=0)
	{
		drawCircle(x,y,rad);
		drawColorBall(x,y,rad-1);
	}
}

void drawLeftBlock(double tempX, double tempY,double height)
{
	glPointSize(1);
	glColor3d(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2d(tempX,tempY+(height/10));
	glVertex2d(tempX-10,tempY+(height/10));
	glVertex2d(tempX-10,tempY-(height/10));
	glVertex2d(tempX,tempY-(height/10));
	glEnd();
}

void drawRightBlock(double tempX, double tempY, double height)
{
	glPointSize(1);
	glColor3d(0,0,1);
	glBegin(GL_POLYGON);
	glVertex2d(tempX,tempY+(height/10));
	glVertex2d(tempX+10,tempY+(height/10));
	glVertex2d(tempX+10,tempY-(height/10));
	glVertex2d(tempX,tempY-(height/10));
	glEnd();
}

void drawBall(double tempX, double tempY, int tempR,int radius)
{
	if(tempR==radius/2+3 || tempR==radius-radius/4 || tempR==radius-radius/4+1)
		glColor3d(0.8,0.8,0.8);
	else
		glColor3d(0,0,0);
		
	glPointSize(1);
	if(tempR>=0)
	{
	double angle,i;
	glBegin(GL_POINTS);
	for(i=0;i<360;i++)
	{
		angle=i*(M_PI/180);
		glVertex2d(tempX+(tempR*cos(angle)),tempY+(tempR*sin(angle)));
	}
	glEnd();
	drawBall(tempX, tempY,tempR-1,radius);
}
}

void drawRectangle(int width,int height)
{
	int xtemp,ytemp;
	int c;
	glColor4ub(255,255,150,255);

	glBegin(GL_POLYGON);
	glVertex2d(-50,-50);
	glVertex2d(-50,height+50);
	glVertex2d(width+50,height+50);
	glVertex2d(width+50,-50);
	glEnd();
}

void drawUpperBlock(int width,int height)
{
	int x,y;
	glColor3ub(102,51,0);

	/////////Top Left Piece/////////
	glBegin(GL_POLYGON);
	glVertex2d(-50,height*3/4);
	glVertex2d(-50,height+50);
	glVertex2d(0,height+50);
	glVertex2d(0,height*3/4);
	glEnd();

	/////////////Top Piece//////////
	glBegin(GL_POLYGON);
	glVertex2d(0,height);
	glVertex2d(0,height+50);
	glVertex2d(width,height+50);
	glVertex2d(width,height);
	glEnd();

	/////////Top Right Piece///////////
	glBegin(GL_POLYGON);
	glVertex2d(width,height+50);
	glVertex2d(width+50,height+50);
	glVertex2d(width+50,height*3/4);
	glVertex2d(width,height*3/4);
	glEnd();

	glColor4ub(0,0,0,150);
	///////Top Left bricks///////
	glBegin(GL_LINES);
	glVertex2d(-25,height+50);
	glVertex2d(-25,3*height/4);
	glEnd();
	for(y=height*3/4;y<height+50;y+=50)
	{
		glBegin(GL_LINES);
		glVertex2d(-25,y);
		glVertex2d(0,y);
		glEnd();
	}

	for(y=height*3/4+20;y<height+50;y+=50)
	{
		glBegin(GL_LINES);
		glVertex2d(-25,y);
		glVertex2d(-50,y);
		glEnd();
	}

	///////Top Right bricks///////
	glBegin(GL_LINES);
	glVertex2d(width+25,height+50);
	glVertex2d(width+25,3*height/4);
	glEnd();
	for(y=height*3/4;y<height+50;y+=50)
	{
		glBegin(GL_LINES);
		glVertex2d(width,y);
		glVertex2d(width+25,y);
		glEnd();
	}

	for(y=height*3/4+15;y<height+50;y+=50)
	{
		glBegin(GL_LINES);
		glVertex2d(width+25,y);
		glVertex2d(width+50,y);
		glEnd();
	}

	/////////////Top Piece////////////
	glBegin(GL_LINES);
	glVertex2d(0,height+25);
	glVertex2d(width,height+25);
	glEnd();
	for(x=0;x<width;x+=50)
	{
		glBegin(GL_LINES);
		glVertex2d(x,height);
		glVertex2d(x,height+25);
		glEnd();
	}

	for(x=-25;x<width;x+=50)
	{
		glBegin(GL_LINES);
		glVertex2d(x,height+25);
		glVertex2d(x,height+50);
		glEnd();
	}
}

void drawOutline()
{
	glBegin(GL_LINES);
	////////Bottom Left/////////
	glVertex2d(-50,-50);
	glVertex2d(-50,height/4);
	glVertex2d(-50,height/4);
	glVertex2d(0,height/4);
	glVertex2d(0,height/4);
	glVertex2d(0,-50);
	glVertex2d(0,-50);
	glVertex2d(-50,-50);

	/////////Bottom ////////////
	glVertex2d(0,0);
	glVertex2d(0,-50);
	glVertex2d(0,-50);
	glVertex2d(width,-50);
	glVertex2d(width,-50);
	glVertex2d(width,0);
	glVertex2d(width,0);
	glVertex2d(0,0);

	/////////////Bottom Right////////
	glVertex2d(width,-50);
	glVertex2d(width+50,-50);
	glVertex2d(width+50,-50);
	glVertex2d(width+50,height/4);
	glVertex2d(width+50,height/4);
	glVertex2d(width,height/4);
	glVertex2d(width,height/4);
	glVertex2d(width,-50);

	////////Top Left////////////
	glVertex2d(-50,height*3/4);
	glVertex2d(-50,height+50);
	glVertex2d(-50,height+50);
	glVertex2d(0,height+50);
	glVertex2d(0,height+50);
	glVertex2d(0,height*3/4);
	glVertex2d(0,height*3/4);
	glVertex2d(-50,height*3/4);

	//////////Top///////////
	glVertex2d(0,height);
	glVertex2d(0,height+50);
	glVertex2d(0,height+50);
	glVertex2d(width,height+50);
	glVertex2d(width,height+50);
	glVertex2d(width,height);
	glVertex2d(width,height);
	glVertex2d(0,height);

	///////////Top Right/////////
	glVertex2d(width,height+50);
	glVertex2d(width+50,height+50);
	glVertex2d(width+50,height+50);
	glVertex2d(width+50,height*3/4);
	glVertex2d(width+50,height*3/4);
	glVertex2d(width,height*3/4);
	glVertex2d(width,height*3/4);
	glVertex2d(width,height+50);

	glEnd();
}

void drawLowerBlock(int width,int height)
{
	int x,y;

	glColor3ub(102,51,0);

	///////////Bottom Left Piece///////////
	glBegin(GL_POLYGON);
	glVertex2d(-50,-50);
	glVertex2d(-50,height/4);
	glVertex2d(0,height/4);
	glVertex2d(0,-50);
	glEnd();

	//////////Bottom Piece/////////////
	glBegin(GL_POLYGON);
	glVertex2d(0,0);
	glVertex2d(0,-50);
	glVertex2d(width,-50);
	glVertex2d(width,0);
	glEnd();

	////////////Bottom right piece///////////
	glBegin(GL_POLYGON);
	glVertex2d(width,-50);
	glVertex2d(width+50,-50);
	glVertex2d(width+50,height/4);
	glVertex2d(width,height/4);
	glEnd();

	glColor4ub(0,0,0,150);

	/////////Bottom left bricks///////////
	glBegin(GL_LINES);
	glVertex2d(-25,-50);
	glVertex2d(-25,height/4);
	glEnd();
	for(y=height*1/4;y>-50;y-=50)
	{
		glBegin(GL_LINES);
		glVertex2d(-25,y);
		glVertex2d(0,y);
		glEnd();
	}

	for(y=height*1/4-30;y>-50;y-=50)
	{
		glBegin(GL_LINES);
		glVertex2d(-25,y);
		glVertex2d(-50,y);
		glEnd();
	}

	/////////////Bottom Right bricks//////////
	glBegin(GL_LINES);
	glVertex2d(width+25,-50);
	glVertex2d(width+25,height/4);
	glEnd();
	for(y=height*1/4;y>-50;y-=50)
	{
		glBegin(GL_LINES);
		glVertex2d(width,y);
		glVertex2d(width+25,y);
		glEnd();
	}

	for(y=height*1/4-10;y>-50;y-=50)
	{
		glBegin(GL_LINES);
		glVertex2d(width+25,y);
		glVertex2d(width+50,y);
		glEnd();
	}

	/////////////Bottom Piece////////////
	glBegin(GL_LINES);
	glVertex2d(0,-25);
	glVertex2d(width,-25);
	glEnd();
	for(x=0;x<width;x+=50)
	{
		glBegin(GL_LINES);
		glVertex2d(x,0);
		glVertex2d(x,-25);
		glEnd();
	}

	for(x=-20;x<width;x+=50)
	{
		glBegin(GL_LINES);
		glVertex2d(x,-50);
		glVertex2d(x,-25);
		glEnd();
	}

}

void drawNet(int width,int height)
{
	int x,y;	
	glLineWidth(2);

	glColor3ub(100,100,100);
	for(x=-width/2;x<=width/2;x+=width/10)
	{
		glBegin(GL_LINES);
		glVertex2d(x,-height/2);
		glVertex2d(x,height/2);
		glEnd();
	}

	for(y=-height/2;y<=height/2;y+=height/10)
	{
		glBegin(GL_LINES);
		glVertex2d(-width/2,y);
		glVertex2d(width/2,y);
		glEnd();
	}
}

void drawBoundary(int width,int height)
{
	static a=0;

	////////////////Net////////////////
	glColor3ub(100,100,0);

	glPushMatrix();
	glTranslated(-25,height/2,0);
	drawNet(50,height/2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(25+width,height/2,0);
	drawNet(50,height/2);
	glPopMatrix();

	/////////////////////Upper Boundary////////////////
	drawUpperBlock(width,height);

	////////////////////Lower Boundary/////////////////
	drawLowerBlock(width,height);

	///////Outline//////////
	drawOutline();
	
}


void drawComponents()
{
	glColor3ub(255,162,0);

	glLineWidth(10);

	glBegin(GL_LINES);
	glVertex2d(width/2,height);
	glVertex2d(width/2,0);
	glEnd();

	glPointSize(7);
	drawCircle(width/2,height/2,height/4);

	drawCircle(width+10,height/2,height/3);
	drawCircle(-10,height/2,height/3);

}

void drawTexture()
{
	/*int x,y;
	for(x=width/2)*/
}

void calcScore()
{
	char score[7];
	glColor3ub(153,76,0);
	glBegin(GL_POLYGON);
	glVertex2d(width/2-150,height+100);
	glVertex2d(width/2+150,height+100);
	glVertex2d(width/2+150,height);
	glVertex2d(width/2-150,height);
	glEnd();

	glLineWidth(5);
	glColor4ub(0,0,0,200);
	/////////Boundarys///////
	glBegin(GL_LINES);
	glVertex2d(width/2-150,height+100);
	glVertex2d(width/2+150,height+100);
	glVertex2d(width/2+150,height+100);
	glVertex2d(width/2+150,height);
	glVertex2d(width/2+150,height);
	glVertex2d(width/2-150,height);
	glVertex2d(width/2-150,height);
	glVertex2d(width/2-150,height+100);
	glEnd();

	/////////Inner Boundarys//////////
	glBegin(GL_LINES);
	/////////Inner Boxes////////
	glVertex2d(width/2-100,height+75);
	glVertex2d(width/2+100,height+75);
	glVertex2d(width/2+100,height+75);
	glVertex2d(width/2+100,height+25);
	glVertex2d(width/2+100,height+25);
	glVertex2d(width/2-100,height+25);
	glVertex2d(width/2-100,height+25);
	glVertex2d(width/2-100,height+75);

	/////////Connecting Lines////////////
	glVertex2d(width/2-100,height+75);
	glVertex2d(width/2-150,height+100);
	glVertex2d(width/2+100,height+75);
	glVertex2d(width/2+150,height+100);
	glVertex2d(width/2+100,height+25);
	glVertex2d(width/2+150,height);
	glVertex2d(width/2-100,height+25);
	glVertex2d(width/2-150,height);
	glEnd();

	///////////Textures/////////
	//drawTexture();

	if(x[0]-radius>=width)
	{
		scoreLeft++;
	}
	if(x[0]+radius<=0)
		scoreRight++;
	
	score[0]=(char)(48+scoreLeft);
	score[1]=' ';
	score[2]='-';
	score[3]=' ';
	score[4]=(char)(48+scoreRight);
	score[5]='\0';

	glColor4ub(0,0,0,175);
	glLineWidth(5);
	glPointSize(2);
	glPushMatrix();
	glTranslated(455,height+40,0);
	glScalef(0.2,0.25,0);
    strokeString(score);
    glPopMatrix();
}

void drawArrow()
{
	glBegin(GL_POLYGON);
	glVertex2d(0,0);
	glVertex2d(100,0);
	glVertex2d(100,30);
	glVertex2d(0,30);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2d(0,-15);
	glVertex2d(-40,15);
	glVertex2d(0,45);
	glEnd();
}