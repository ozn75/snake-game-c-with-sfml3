#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Snake {
public:
	enum class syon
	{
		Sag,
		Sol,
		Yukari,
		Asagi
	};


	Snake();

	void yonayarlama(syon yon1);
	void hareketet(syon yon1);
	void sbuyut();
	void snakeciz(sf::RenderWindow& window);
	syon getCurrentyon() const;
	sf::Vector2f sgetpozisyon() const;
	sf::RectangleShape getsbody() const;
	
private:
	syon currentyon; // Yýlanýn hareket yönü
	std::vector<sf::RectangleShape> sbody; // Yýlanýn gövde parçalarý
	sf::Vector2f sposition; // Yýlanýn baþlangýç pozisyonu
	float sbodywidth = 20.0f; // Yýlanýn gövde parçalarýnýn geniþliði
	float sbodyheight = 20.0f; // Yýlanýn gövde parçalarýnýn yüksekliði
};