#pragma once

#include <iostream>
using namespace std;

class Paddle
{
protected:
	int x, y;
	int  oX, oY;
public:
	Paddle();// Constructor for Paddle without variable
	Paddle(int, int); // Constructor for Paddle
	~Paddle(); // Destructor for Paddle

	void reset();// Khởi tạo lại giá trị cho Paddle
	int getX(); // Lấy toạ độ x của Paddle ra ngoài
	int getY(); // Lấy toạ độ y của Paddle ra ngoài
	void set_y(int Y);
	void set_x(int X);
	void MoveUp();// Dịch chuyển Paddle lên 1 đơn vị
	void MoveDown();// Dịch chuyển Paddle xuống 1 đơn vị
	friend ostream& operator <<(ostream& os, Paddle p);// Toán tử xuất cho Paddle
};

