#include "Game.hpp"
#include <iostream>

Game::Game() : menu(font),oyunekraný(font)
{	
	gamedurumu = Gamedurum::menude;
	fontyukle();
	pencereolustur();

}

void Game::Gameolayyonetim()
{
	while (const std::optional<sf::Event> olay = window.pollEvent())
	{
		if (olay->is<sf::Event::Closed>())
		{
			window.close();
		}
		if (gamedurumu == Gamedurum::menude)
		{
			menu.menuolayyonetim(window, olay);
			if (menu.getCurrentDurum() == Menu::mdurum::Oyna)
			{
				setgdurum(Gamedurum::oyunda);
				std::cout << "Oyun baþladý!" << std::endl;
			}
			if (menu.getCurrentDurum() == Menu::mdurum::odakur)
			{
				setgdurum(Gamedurum::odakurma);
				std::cout << "oda kuruluyor!" << std::endl;
			}
			else if (menu.getCurrentDurum() == Menu::mdurum::Cikis)
			{
				window.close();
				std::cout << "Oyun kapatýlýyor!" << std::endl;
			}
		}
		if (gamedurumu == Gamedurum::oyunda)
		{
			oyunekraný.oyunolayyonetim(window, olay);
		}
	}
}



void Game::gciz()
{
	window.clear(sf::Color::Black);

	if (gamedurumu == Gamedurum::menude)
	{
		menu.menuciz(window);
	}
	else if (gamedurumu == Gamedurum::oyunda)
	{
		oyunekraný.oyunekranciz(window);
	}

	window.display();
}


void Game::pencereolustur()
{
	window.create(sf::VideoMode({ 1000, 800 }), "Yýlan Oyunu");
	window.setFramerateLimit(60);
}

void Game::fontyukle()
{ 
	if (!font.openFromFile("Yazilar/yazitipi.ttf")) {
		// Handle error
		std::cerr << "Font yüklenemedi!" << std::endl;
	}
}

void Game::setgdurum(Gamedurum durum1)
{
	gamedurumu = durum1;
}

void Game::gameupdate(sf::Time dt)
{
	if (gamedurumu == Gamedurum::oyunda)
	{
		gecenSure += dt;

		if (gecenSure >= hareketSikligi)
		{
			oyunekraný.updateoekraný();
			gecenSure = sf::Time::Zero;
		}
	}
}

void Game::run()
{
	sf::Clock saat;

	while (window.isOpen())
	{
		sf::Time dt = saat.restart();

		// 1. Olaylarý iþle
		Gameolayyonetim();

		// 2. Oyun durumunu güncelle
		gameupdate(dt);

		// 3. Ekraný çiz
		gciz();
	}
}
