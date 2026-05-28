#include "Snake.hpp"
#include <iostream>

Snake::Snake() : currentyon(syon::Sag)
{
	sbody.push_back(sf::RectangleShape(sf::Vector2f(sbodywidth, sbodyheight)));
	sbody[0].setFillColor(sf::Color::Red);
	sbody[0].setPosition(sf::Vector2f(20.0f,20.0f)); // Baþlangýç pozisyonu
	sbody[0].setOutlineColor(sf::Color::White);
	sbody[0].setOutlineThickness(2.f); // Kenar çizgisi kalýnlýðý

}

void Snake::yonayarlama(syon yon1)
{
	// Ters yöne dönme engeli
	if ((currentyon == syon::Yukari && yon1 == syon::Asagi) ||
		(currentyon == syon::Asagi && yon1 == syon::Yukari) ||
		(currentyon == syon::Sol && yon1 == syon::Sag) ||
		(currentyon == syon::Sag && yon1 == syon::Sol)) {
		return;
	}
	currentyon = yon1;
}

void Snake::hareketet(syon yon)
{
	for (int i = sbody.size() - 1; i > 0; --i)
	{
		sbody[i].setPosition(sbody[i - 1].getPosition());
	}


	sf::Vector2f yenipozisyon = sbody[0].getPosition();

	switch (yon)
	{
	case Snake::syon::Sag:
		yenipozisyon.x += sbodywidth; // Sað hareket
		break;
	case Snake::syon::Sol:
		yenipozisyon.x -= sbodywidth; // Sol hareket
		break;
	case Snake::syon::Yukari:
		yenipozisyon.y -= sbodyheight; // Yukarý hareket
		break;
	case Snake::syon::Asagi:
		yenipozisyon.y += sbodyheight; // Aþaðý hareket
		break;
	default:
		break;
	}
	sbody[0].setPosition(yenipozisyon);
}

void Snake::sbuyut()
{
	sf::RectangleShape yeniparca(sf::Vector2f(sbodywidth, sbodyheight));
	yeniparca.setFillColor(sf::Color::White);
	yeniparca.setPosition(sbody.back().getPosition()); // Son parçanýn pozisyonuna ekle
	sbody.push_back(yeniparca);
}

void Snake::snakeciz(sf::RenderWindow& window)
{
	for (int i = 0;i<sbody.size();i++)
	{
		window.draw(sbody[i]);
	}
}

Snake::syon Snake::getCurrentyon() const
{
	return currentyon;
}

sf::Vector2f Snake::sgetpozisyon() const
{
	return sbody[0].getPosition();
}

sf::RectangleShape Snake::getsbody() const
{
	return sbody[0];
}


