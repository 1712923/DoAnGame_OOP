#pragma once
#include <SFML\Graphics.hpp>

//vật phẩm
class PowerUp : public sf::RectangleShape
{
public:
	PowerUp();
	~PowerUp();

	
	void fallDown(double);
	void draw(sf::RenderWindow & theWindow, double);
	void setPower(int);

private:
	int itsPower;
};

