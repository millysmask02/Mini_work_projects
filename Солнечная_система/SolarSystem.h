#pragma once
#include "Planet.h"
#include <vector>

class SolarSystem
{
public:
	SolarSystem() = default;
	SolarSystem(std::vector<Planet>);

	void addPlanet(Planet);

	~SolarSystem();

private:
	friend class Engine;
	std::vector<Planet> planets;
};