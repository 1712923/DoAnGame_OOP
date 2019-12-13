#include "Paddle.h"

//dieu khien vot bong ban
cPaddle::cPaddle()
{
	x = y = 0;
}
cPaddle::cPaddle(int posX, int posY) : cPaddle()
{
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
}
void cPaddle::Reset() 
{
	x = originalX; 
	y = originalY; 
} // ham reset ve vi tri ban dau cua vot

//ham get vi tri
int cPaddle::getX() 
{ 
	return x;
}
int cPaddle::getY() 
{
	return y;
}

//ham di chuyen len xuong cho vot
void cPaddle::moveUp() 
{
	y--;
}

void cPaddle::moveDown() 
{ 
	y++;
}

