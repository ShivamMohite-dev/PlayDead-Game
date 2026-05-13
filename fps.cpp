#include "fps.h"
#include<iostream>
fps::fps():timer(0){}
fps::~fps(){}
void fps::Initialize(){}
void fps::Load(){
	if (fpsfont.loadFromFile("Assets/Fonts/Graduate-Regular.ttf")) {
		fpstext.setFont(fpsfont);
		fpstext.setCharacterSize(20);
		fpstext.setFillColor(sf::Color::Black);
		fpstext.setPosition(sf::Vector2f(10,10));
	}
	else {
		std::cout << "Font: Graduate.ttf failed to load!" << std::endl; // Remove this line of code if plan to deploy it later
	}
}
void fps::Update(float deltatime){
	timer += deltatime;
	if (timer >= 100.0f) {
		std::string fps = "FPS: " + std::to_string((int)(1000 / deltatime));
		fpstext.setString(fps);
		timer = 0;
	}
}
void fps::Draw(sf::RenderWindow& window){
	window.draw(fpstext);
}