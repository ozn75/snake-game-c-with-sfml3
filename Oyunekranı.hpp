#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Food.hpp"


class Oyunekraný {
public:
	enum class oyunekranýdurumu
	{
		Oynuyor,
		Duraklatýldý,
		Died
	};

	
	Oyunekraný(const sf::Font& font);

	void oyunekranciz(sf::RenderWindow& window);
	void oyunolayyonetim(const sf::RenderWindow& window1,const std::optional<sf::Event>& event1);
	void updateoekraný();
	bool yemyendimi();
	int getscore()const;
	void setscore(int sayi);
	void skorArttir(); // Skoru artýr
	void skorCiz(sf::RenderWindow& pencere); // Skoru çiz

private:
	int score = 0;
	sf::Text scoretext;
	oyunekranýdurumu currentoyunekraný;
	Snake snake; // Yýlan nesnesi
	Food yemek; // Yiyecek nesnesi
};