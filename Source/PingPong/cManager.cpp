#include"cManager.h"

void SetConsoleSize(int width, int height) // thiết lập kích thước màn hình Console
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void removeCursor() // loại bỏ con trỏ chuột
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void gotoxy(int x, int y) // đi đến vị trí xy
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}

void TextColor(int x) // màu chữ
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void WindowInit()  //thiết lập màn hình Window
{
	SetConsoleSize(800, 480);
	removeCursor();
}

// quan ly luat choi, diem so
cGameManager::cGameManager(int w, int h)
{
	srand((unsigned int)time(NULL)); // thoi gian ngau nhien
	quit = false;
	up1 = 'w'; up2 = 'i'; // phim tat w cho up player 1, i cho up player 2
	down1 = 's'; down2 = 'k'; //phim  tat s cho down player 1, k cho down player 2
	score1 = score2 = 0;   // set diem ca 2 player = 0
	width = w; height = h;
	paddleLength = 6;
	ball = new cBall(w / 2, h / 2);  //dat Ball o chinh giua ban
	player1 = new cPaddle(1, h / 2 - 3); //dat vi tri ban dau cua vot player 1
	player2 = new cPaddle(w - 2, h / 2 - 3); //dat vi tri ban dau cua vot player 2
}

cGameManager::~cGameManager()
{
	delete ball, player1, player2;
}
void cGameManager::Restart()  //khởi động lại màn chơi
{
	system("cls");
	ball->Reset();
	player1->Reset();
	player2->Reset();
	TextColor(0);
	Draw();

}
//ham tinh diem
void cGameManager::ScoreUp(cPaddle * player)
{
	if (player == player1)
		score1++;
	else if (player == player2)
		score2++;

	//tro ve vi tri mac dinh
	ball->Reset();
	player1->Reset();
	player2->Reset();
}

//ve vi tri cho bong va vot
void cGameManager::Draw()
{
	gotoxy(0, 0);

	TextColor(11);
	// tao khung tro choi
	for (int i = 0; i < width + 2; i++)
		cout << "\xB2";
	TextColor(0);
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{

			// lay toa do cua ball va player
			int ballx = ball->getX();
			int bally = ball->getY();
			int player1x = player1->getX();
			int player2x = player2->getX();
			int player1y = player1->getY();
			int player2y = player2->getY();


			if (j == 0)
			{
				TextColor(11);
				cout << "\xB2"; //ve khung bong ban ben trai
				TextColor(0);
			}

			if (ballx == j && bally == i)
			{
				TextColor(11);
				cout << "O"; //ball   #ve vi tri bong
				TextColor(0);
			}
			else if (j == player1x && i >= player1y && i <= player1y + paddleLength - 1)
			{
				TextColor(11);
				cout << "\xDB"; //player1    //ve vi tri nguoi choi 1
				TextColor(0);
			}

			else if (j == player2x && i >= player2y && i <= player2y + paddleLength - 1)
			{
				TextColor(11);
				cout << "\xDB"; //player2    //ve vi tri nguoi choi 2
				TextColor(0);
			}


			else
				cout << " ";

			if (j == width - 1)  //ve khung bong ban ben phai
			{
				TextColor(11);
				cout << "\xB2"; //ve khung bong ban ben trai
				TextColor(0);
			}
		}
		cout << endl;
	}

	TextColor(11);
	for (int i = 0; i < width + 2; i++)
		cout << "\xB2";
	TextColor(0);
	cout << endl;

}

void  cGameManager::CheckInput1() //người với người
{
	ball->Move(); //di chuyen bong

	// lay toa do cua ball va player
	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player2x = player2->getX();
	int player1y = player1->getY();
	int player2y = player2->getY();

	if (_kbhit())
	{
		char current = _getch(); //nhan du lieu 
		if (current == up1)
		if (player1y > 0)
			player1->moveUp(); //neu player1y >0 thi co the MoveUp

		if (current == up2)
		if (player2y > 0)
			player2->moveUp();

		if (current == down1)
		if (player1y + paddleLength - 1  < height - 1)
			player1->moveDown();

		if (current == down2)
		if (player2y + paddleLength - 1  < height - 1)
			player2->moveDown();

		if (ball->getDirection() == STOP) //neu ball dung lai thi tao vi tri ngau nhien cho ball
			ball->randomDirection();

		if (current == 'q') //quit game
			quit = true;
	}

}

