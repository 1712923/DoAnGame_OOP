#include "Manger.h"
#include "console.h"
#include <Windows.h>

Manger::Manger(int w, int h)
{
	quit = 0;
	up1 = 'w';// Nút để thanh 1 tiến lên trên
	up2 = 'p';// Nút để thanh 2 tiến lên trên
	down1 = 's';// Nút để thanh 1 lùi xuống dưới
	down2 = 'l';// Nút để thanh 2 lùi xuống dưới
	score1 = 0;
	score2 = 0;
	width = w;
	heigth = h;
	ball = new Ball(w / 2, h / 2);
	player1 = new Paddle(1, h / 2 - 3);
	player2 = new Paddle(w - 2, h / 2 - 3);
}

Manger::~Manger()
{
	delete ball;
	delete player1;
	delete player2;
}

void Manger::scoreUp(Paddle* p)
{
	if (p == player1)
	{
		score1++;
	}
	else if (p == player2)
	{
		score2++;
	}
	ball->reset();
	player1->reset();
	player2->reset();
}

void Manger::draw()
{
	gotoXY(0, 1);

	TextColor(6);
	for (int i = 0; i < width + 2; i++)
	{
		cout << "\xB1";
	}
	cout << endl;

	for (int i = 0; i < heigth; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int x = ball->getX();
			int y = ball->getY();
			int x1 = player1->getX();
			int y1 = player1->getY();
			int x2 = player2->getX();
			int y2 = player2->getY();

			if (j == 0)
				cout << "\xB2";

			if ((x == j) && (y == i))
			{
				TextColor(15);
				cout << "\x4F";
				TextColor(6);
			}

			else if (x1 == j && y1 == i)
			{
				TextColor(5);
				cout << "\xB2";
				TextColor(6);
			}
			else if (x2 == j && y2 == i)
			{
				TextColor(5);
				cout << "\xB2";
				TextColor(6);
			}
			else if (x2 == j && y2 + 1 == i)
			{
				TextColor(5);
				cout << "\xB2";
				TextColor(6);
			}
			else if (x2 == j && y2 + 2 == i)
			{
				TextColor(5);
				cout << "\xB2";
				TextColor(6);
			}
			else if (x2 == j && y2 + 3 == i)
			{
				TextColor(5);
				cout << "\xB2";
				TextColor(6);
			}
			else if (x1 == j && y1 + 1 == i)
			{
				TextColor(5);
				cout << "\xB2";
				TextColor(6);
			}
			else if (x1 == j && y1 + 2 == i)
			{
				TextColor(5);
				cout << "\xB2";
				TextColor(6);
			}
			else if (x1 == j && y1 + 3 == i)
			{
				TextColor(5);
				cout << "\xB2";
				TextColor(6);
			}
			else cout << " ";

			if (j == width - 1)
			{
				cout << "\xB2";
				TextColor(6);
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
	{
		cout << "\xB1";
	}
	cout << endl;
	TextColor(15);
	cout << "Press any key to Start" << endl;
	cout << "Press Q to Pause" << endl;
	gotoXY(10, 4);
	cout << score1;
	gotoXY(30, 4);
	cout << score2;
	gotoXY(43, 27);
}

void Manger::inPut()
{
	ball->move();

	int x = ball->getX();
	int y = ball->getY();
	int x1 = player1->getX();
	int y1 = player1->getY();
	int x2 = player2->getX();
	int y2 = player2->getY();

	if (_kbhit())
	{

		char curr = _getch();
		if (curr == up1)
			if (y1 > 0)	player1->MoveUp();
		if (curr == up2)
			if (y2 > 0)	player2->MoveUp();
		if (curr == down1)
			if (y1 + 4 < heigth) player1->MoveDown();
		if (curr == down2)
			if (y2 + 4 < heigth) player2->MoveDown();
		if (ball->getHuong() == stop)	ball->randomHuong();
		if (curr == 'q') quit = 1;
		if ((score1 == 5) || (score2 == 5))quit = 1;
	}
}

void Manger::loGic()
{
	int x = ball->getX();
	int y = ball->getY();
	int x1 = player1->getX();
	int y1 = player1->getY();
	int x2 = player2->getX();
	int y2 = player2->getY();

	//left paddle
	for (int i = 0; i < 4; i++)
		if (x == x1 + 1)
		{
			if (y == y1 + i)
			{
				ball->chuyenHuong(ball->getHuong() == downLeft ? downRight : upRight);
			}
		}

	//right paddle
	for (int i = 0; i < 4; i++)
		if (x == x2 - 1)
		{
			if (y == y2 + i)
			{
				ball->chuyenHuong(ball->getHuong() == downRight ? downLeft : upLeft);
			}
		}
	// bottom wall
	if (y == heigth - 1)
		ball->chuyenHuong(ball->getHuong() == downRight ? upRight : upLeft);

	// top wall
	if (y == 0)
		ball->chuyenHuong(ball->getHuong() == upRight ? downRight : downLeft);
	// right wall
	if (x == width - 1)	scoreUp(player1);

	// left wall
	if (x == 0)	scoreUp(player2);
}

void Manger::Run()
{

	printScreen();
	Print();
	while (!quit)
	{
		draw();
		inPut();
		loGic();
	}
	gotoXY(13, 10);
	TextColor(4);
	if (score1 > score2)
	{
		cout << "Player1 WIN the Game" << endl;
	}
	else if (score2 > score1)
	{
		cout << "Player2 WIN the Game" << endl;
	}
	gotoXY(43, 27);
}

void Manger::RunOne()
{
	printScreen();
	Print();
	while (!quit)
	{
		draw();
		inPutOne();
		loGic();
	}
	gotoXY(13, 10);
	TextColor(4);
	if (score1 > score2)
	{
		cout << "Computer WIN the Game" << endl;
	}
	else if (score2 > score1)
	{
		cout << "Player2 WIN the Game" << endl;
	}

	luuDiem(score2);
	ghiBangDiem();

	gotoXY(43, 27);
}

void Manger::inPutOne()
{
	ball->move();

	int x = ball->getX();
	int y = ball->getY();
	int x1 = player1->getX();
	int y1 = player1->getY();
	int x2 = player2->getX();
	int y2 = player2->getY();
	if ((ball->getY() <= 19) && (ball->getY() >= 3))
	{
		player1->set_y(ball->getY() - 3);
	}
	if (_kbhit())
	{

		char curr = _getch();

		if (curr == up2)
			if (y2 > 0)	player2->MoveUp();
		if (curr == down2)
			if (y2 + 4 < heigth) player2->MoveDown();
		if (ball->getHuong() == stop)	ball->randomHuong();
		if (curr == 'q') quit = 1;
		if (score1 == 5)quit = 1;
	}
}

void printScreen()
{
	TextColor(14);
	gotoXY(0, 1);
	for (int i = 0; i < 42; i++)
	{
		cout << "\xB1";
	}
	cout << endl;
	for (int i = 0; i < 19; i++)
	{
		cout << "\xB2                                        \xB2" << endl;
	}
	for (int i = 0; i < 42; i++)
	{
		cout << "\xB1";
	}
}

void Manger::luuDiem(int score) // luu diem
{
	bangDiem.push_back(score);
	sort(bangDiem.begin(), bangDiem.end());

	while (bangDiem.size() > 15)  //chi lay top 15 diem cao nhat
	{
		bangDiem.erase(bangDiem.begin());
	}
}

void Manger::ghiBangDiem()//ghi bang diem ra file
{
	ofstream fileout(bangThanhTich, ios::app);
	for (int i = bangDiem.size()-1; i >= 0; i--) 
	{
		int j = 1;
		fileout << bangDiem[i] << "\n";
		j++;
	}

	fileout.close();	
}


void Manger::hienBangThanhTich() //hien top diem cao ra man hinh
{
	vector<int> bangDiem;
	ifstream filein(bangThanhTich);
	int score;

	while (filein >> score)
	{
		bangDiem.push_back(score);
	}
	system("cls");

	cout << "Top Thanh Tich: " << endl;

	for (int i = 0; i < bangDiem.size(); i++) 
	{
		cout << bangDiem[i] << endl;
	}
	cout << endl;
	filein.close();
}


void Print()
{

}

void Project()
{
	TextColor(5);
	printScreen();
	gotoXY(8, 3);
	TextColor(1);
	cout << "<<<<<<<<PONG-GAME>>>>>>>>" << endl;
	gotoXY(1, 5);
	TextColor(2);
	cout << "----------------------------------------" << endl;
	gotoXY(11, 6);
	TextColor(3);
	cout << "Press 1 : One Player ";
	gotoXY(11, 8);
	cout << "Press 2 : Two Player ";
	gotoXY(1, 7);
	TextColor(2);
	cout << "----------------------------------------" << endl;
	gotoXY(1, 9);
	cout << "----------------------------------------" << endl;
	gotoXY(1, 11);
	cout << "----------------------------------------" << endl;
	gotoXY(11, 10);
	TextColor(3);
	cout << "Press 3 : Instruction";
	gotoXY(11, 12);
	TextColor(3);
	cout << "Press 4 : Bang Thanh Tich ";
	gotoXY(1, 13);
	TextColor(2);
	cout << "----------------------------------------" << endl;
	gotoXY(11, 14);
	TextColor(3);
	cout << "Press 0 : Quit Game ";
	TextColor(2);
	gotoXY(1, 15);
	cout << "----------------------------------------" << endl;
	gotoXY(12, 16);
	TextColor(4);
	cout << "Your Choice : ";
	gotoXY(26, 16);
	int n;
	cin >> n;
	TextColor(15);
	if (n == 0)
	{
		system("cls");
		printScreen();
		TextColor(4);
		gotoXY(13, 10);
		cout << "See you later !!!";
	}
	else if (n == 2)
	{
		Manger c(40, 20);
		Print();
		c.Run();
		system("pause");
		system("cls");
		Project();
	}
	else if (n == 1)
	{
		Manger c(40, 20);
		c.RunOne();
		system("pause");
		system("cls");
		Project();
	}
	else if (n == 3) {
		system("cls");
		printScreen();
		TextColor(2);
		gotoXY(15, 4);
		cout << "INSTRUCTION";
		TextColor(15);
		gotoXY(2, 7);
		cout << "Player1: W: up, S:down";
		gotoXY(2, 10);
		cout << "Player2: P: up, L:down";
		TextColor(6);
		gotoXY(2, 13);
		system("pause");
		system("cls");
		Project();
	}
	else if (n == 4)
	{
		system("cls");
		printScreen();
		Manger::hienBangThanhTich();
		system("pause");
		system("cls");
		Project();
	}
	else
	{
		Project();
	}
	gotoXY(43, 27);
	return;
}
