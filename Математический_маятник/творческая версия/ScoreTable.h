#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ScoreTable : public sf::Text
{
public:
	ScoreTable(std::string fontfile);
	int getScore();
	void inc();
	void dec(int price);

	int getLevel();
	void incLevel();

private:
	sf::Font font;
	int score = 0;
	int level = 1;
};

