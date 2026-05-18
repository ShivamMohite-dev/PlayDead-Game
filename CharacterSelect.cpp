#include "CharacterSelect.h"
#include <iostream>
CharacterSelect::CharacterSelect(){}
CharacterSelect::~CharacterSelect(){}
void CharacterSelect::Initialize(){}
void CharacterSelect::Load(){
	std::cout << "CharacterSelect::Load() function called!" << std::endl; // Delete this line of code once everything is working perfectly
	if (backgroundTexture.loadFromFile("Assets/World/CharacterSelect-Texture.png")) {
		std::cout << "Background Texture Loaded Successfully" << std::endl;
		background_sprite.setTexture(backgroundTexture);
	}else {
		std::cout << "Failed to Background Texture" << std::endl; // Delete this line of code once everything is working perfectly
	}
	if (robinTexture.loadFromFile("Assets/Player/Robin.png")) {
		std::cout << "Character: Robin Loaded Successfully" << std::endl; // Delete this line of code once everything is working perfectly
		robin.setTexture(robinTexture);
		robin.setScale(0.45f,0.45f);
		robin.setPosition(sf::Vector2f(-50,200));
	}else {
		std::cout << "Failed to Load Character: Robin" << std::endl; // Delete this line of code once everything is working perfectly
	}
	if (frierenTexture.loadFromFile("Assets/Player/Frieren.png")) {
		std::cout << "Character: Frieren Loaded Successfully" << std::endl; // Delete this line of code once everything is working perfectly
		frieren.setTexture(frierenTexture);
		frieren.setScale(0.4f, 0.4f);
		frieren.setPosition(sf::Vector2f(330, 200));
	}else {
		std::cout << "Failed to Load Character: Frieren" << std::endl; // Delete this line of code once everything is working perfectly
	}
	if (hinataTexture.loadFromFile("Assets/Player/Hinata.png")) {
		std::cout << "Character: Hinata Loaded Successfully" << std::endl; // Delete this line of code once everything is working perfectly
		hinata.setTexture(hinataTexture);
		hinata.setScale(0.4f, 0.4f);
		hinata.setPosition(sf::Vector2f(600, 200));
	}
	else {
		std::cout << "Failed to Load Character: Hinata" << std::endl; // Delete this line of code once everything is working perfectly
	}
	if (GraduateFont.loadFromFile("Assets/Fonts/Graduate-Regular.ttf")) {
		std::cout << "Font: Graduate Loaded Successfully" << std::endl; // Delete this line of code once everything is working perfectly
		pickText.setFont(GraduateFont);
		pickText.setCharacterSize(60);
		pickText.setStyle(sf::Text::Bold);
		pickText.setString("PICK YOUR CHARACTER");
		pickText.setFillColor(sf::Color(49, 78, 110));
		pickText.setPosition(sf::Vector2f(50,50));

		RobinNameText.setFont(GraduateFont);
		RobinNameText.setCharacterSize(20);
		RobinNameText.setStyle(sf::Text::Bold);
		RobinNameText.setString("Robin");
		RobinNameText.setFillColor(sf::Color::Black);
		RobinNameText.setPosition(sf::Vector2f(100, 405));

		FrierenNameText.setFont(GraduateFont);
		FrierenNameText.setCharacterSize(20);
		FrierenNameText.setStyle(sf::Text::Bold);
		FrierenNameText.setString("Frieren");
		FrierenNameText.setFillColor(sf::Color::Black);
		FrierenNameText.setPosition(sf::Vector2f(380, 405));

		HinataNameText.setFont(GraduateFont);
		HinataNameText.setCharacterSize(20);
		HinataNameText.setStyle(sf::Text::Bold);
		HinataNameText.setString("Hinata");
		HinataNameText.setFillColor(sf::Color::Black);
		HinataNameText.setPosition(sf::Vector2f(650, 405));

		selectText.setFont(GraduateFont);
		selectText.setCharacterSize(30);
		selectText.setStyle(sf::Text::Bold);
		selectText.setString("CHARACTER SELECTED: ");
		selectText.setFillColor(sf::Color::Transparent);
		selectText.setPosition(sf::Vector2f(140, 470));

		charname.setFont(GraduateFont);
		charname.setCharacterSize(30);
		charname.setStyle(sf::Text::Bold);
		charname.setFillColor(sf::Color::Transparent);
		charname.setPosition(sf::Vector2f(510, 470));

		abilityinfo.setFont(GraduateFont);
		abilityinfo.setCharacterSize(20);
		abilityinfo.setStyle(sf::Text::Bold);
		abilityinfo.setFillColor(sf::Color::Transparent);
		abilityinfo.setPosition(sf::Vector2f(20, 530));

		proceedText.setFont(GraduateFont);
		proceedText.setCharacterSize(25);
		proceedText.setStyle(sf::Text::Bold);
		proceedText.setString("PROCEED");
		proceedText.setFillColor(sf::Color::Transparent);
		proceedText.setPosition(sf::Vector2f(330, 700));
	}
	else {
		std::cout << "Font: Graduate Loading failed!" << std::endl; // Delete this line of code once everything is working perfectly
	}
	if (clicksound.openFromFile("Assets/Audio/click.mp3")){
		std::cout << "Click effect audio loaded successfully!" << std::endl;
		//clicksound.setLoop(true);
		clicksound.setVolume(30.f);
	}
	else{
		std::cout << "Click effect audio loading failed!" << std::endl;
	}
	if (hoversound.openFromFile("Assets/Audio/hover.mp3")) {
		std::cout << "Hover effect audio loaded successfully!" << std::endl;
		//hoversound.setLoop(true);
		hoversound.setVolume(30.f);
	}
	else {
		std::cout << "Hover effect audio loading failed!" << std::endl;
	}
	rect1.setSize(sf::Vector2f(200,200));
	rect1.setOutlineThickness(2);
	rect1.setOutlineColor(sf::Color::Black);
	rect1.setFillColor(sf::Color::Transparent);
	rect1.setPosition(sf::Vector2f(50,200));
	
	rect2.setSize(sf::Vector2f(200, 200));
	rect2.setOutlineThickness(2);
	rect2.setOutlineColor(sf::Color::Black);
	rect2.setFillColor(sf::Color::Transparent);
	rect2.setPosition(sf::Vector2f(330, 200));

	rect3.setSize(sf::Vector2f(200, 200));
	rect3.setOutlineThickness(2);
	rect3.setOutlineColor(sf::Color::Black);
	rect3.setFillColor(sf::Color::Transparent);
	rect3.setPosition(sf::Vector2f(600, 200));

	proceedbutton.setSize(sf::Vector2f(150, 50));
	proceedbutton.setOutlineThickness(2);
	proceedbutton.setOutlineColor(sf::Color::Transparent);
	proceedbutton.setFillColor(sf::Color::Transparent);
	proceedbutton.setPosition(sf::Vector2f(320, 690));
}
void CharacterSelect::Update(sf::RenderWindow& window, sf::Event& event, gamestate& currentState){
	// --- HOVER EFFECTS ---
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	if (rect1.getGlobalBounds().contains(mousePosF)){ //Rect 1 - Robin
		rect1.setOutlineColor(sf::Color(49, 78, 110));
		rect1.setOutlineThickness(4);
		rect1.setFillColor(sf::Color(49, 78, 110, 40));
		hoversound.play();
	}
	else{
		rect1.setOutlineColor(sf::Color::Black);
		rect1.setOutlineThickness(2);
		rect1.setFillColor(sf::Color::Transparent);
	}
	if (rect2.getGlobalBounds().contains(mousePosF)){ // Rect 2 - Frieren
		rect2.setOutlineColor(sf::Color(49, 78, 110));
		rect2.setOutlineThickness(4);
		rect2.setFillColor(sf::Color(49, 78, 110, 40));
		hoversound.play();
	}
	else{
		rect2.setOutlineColor(sf::Color::Black);
		rect2.setOutlineThickness(2);
		rect2.setFillColor(sf::Color::Transparent);
	}
	if (rect3.getGlobalBounds().contains(mousePosF)){ // Rect 3 - Hinata
		rect3.setOutlineColor(sf::Color(49, 78, 110));
		rect3.setOutlineThickness(4);
		rect3.setFillColor(sf::Color(49, 78, 110, 40));
		hoversound.play();
	}
	else{
		rect3.setOutlineColor(sf::Color::Black);
		rect3.setOutlineThickness(2);
		rect3.setFillColor(sf::Color::Transparent);
	}
	if (proceedbutton.getGlobalBounds().contains(mousePosF)){
		proceedbutton.setFillColor(sf::Color(49, 78, 110, 180));
		proceedbutton.setOutlineColor(sf::Color(49, 78, 110));
		proceedText.setFillColor(sf::Color::White);
	}
	else if (!selectedcharacter.empty()){
		proceedbutton.setFillColor(sf::Color::Transparent);
		proceedbutton.setOutlineColor(sf::Color::Black);
		proceedText.setFillColor(sf::Color::Black);
	}
	// --- CLICK EVENTS ---
	sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (rect1.getGlobalBounds().contains(mousePos)){
				std::cout << "Character Selected: Robin" << std::endl;
				selectedcharacter = "Robin";
				selectText.setFillColor(sf::Color(179, 92, 68));
				charname.setString(selectedcharacter);
				charname.setFillColor(sf::Color::Black);
				abilityinfo.setString("Robin is a stealth-based fighter who combines dual-blade\ncombat with shadow manipulation abilities. He can move \nsilently, create illusion clones, and perform quick surprise\nattacks that confuse enemies during combat.");
				abilityinfo.setFillColor(sf::Color::Black);
				proceedText.setFillColor(sf::Color::Black);
				proceedbutton.setOutlineColor(sf::Color::Black);
			}
			if (rect2.getGlobalBounds().contains(mousePos)){
				std::cout << "Character Selected: Frieren" << std::endl;
				selectedcharacter = "Frieren";
				selectText.setFillColor(sf::Color(179, 92, 68));
				charname.setString(selectedcharacter);
				charname.setFillColor(sf::Color::Black);
				abilityinfo.setString("Frieren is a calm and highly skilled mage who possesses\npowerful ancient magic. She can cast destructive attack spells,\ndefensive barriers, and support magic while maintaining\nexceptional control and intelligence during battles.");
				abilityinfo.setFillColor(sf::Color::Black);
				proceedText.setFillColor(sf::Color::Black);
				proceedbutton.setOutlineColor(sf::Color::Black);
			}
			if (rect3.getGlobalBounds().contains(mousePos)){
				std::cout << "Character Selected: Hinata" << std::endl;
				selectedcharacter = "Hinata";
				selectText.setFillColor(sf::Color(179, 92, 68));
				charname.setString(selectedcharacter);
				charname.setFillColor(sf::Color::Black);
				abilityinfo.setString("Hinata is a fast and energetic volleyball player with\nincredible jumping ability. Even though he is short, his speed,\nreflexes, and determination allow him to perform powerful\nspikes and surprise his opponents on the court.");
				abilityinfo.setFillColor(sf::Color::Black);
				proceedText.setFillColor(sf::Color::Black);
				proceedbutton.setOutlineColor(sf::Color::Black);
			}
			if (proceedbutton.getGlobalBounds().contains(mousePos) && !selectedcharacter.empty())
			{
				clicksound.play(); // UNCOMMENT THIS FOR BACKGROUND MUSIC
				std::cout << "Proceed Button pressed!" << std::endl;
				finalizedcharacter = selectedcharacter;
				currentState = gamestate::Playing;
			}
		}
	}
}
void CharacterSelect::Draw(sf::RenderWindow& window){
	window.draw(background_sprite);
	window.draw(pickText);
	window.draw(rect1);
	window.draw(rect2);
	window.draw(rect3);
	window.draw(robin);
	window.draw(frieren);
	window.draw(hinata);
	window.draw(RobinNameText);
	window.draw(FrierenNameText);
	window.draw(HinataNameText);
	window.draw(selectText);
	window.draw(charname);
	window.draw(abilityinfo);
	window.draw(proceedbutton);
	window.draw(proceedText);
}