#pragma once
#include <SFML/Graphics.hpp>



class Food {
public:
	Food();

	void foodciz(sf::RenderWindow& window); // Yiyeceði çizme fonksiyonu
	void setfpositionrandom(); // Yiyeceðin pozisyonunu ayarlama fonksiyonu
	sf::Vector2f getfposition() const; // Yiyeceðin pozisyonunu alma fonksiyonu

	sf::RectangleShape getfbody() const; // Yiyeceðin þekil nesnesini alma fonksiyonu

private:
	sf::Vector2f fposition; // Yiyeceðin pozisyonu
	sf::RectangleShape fbody; // Yiyeceðin þekli
	
};