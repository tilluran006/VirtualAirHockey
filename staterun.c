#include "game.h"

//////////////////STATES///////////

void stateRunning()
{
	char c;
	char score[7];
//	if(loopTime==0){
	glClear(GL_COLOR_BUFFER_BIT );
	glClearColor(0,0,0,0);

	drawRectangle(width,height);

	drawComponents();

	///////////////////for Ball///////////////////

	if(y[0]+radius>=500)
	{
    	speedy*=-1; 
    	y[0]=500-radius;
	}
	if(y[0]-radius<=0)
	{
		speedy*=-1; 
    	y[0]=radius;
	}

	if(x[0]-radius-5<=x[1] && x[0]+radius+5>=x[2] )
	{
		if((y[0]>=y[1]-height/10 && y[0]<=y[2]+height/10) || (y[0]>=y[2]-height/10 && y[0]<=y[1]+height/10))
		{
			x[1]=x[0]-2*radius;
			x[2]=x[0]+2*radius;
		}
	}

    if((x[0]-radius>x[1] && x[0]+speedx-radius<x[1]) || (x[0]+radius<x[1]-10 && x[0]+speedx+radius>x[1]-10))
	{
		yi=(speedy/speedx)*(x[1]-x[0])+y[0];
		xi=x[0];
		if(yi<y[1]+height/10 && yi>y[1]-height/10)
		{
			if(x[0]>x[1])
				x[0]=x[1]+radius;
			else
				x[0]=x[1]-radius;
			y[0]=(speedy/speedx)*(x[0]-xi)+y[0];
		}
	}

	if(y[0]-radius<=y[1]+height/10 && y[0]+radius>=y[1]-height/10){
    if((x[0]-radius<=x[1] && x[0]-radius>=x[1]-10))
    {
    	x[0]=x[1]+radius;
    	speedx=abs(speedx);
    	speedx+=xspeeder;
    	speedy+=yspeeder;    	
    }else if(x[0]+radius>=x[1]-10 && x[0]+radius<=x[1])
    {
    	x[0]=x[1]-radius-10;
    	speedx=abs(speedx)*-1;
    	speedx+=xspeeder;
    	speedy+=yspeeder;    	
    }
}
	if(x[0]<=x[1] && x[0]>=x[1]-10){
    if((y[0]-radius<=y[1]+height/10 && y[0]-radius>=y[1]))
    {
    	y[0]=y[1]+height/10+radius;
    	speedy=abs(speedy);
    	speedx+=xspeeder;
    	speedy+=yspeeder;    	
    }else if(y[0]+radius>=y[1]-height/10 && y[0]-radius<=y[1])
    {
    	y[0]=y[1]-height/10-radius;
    	speedy=abs(speedy)*-1;
    	speedx+=xspeeder;
    	speedy+=yspeeder;    	
    }
}

	if((x[0]-radius>x[2]+10 && x[0]+speedx-radius<x[2]+10) || (x[0]+radius<x[2] && x[0]+speedx+radius>x[2]))
	{
		yi=(speedy/speedx)*(x[2]-x[0])+y[0];
		xi=x[0];
		if(yi<y[2]+height/10 && yi>y[2]-height/10)
		{
			if(x[0]>x[2])
				x[0]=x[2]+radius+10;
			else
				x[0]=x[2]-radius;
			y[0]=(speedy/speedx)*(x[0]-xi)+y[0];
		}
	}

	if(y[0]-radius<=y[2]+height/10 && y[0]+radius>=y[2]-height/10){
    if((x[0]+radius>=x[2] && x[0]+radius<=x[2]+10))
    {
    	x[0]=x[2]-radius;
    	speedx=abs(speedx)*-1;
    	speedx+=xspeeder;
    	speedy+=yspeeder;
    	
    }else if(x[0]-radius<=x[2]+10 && x[0]-radius>=x[2])
    {
    	x[0]=x[2]+10+radius;
    	speedx=abs(speedx);
    	speedx+=xspeeder;
    	speedy+=yspeeder;

    }
}

if(x[0]>=x[2] && x[0]<=x[2]+10){
    if((y[0]-radius<=y[2]+height/10 && y[0]-radius>=y[2]))
    {
    	y[0]=y[2]+height/10+radius;
    	speedy=abs(speedy);
    	speedx+=xspeeder;
    	speedy+=yspeeder;    	
    }else if(y[0]+radius>=y[2]-height/10 && y[0]-radius<=y[2])
    {
    	y[0]=y[2]-height/10-radius;
    	speedy=abs(speedy)*-1;
    	speedx+=xspeeder;
    	speedy+=yspeeder;    	
    }
}

    x[0]=x[0]+speedx;
	y[0]=y[0]+speedy;	

	if(x[0]-radius<=0)
	{
		if((y[0]>=height*3/4 && y[0]<=height) || (y[0]<=height/4 && y[0]>=0))
		{
		speedx*=-1;
		x[0]=radius;
	}
	}

	if(x[0]-radius==0 && x[0]+radius>=x[1]-10)
	{
		if((y[0]>=y[1]-height/10 && y[0]<=y[1]+height/10))
		{
			x[1]=x[0]+3*radius;
		}
	}

	if(x[0]+radius>=width)
	{
		if((y[0]>=height*3/4 && y[0]<=height) || (y[0]<=height/4 && y[0]>=0))
		{
		speedx*=-1;
		x[0]=width-radius;
	}
	}

	if(x[0]+radius==width && x[0]-radius<=x[2]+10)
	{
		if((y[0]>=y[2]-height/10 && y[0]<=y[2]+height/10))
		{
			x[2]=x[0]-3*radius;
		}
	}

	drawBall(x[0],y[0],radius,radius);
   
	/////////////////for Block 1///////////////////////

	if(x[1]<500 && x[1]-10>0){
	if(y[1]+height/10<500 && y[1]-height/10>0)
	{
	if(up[0]==1)
	{
		y[1]+=5;
		yspeeder+=0.1;
    }
    if(down[0]==1)
    {
    	y[1]-=5;
    	yspeeder-=0.1;
    }
    if(left[0]==1)
    {
    	x[1]-=5;
    	xspeeder-=0.1;
    }
    if(right[0]==1)
    {
    	x[1]+=5;
    	xspeeder+=0.1;
    }
}else {
	if(y[1]+height/10>=500)
		y[1]-=6;
	else if(y[1]-height/10<=0)
		y[1]+=6;
}
}else{
	if(x[1]>=500)
		x[1]-=6;
	else if(x[1]-10<=0)
		x[1]+=6;
	
}
    drawLeftBlock(x[1],y[1],height);

    /////////////////////for block 2//////////////////

   if(x[2]+10<1000 && x[2]>500){
	if(y[2]+height/10<500 && y[2]-height/10>0)
	{
	if(up[1]==1)
	{
		y[2]+=5;
		yspeeder+=0.1;
    }
    if(down[1]==1)
    {
    	y[2]-=5;
    	yspeeder-=0.1;
    }
    if(left[1]==1)
    {
    	x[2]-=5;;
    	xspeeder-=0.1;
    }
    if(right[1]==1)
    {
    	x[2]+=5;
    	xspeeder+=0.1;
    }
}else {
	if(y[2]+height/10>=500)
		y[2]-=6;
	else if(y[2]-height/10<=0)
		y[2]+=6;
}
}else{
	if(x[2]<=500)
		x[2]+=6;
	else if(x[2]>=990)
		x[2]-=6;
	
}
	drawRightBlock(x[2],y[2],height); 

	drawBoundary(width,height); 
	
	calcScore();

	loopTime++;	
}