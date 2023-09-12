#include <iostream>
#include <SFML/Graphics.hpp>
#include "ClickBtn.h"
#include "ScoreTable.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(500, 500), "My Clicker");
    Font font;
    if (!font.loadFromFile("calibri.ttf")) {
        std::cout << "error load font" << std::endl;
        return -1;
    }

    Texture texture;
    if (!texture.loadFromFile("kyky.jpg")) {
        std::cout << "error load texture" << std::endl;
        return -1;
    }

    Texture texture1;
    if (!texture1.loadFromFile("logo.jpg")) {
        std::cout << "error load texture" << std::endl;
        return -1;
    }


    ClickBtn btn(window);
    btn.setTexture(&texture);
    
    ScoreTable info("calibri.ttf");
    info.setCharacterSize(40);
    info.setFillColor(Color::Black);
    info.setPosition(10, 10);

    int cost = 25;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed &&
                event.mouseButton.button == Mouse::Left) {
                if (btn.getDistance(window) <= btn.getRadius()) {
                    info.inc();
                    btn.setPosition(rand() % 300 + 100, rand() % 300 + 100);
                }
            }
        }

        if (info.getScore() >= cost * info.getLevel()) {
            info.dec(cost * info.getLevel());
            info.incLevel();
        }

        if (info.getLevel() == 10) {
            btn.setTexture(&texture1);
        }

        window.clear(Color::White);
        std::string str = "Score: " + std::to_string(info.getScore()) + 
            "     Level: " + std::to_string(info.getLevel()) +
            "   price: " + std::to_string(cost * info.getLevel());
        info.setString(str);
        window.draw(btn);
        window.draw(info);
        window.display();
    }
}