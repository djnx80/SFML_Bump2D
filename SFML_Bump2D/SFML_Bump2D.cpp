#include "stdafx.h"
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bump2D.h"

int main()
{
	srand(time(NULL));
	// otwórz okno
	sf::RenderWindow okno(sf::VideoMode(800, 600), "Okno");
	okno.setVerticalSyncEnabled(true);	// 60fps

	// nowy bump
	Bump2D *bump = new Bump2D("obrazek.jpg","light3.png", 250, 20);
	sf::Clock zegar;

	while (okno.isOpen())
	{
		sf::Event event;
		while (okno.pollEvent(event))	{
			if (event.type == sf::Event::Closed)	okno.close();
		}

		okno.clear();
		zegar.restart();
		bump->drawAndUpdate(okno);
		std::cout << "czas: " << zegar.getElapsedTime().asMilliseconds() << std::endl;
		okno.display();
	}

	// usuñ z pamiêci bumpa
	delete bump;
	return 0;
}

