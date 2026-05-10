#pragma once
#include <SFML/Graphics.hpp>
class fps
{
private:
	sf::Font fpsfont;
	sf::Text fpstext;
	float timer;
public:
	fps();
	~fps();
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};

