#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Planet : public sf::CircleShape
{
public:
	Planet(sf::Vector2f, float, float, float, std::string);

	void setAngularVelocity(float);

private:
	friend class Engine;
	sf::Texture texture;
	sf::Vector2f centerOrbitPosition;
	float orbitRadius = 0.0f;
	float angularVelocity = 0.0f;
	float currentAngle = 0.0f;
};