#include "Engine.h"

Engine::Engine(unsigned width, unsigned height, std::string window_name) {
    settings.antialiasingLevel = 8;
    view = new sf::View(sf::FloatRect(0, 0, width * 2, height * 2));
    window = new sf::RenderWindow(
        sf::VideoMode(width, height),
        window_name,
        sf::Style::Fullscreen,
        settings);

    view->setCenter(width / 2, height / 2);
    view->zoom(-100);
    window->setView(*view);
}

void Engine::run() {
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::MouseWheelMoved:
                if (event.mouseWheel.delta == 1)
                {
                    view->zoom(1.0f / gameZoom);
                    window->setView(*view);
                }
                if (event.mouseWheel.delta == -1)
                {
                    view->zoom(gameZoom);
                    window->setView(*view);
                }
                break;
            case sf::Event::Closed:
                window->close();
                break;
            default:
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

            view->move(100, 0);
            window->setView(*view);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

            view->move(-100, 0);
            window->setView(*view);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

            view->move(0, 100);
            window->setView(*view);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

            view->move(0, -100);
            window->setView(*view);
        }

        window->clear(sf::Color::Black);

        for (int i = 0; i < mSolarSystem.planets.size(); i++)
        {
            mSolarSystem.planets[i].currentAngle += mSolarSystem.planets[i].angularVelocity * dt.asSeconds();
            mSolarSystem.planets[i].setPosition(
                mSolarSystem.planets[i].centerOrbitPosition.x + mSolarSystem.planets[i].orbitRadius * cos(mSolarSystem.planets[i].currentAngle),
                mSolarSystem.planets[i].centerOrbitPosition.y + mSolarSystem.planets[i].orbitRadius * sin(mSolarSystem.planets[i].currentAngle)
            );
            window->draw(mSolarSystem.planets[i]);

        }
        window->display();
        dt = deltaClock.restart();
    }
}

void Engine::setSolarSystem(SolarSystem solarSystem) {
    mSolarSystem = solarSystem;
}

Engine::~Engine() {
    delete window;
    delete view;
}