#include "ScoreTable.h"

ScoreTable::ScoreTable(std::string fontfile) {
	if (!font.loadFromFile(fontfile)) {
		std::cerr << "Error" << std::endl;
	}
	setFont(font);
}

int ScoreTable::getScore() {
	return score;
}

void ScoreTable::inc() {
	score += level;
}

int ScoreTable::getLevel() {
	return level;
}

void ScoreTable::incLevel() {
	level++;
}

void ScoreTable::dec(int price) {
	score -= price;
}