void  cGameManager::CheckInput2() //người vs máy
{
	ball->Move(); //di chuyen bong

	// lay toa do cua ball va player
	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player2x = player2->getX();
	int player1y = player1->getY();
	int player2y = player2->getY();

	if (_kbhit())
	{

		char current = _getch(); //nhan du lieu 
		if (current == up1)
		if (player1y > 0)
			player1->moveUp(); //neu player1y >0 thi co the MoveUp

		if (current == down1)
		if (player1y + paddleLength - 1  < height - 1)
			player1->moveDown();

		if (current == 'q')
			quit = true;

	}

	if (ball->getDirection() == STOP)
		ball->randomDirection();

	int computerActive = rand() % 5;
	if (computerActive > 0)
	{
		if (ball->getDirection() == RIGHT)
		{
			if (bally > player2y + paddleLength - 1)
			{
				if (player2y + paddleLength - 1 < height - 1)
					player2->moveDown();
			}
			else if (bally < player2y)
			{
				if (player2y > 0)
					player2->moveUp();
			}
		}

		if (ball->getDirection() == DOWNRIGHT && bally > player2y + paddleLength - 1)
		{
			if (player2y + paddleLength - 1 < height - 1)
				player2->moveDown();
		}
		if (ball->getDirection() == UPRIGHT && bally < player2y)
		{
			if (player2y > 0)
				player2->moveUp();
		}
	}
}

void  cGameManager::PrintUI(int choose) //in màn hình kết quả
{
	TextColor(10);
	gotoxy(width + 5, 5);
	cout << "Player 1 's score: " << score1;
	TextColor(11);
	gotoxy(width + 5, 6);
	if (choose == 1)
		cout << "Player 2 's score: " << score2;
	else
		cout << "Computer's score: " << score2;

	TextColor(12);
	gotoxy(width + 5, 8);
	cout << "Press Q key to quit game";

	gotoxy(width / 2 - 7, height + 3);
	TextColor(10); cout << "PING"; TextColor(11); cout << " PONG"; TextColor(12); cout << " GAME";
	gotoxy(width / 2 - 8, height + 4);

}

void cGameManager::PrintResult(int choose)  //in kết quả sau khi chiến thắng
{
	
	//Win-Lose
	if (score1 == 5)
	{
		system("cls");
		cout << "Player 1 WIN!!" << endl;
		system("pause");
		quit = true;
	}
	else if (score2 == 5)
	{
		system("cls");
		if (choose == 1)
			cout << "Player 2 WIN!!" << endl;
		else
			cout << "Computer WIN!!" << endl;
		system("pause");
		quit = true;
	}
}

//ham va cham bong
void cGameManager::Logic()
{
	// lay toa do cua ball va player
	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player2x = player2->getX();
	int player1y = player1->getY();
	int player2y = player2->getY();

	//left paddle
	for (int i = 0; i < 6; i++)
	if (ballx == player1x + 1)   //neu ball canh benh player1
	if (bally == player1y + i)
		ball->changeDirection((eDir)((rand() % 3) + 4)); //chuyen huong bong sang vi tri ngau nhien qua phai

	//right paddle
	for (int i = 0; i < 6; i++)
	if (ballx == player2x - 1)
	if (bally == player2y + i)
		ball->changeDirection((eDir)((rand() % 3) + 1)); //chuyen huong bong sang vi tri ngau nhien qua trai

	//bottom wall
	if (bally == height - 1)
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
	//top wall
	else if (bally == 0)
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
	//right wall
	if (ballx == width - 1)
		ScoreUp(player1);
	//left wall
	else if (ballx == 0)
		ScoreUp(player2);

}

void Menu()
{
	system("cls");
	cout << "======================= MENU =====================\n\n";
	cout << " 1. Human vs Human" << endl;
	cout << " 2. Human vs Computer" << endl;
	cout << "==================================================\n";
}

int Chon()
{
	int lenh;

	cout << "\n Nhap lua chon cua ban: ";
	cin >> lenh;
	if (lenh < 1 || lenh > 2)
	{
		cout << "\nLua chon khong hop le. Xin kiem tra lai !\n";
		system("pause");
		exit(0);
	}
	return lenh;
}

void cGameManager::Run1()  //Run màn chơi người với người
{
	
	Draw();
	PrintUI(1);

	while (!quit)
	{
		srand((unsigned int)time(NULL));
		CheckInput1();
		Logic();
		Draw();
		PrintUI(1);
		PrintResult(1);
	}
	
}

void cGameManager::Run2()  //Run màn chơi người với máy
{
	Draw();
	PrintUI(2);
	while (!quit)
	{
		srand((unsigned int)time(NULL));
		CheckInput2();
		Logic();
		Draw();
		PrintUI(2);
		PrintResult(2);
	}
}

