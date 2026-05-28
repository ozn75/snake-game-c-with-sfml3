#include "Menu.hpp"
#include <string>
#include <iostream>

Menu::Menu(const sf::Font& font)
{
	currentdurum = mdurum::None;
	// Initialize menu items
	sf::Text playText(font);
	playText.setString("Oyna");
	playText.setCharacterSize(30);
	playText.setFillColor(sf::Color::White);
	menuItems.push_back(playText);
	sf::Text odakurmaText(font);
	odakurmaText.setString("Oda Kurma");
	odakurmaText.setCharacterSize(30);
	odakurmaText.setFillColor(sf::Color::White);
	menuItems.push_back(odakurmaText);
	sf::Text exitText(font);
	exitText.setString("Cikis");
	exitText.setCharacterSize(30);
	exitText.setFillColor(sf::Color::White);
	menuItems.push_back(exitText);
}

void Menu::menuciz(sf::RenderWindow& window)
{
	for (int i = 0; i < menuItems.size(); i++)
	{
		sf::Vector2f position(450.0f, 350.0f + static_cast<float>(i) * 50.0f);
		menuItems[i].setPosition(position);
		window.draw(menuItems[i]);
	}
}

void Menu::menuolayyonetim(const sf::RenderWindow& window1,const std::optional<sf::Event>& olay1)
{

	if (olay1->is<sf::Event::MouseButtonPressed>())
	{
		const auto* mouse = olay1->getIf<sf::Event::MouseButtonPressed>();
		if (mouse->button == sf::Mouse::Button::Left) {

			sf::Vector2i farepozisyon = sf::Mouse::getPosition(window1);
			if (menuItems[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(farepozisyon)))
			{
				std::cout << "Oyna secildi" << std::endl;
				currentdurum = mdurum::Oyna;

			}
			if (menuItems[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(farepozisyon)))
			{
				std::cout << "oda oluþturuluyor" << std::endl;
				currentdurum = mdurum::odakur;

			}
			if (menuItems[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(farepozisyon)))
			{
				std::cout << "Cikis secildi" << std::endl;
				currentdurum = mdurum::Cikis;
			}
		}
	}
}


Menu::mdurum Menu::getCurrentDurum() const
{
	return currentdurum;
}
