#include "Food.hpp"
#include <cstdlib>
#include <ctime>

Food::Food()
{
	fbody.setSize(sf::Vector2f(20.f,20.f));
	fbody.setFillColor(sf::Color::Blue); // Yiyeceðin rengi
	fbody.setPosition(sf::Vector2f(40.f,40.f));
	srand(time(nullptr));
}

void Food::foodciz(sf::RenderWindow& window)
{
	window.draw(fbody);
}

void Food::setfpositionrandom()
{
	float x = (rand() % 50) * 20 ;
	float y = (rand() % 40) * 20;

	fbody.setPosition(sf::Vector2f(x,y));
}

sf::Vector2f Food::getfposition() const
{
	return fposition;
}

sf::RectangleShape Food::getfbody() const
{
	return fbody;
}
