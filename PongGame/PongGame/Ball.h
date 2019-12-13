#pragma once

#include <iostream>

using namespace std;

enum dir { stop = 0, Left = 1, upLeft = 2, downLeft = 3, Right = 4, upRight = 5, downRight = 6 };// Sử dụng một số viết tắt để dễ thực hiện

class Ball
{
protected:
	int x, y;
	int oX, oY;
	dir huong;

public:
	Ball(int, int);// Constructor Ball
	~Ball();// Destructor Ball

	void reset(); // Khởi tạo lại giá trị cho toạ độ Ball
	void chuyenHuong(dir h);// Di chuyển Ball đến hướng h 
	void randomHuong();// Chọn ngẫu nhiên một h cho hàm chuyenhuong
	int getX();// Lấy giá trị biến x ra ngoài
	int getY();// Lấy giá trị biến y ra ngoài
	dir getHuong();// Lấy biến huong ra ngoài
	void move();// Thay đổi toạ độ của Ball
	friend ostream& operator <<(ostream& os, Ball b);// Toán tử nhập cho Ball
};

