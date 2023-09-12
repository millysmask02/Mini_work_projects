#include "SolarSystem.h"

SolarSystem::SolarSystem(std::vector<Planet> planets) {
	this->planets = planets;
}

void SolarSystem::addPlanet(Planet planet) {
	planets.push_back(planet);
}

SolarSystem::~SolarSystem() {
	planets.clear();
}
