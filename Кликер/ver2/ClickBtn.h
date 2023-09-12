#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>

class ClickBtn : public sf::CircleShape
{
public:
	ClickBtn(const sf::RenderWindow&, int size = 100);

	double getK(const sf::RenderWindow&);

	void nextLevel(int level);

	~ClickBtn() = default;

private:
	uint32_t score;
	uint32_t size;
	const uint32_t maxScrore = UINT32_MAX;
};
