#include "Ball.h"


cBall::cBall (int posX, int posY) // ham constructor
{
	originalX = posX;
	originalY = posY;
	x = posX; y = posY;
	direction = STOP;
}
void cBall::Reset() // ham reset ve vi tri ban dau cua bong
{
	x = originalX; 
	y = originalY;
	direction = STOP;
}
void cBall::changeDirection(eDir d) // ham thay doi huong di cua bong
{
	direction = d;
}
void cBall::randomDirection() // ham tao huong di ngau nhien cua bong
{
	direction = (eDir)((rand() % 6) + 1); //random tu 1 den 6 vi tri
}

//ham get vi tri

int cBall::getX() 
{
	return x;
}

int cBall::getY()
{
	return y; 
}

eDir cBall::getDirection() 
{
	return direction; 
}

void cBall::Move() //ham di chuyen bong
{
	switch (direction)
	{
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UPLEFT:
		x--; y--;
		break;
	case DOWNLEFT:
		x--; y++;
		break;
	case UPRIGHT:
		x++; y--;
		break;
	case DOWNRIGHT:
		x++; y++;
		break;
	default:
		break;
	}
}




