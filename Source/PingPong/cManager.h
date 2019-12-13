#ifndef __CMANAGER_H__
#define __CMANAGER_H__
#include "Ball.h"
#include "Paddle.h"
#include <windows.h>

class cGameManager
{
private:
	int width, height; // chieu rong va chieu cao
	int score1, score2;  // diem nguoi choi
	int paddleLength;
	char up1, down1, up2, down2;
	bool quit;            // thoat game
	cBall * ball;
	cPaddle *player1;     // nguoi choi 1
	cPaddle *player2;     // nguoi choi 2

public:
	cGameManager(int w, int h);
	~cGameManager();
	void Restart();
	void ScoreUp(cPaddle * player);
	void Draw();
	void CheckInput1();
	void CheckInput2();
	void PrintUI(int);
	void Logic();
	void PrintResult(int);
	void Run1();
	void Run2();
};
//hàm hỗ trợ Menu lua chon nguoi choi
void Menu();
int Chon();

// hàm hỗ trợ cho background
void SetConsoleSize(int width, int height);
void removeCursor();
void gotoxy(int x, int y);
void TextColor(int x);
void WindowInit();


#endif