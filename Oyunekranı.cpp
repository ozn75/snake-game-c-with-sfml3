#include "Oyunekraný.hpp"
#include <iostream>

Oyunekraný::Oyunekraný(const sf::Font& font) : currentoyunekraný(oyunekranýdurumu::Oynuyor),scoretext(font)
{
    scoretext.setPosition(sf::Vector2f(900, 20));
    scoretext.setFillColor(sf::Color::White);
    scoretext.setCharacterSize(24);
    scoretext.setString("Skor: 0");
}

void Oyunekraný::oyunekranciz(sf::RenderWindow& window)
{   
    skorCiz(window);
    yemek.foodciz(window);
	snake.snakeciz(window);
}

void Oyunekraný::oyunolayyonetim(const sf::RenderWindow& window1,const std::optional<sf::Event>& event1)
{
    if (event1->is<sf::Event::KeyPressed>())
    {
		const auto* keyEvent = event1->getIf<sf::Event::KeyPressed>();
        if (keyEvent->scancode == sf::Keyboard::Scancode::W)
        {
            snake.yonayarlama(Snake::syon::Yukari);
            std::cout << "Yukarý" << std::endl;
        }
        else if (keyEvent->scancode == sf::Keyboard::Scancode::S)
        {
            snake.yonayarlama(Snake::syon::Asagi);
            std::cout << "Asagi" << std::endl;
        }
        else if (keyEvent->scancode == sf::Keyboard::Scancode::A)
        {
            snake.yonayarlama(Snake::syon::Sol);
            std::cout << "Sol" << std::endl;
        }
        else if (keyEvent->scancode == sf::Keyboard::Scancode::D)
        {
            snake.yonayarlama(Snake::syon::Sag);
            std::cout << "Sag" << std::endl;
        }
    }
}

void Oyunekraný::updateoekraný()
{
	snake.hareketet(snake.getCurrentyon());

    if (yemyendimi())
    {   

        skorArttir();
        snake.sbuyut();
        yemek.setfpositionrandom();
    }
}

bool Oyunekraný::yemyendimi()
{
    sf::FloatRect snakeBounds = snake.getsbody().getGlobalBounds();
    sf::FloatRect yemekBounds = yemek.getfbody().getGlobalBounds();

    if (snakeBounds.findIntersection(yemekBounds))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Oyunekraný::getscore() const
{
    return score;
}

void Oyunekraný::setscore(int sayi)
{
    score = sayi;
}

void Oyunekraný::skorArttir()
{
    score += 1;
    scoretext.setString("SKOR: " + std::to_string(score));
}

void Oyunekraný::skorCiz(sf::RenderWindow& pencere)
{
    pencere.draw(scoretext);
}

