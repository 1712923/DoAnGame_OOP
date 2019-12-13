

#include "Paddle.h"
#include "Ball.h"

Paddle::Paddle()
{
	x = 0;
	y = 0;
}

Paddle::Paddle(int pX, int pY)
{
	oX = pX;
	oY = pY;
	x = pX;
	y = pY;
}

Paddle::~Paddle()
{
}

void Paddle::reset()
{
	x = oX;
	y = oY;
}

int Paddle::getX()
{
	return x;
}

int Paddle::getY()
{
	return y;
}

void Paddle::set_y(int Y)
{
	y = Y;
}

void Paddle::set_x(int X)
{
	x = X;
}

void Paddle::MoveUp()
{
	y--;
}

void Paddle::MoveDown()
{
	y++;
}

ostream& operator<<(ostream& os, Paddle p)
{
	os << "Paddle (" << p.x << "," << p.y << ")" << endl;
	return os;
}
