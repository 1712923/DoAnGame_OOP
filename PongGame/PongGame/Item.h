#pragma once
#pragma once
#include "Ball.h"
#include "Paddle.h"

#include <stdlib.h>
#include <time.h>

class Item
{
private:
	int x, y;
	char shapeItem; //hinh dang cua vat pham

	bool isExistent = true;//flag vat pham con ton tai
	int type;

public:
	Item();
	Item(int x, int y);
	void createArrayItems();
	Item* createItems(int x, int y);
	void deleteItems();

	~Item();
};

