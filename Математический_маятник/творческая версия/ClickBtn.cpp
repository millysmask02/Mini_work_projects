#include "ClickBtn.h"

ClickBtn::ClickBtn(const sf::RenderWindow& window, int size) {
	this->size = size;
	setRadius(size);
	setOrigin(size, size);
	setPosition(window.getSize().x / 2, window.getSize().y / 2);
}

double ClickBtn::getDistance(const sf::RenderWindow& window) {
	double mouseX = sf::Mouse::getPosition(window).x;
	double mouseY = sf::Mouse::getPosition(window).y;
	double circleX = getPosition().x;
	double circleY = getPosition().y;

	return std::sqrt(std::pow(mouseX - circleX, 2) + std::pow(mouseY - circleY, 2));
}

