#include "ScoreTable.h"

ScoreTable::ScoreTable(std::string fontPath) {
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Eror: Load font from file\n";
    }
    setFont(font);
}

void ScoreTable::inc() {
    ++score;
}

uint32_t ScoreTable::getScore() {
    return score;
}