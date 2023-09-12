#pragma once
#include <iostream>
#include <SFML/Graphics/Text.hpp>

class ScoreTable : public sf::Text
{
public:
	ScoreTable(std::string);

	uint32_t getScore();
	int getLevel();

	void inc();
	void increaseLevel();

	~ScoreTable() = default;

private:
	sf::Font font;
	uint32_t score = 0;
	int level = 1;
};
