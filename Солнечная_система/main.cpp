#include "Engine.h"

#define SUN     1000
#define MERCURY 100
#define VENUS   150
#define EARTH   300
#define MARS    270
#define JUPITER 700
#define SATURN  700
#define URANUS  900
#define NEPTUNE 900
#define PLUTO   100

int main()
{
    const unsigned screen_size_w = 1920;
    const unsigned screen_size_h = 1080;

    const unsigned screen_center_w = screen_size_w / 2;
    const unsigned screen_center_h = screen_size_h / 2;

    Engine* engine = new Engine(screen_size_w, screen_size_h, "SolarSystem");
    SolarSystem solarSystem;

    Planet sun(sf::Vector2f(screen_center_w, screen_center_h), 0,
        SUN, 0, "planet/sun.png");
    Planet mercury(sf::Vector2f(screen_center_w, screen_center_h), 1700,
        MERCURY, 2.5, "planet/mercury.png");
    Planet venus(sf::Vector2f(screen_center_w, screen_center_h), 10600,
        VENUS, 1.25, "planet/venus.png");
    Planet eath(sf::Vector2f(screen_center_w, screen_center_h), 15500,
        EARTH, 0.7, "planet/earth.png");
    Planet mars(sf::Vector2f(screen_center_w, screen_center_h), 22500,
        MARS, 1, "planet/mars.png");
    Planet jupiter(sf::Vector2f(screen_center_w, screen_center_h), 25500,
        JUPITER, 0.5, "planet/jupiter.png");
    Planet saturn(sf::Vector2f(screen_center_w, screen_center_h), 30500,
        SATURN, 0.7, "planet/saturn.png");
    Planet uranus(sf::Vector2f(screen_center_w, screen_center_h), 40500,
        URANUS, 0.3, "planet/uranus.png");
    Planet neptune(sf::Vector2f(screen_center_w, screen_center_h), 47000,
        NEPTUNE, 0.2, "planet/neptune.png");
    Planet pluto(sf::Vector2f(screen_center_w, screen_center_h), 90000,
        PLUTO, 0.1, "planet/pluto.png");

    solarSystem.addPlanet(sun);
    solarSystem.addPlanet(mercury);
    solarSystem.addPlanet(venus);
    solarSystem.addPlanet(eath);
    solarSystem.addPlanet(mars);
    solarSystem.addPlanet(jupiter);
    solarSystem.addPlanet(saturn);
    solarSystem.addPlanet(uranus);
    solarSystem.addPlanet(neptune);
    solarSystem.addPlanet(pluto);

    engine->setSolarSystem(solarSystem);

    engine->run();

    delete engine;
}