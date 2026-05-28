#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include <optional> 
#include "oyunekraný.hpp"


class Game {
public:
	enum class Gamedurum
	{
		menude,
		oyunda,
		odakurma,
		beklemede
	};
	Game();

	void Gameolayyonetim();

	void gciz();

	void pencereolustur();
	void fontyukle();
	void setgdurum(Gamedurum durum1);
	void gameupdate(sf::Time dt);
	void run();

private:
	sf::Clock zamanlayici;
	sf::Time gecenSure;
	sf::Time hareketSikligi = sf::seconds(0.2); 

	sf::RenderWindow window;
	Menu menu;
	sf::Font font;
	Gamedurum gamedurumu = Gamedurum::menude;
	Oyunekraný oyunekraný; // Oyun ekraný nesnesi
};