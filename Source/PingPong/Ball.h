#ifndef __BALL_H__
#define __BALL_H__
#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

//bang liet ke cho huong di cua bong ban
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

class cBall
{
private:
	int x, y; //vi tri cua bóng
	int originalX, originalY; //vi tri ban dau cua bong
	eDir direction;
public:
	cBall(int posX, int posY);
	void Reset();
	void changeDirection(eDir d);
	void randomDirection();
	int getX();
	int getY();
	eDir getDirection();
	void Move();
};

#endif