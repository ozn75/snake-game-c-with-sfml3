#pragma once
#include <SFML/Graphics.hpp>
#include <vector>



class Menu {
public:
	enum class mdurum
	{
		Oyna,
		odakur,
		Cikis,
		None
	};
	Menu(const sf::Font& font);
	void menuciz(sf::RenderWindow& window);
	void menuolayyonetim(const sf::RenderWindow& window1,const std::optional<sf::Event>& olay1);

	mdurum getCurrentDurum() const;


private:
	std::vector<sf::Text> menuItems;
	mdurum currentdurum = mdurum::None;

};