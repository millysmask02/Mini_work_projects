#pragma once
#include "SolarSystem.h"

class Engine
{
public:
	Engine(unsigned, unsigned, std::string);

	void run();
	void setSolarSystem(SolarSystem);

	~Engine();

private:
	const float gameZoom = 1.02f;
	sf::Clock deltaClock;
	sf::Time dt;
	sf::ContextSettings settings;
	sf::RenderWindow* window;
	sf::View* view;
	sf::Event event;
	SolarSystem mSolarSystem;
};

