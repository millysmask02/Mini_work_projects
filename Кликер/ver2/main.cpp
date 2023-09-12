#include <SFML/Graphics.hpp>
#include "ClickBtn.h"
#include "ScoreTable.h"
#include <iostream>
#include <vector>

/*
2 - 25
3 - 50
4 - 100
5 - 200
*/

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(500, 500), "Clicker", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("calibri.ttf")) {
        return -1;
    }

    sf::Texture btnTexture;
    if (!btnTexture.loadFromFile("logo.jpg")) {
        return -1;
    }

    sf::Texture catTexture;
    if (!catTexture.loadFromFile("cat.jpg")) {
        return -1;
    }

    std::vector<sf::Texture> textures;
    textures.push_back(btnTexture);
    textures.push_back(catTexture);


    ClickBtn clickBtn(window);
    clickBtn.setTexture(&btnTexture);
    clickBtn.setOutlineThickness(2);
    clickBtn.setOutlineColor(sf::Color(0, 0, 0));

    ScoreTable scoreTable("calibri.ttf");

    scoreTable.setCharacterSize(40);
    scoreTable.setFillColor(sf::Color::Black);
    scoreTable.setPosition(10, 10);

    int nextScore = 25;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (clickBtn.getK(window) <= clickBtn.getRadius())
                {
                    scoreTable.inc();
                    clickBtn.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
                }
            }
        }

        if (nextScore < scoreTable.getScore()) {
            scoreTable.increaseLevel();
            nextScore *= 2;
            clickBtn.nextLevel(scoreTable.getLevel());
            clickBtn.setTexture(&textures[scoreTable.getLevel() % 2]);
        }

        std::string str = "Score: " + std::to_string(scoreTable.getScore());
        str += "      Level: " + std::to_string(scoreTable.getLevel());
        window.clear(sf::Color::White);
        scoreTable.setString(str);
        window.draw(clickBtn);
        window.draw(scoreTable);

        window.display();
    }

    return 0;
}
