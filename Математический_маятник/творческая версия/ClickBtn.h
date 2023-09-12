#pragma once
#include <SFML/Graphics.hpp>

class ClickBtn : public sf::CircleShape {
public:
	ClickBtn(const sf::RenderWindow& window, int size = 100);
	double getDistance(const sf::RenderWindow& window);
	~ClickBtn() = default;

private:
	int score;
	int size;
};

