#pragma once

#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

const string bangThanhTich = "BangThanhTich.txt";
class Manger
{
private:
	int width;
	int heigth;
	int score1;
	int score2;
	int quit;  //1:TRUE, 0:FALSE
	Ball* ball;
	Paddle* player1;
	Paddle* player2;
	char up1, up2, down1, down2;
	vector<int> bangDiem;

public:
	Manger(int, int); // Constructor for Manger
	~Manger();// Destructor for Manger
	void setScore1(int Score1)
	{
		this->score1 = Score1;
	}
	void setScore2(int Score2)
	{
		this->score2 = Score2;
	}
	void scoreUp(Paddle*);// Tăng điểm cho người chơi
	void draw(); // In ra màn hình các đối tượng 
	void inPut();// nhận các lệnh nhập từ bàn phím, xử lí chúng
	void loGic();// Di chuyển các Paddle và xử lí đụng tường
	void Run();// Chạy các lệnh thực thi
	void RunOne();//Chạy các lệnh thực thi trong chế độ 1 người chơi.
	void inPutOne();// nhận các lệnh nhập từ bàn phím, xử lí chúng trong chế độ 1 người chơi.
	void luuDiem(int score);//luu diem
	void ghiBangDiem(); //ghi bang diem ra file
	static void hienBangThanhTich();//hien bang diem ra man hinh

};

void printScreen();// In màn hình chơi game
void Print();
void Project();// Đồ án

