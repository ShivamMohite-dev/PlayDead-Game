#pragma once
#include<SFML/Graphics.hpp>
class MathLogic{
public:
	static sf::Vector2f normalize(sf::Vector2f vector);
	static bool checkCollision(sf::FloatRect rect1, sf::FloatRect rect2);
};

