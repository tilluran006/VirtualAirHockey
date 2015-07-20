#include "game.h"

void stateOut()
{
	if(x[0]-radius>=width)
	{
		x[0]=3*width/4;
		y[0]=height/2;
		speedx=0;
		speedy=0;
	}
	if(x[0]+radius<=0)
	{
	    x[0]=width/4;
		y[0]=height/2;
		speedx=0;
		speedy=0;
	}
}
