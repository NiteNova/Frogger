#include <SFML/Graphics.hpp>
#include <iostream>
#include "globals.h"
#include "frog.h"
#include <time.h>
using namespace std;

int main() {

	srand(time(NULL));
	int timer = 0;
	bool keys[] = { false, false, false, false };

	sf::RenderWindow screen(sf::VideoMode(1000, 1000), "Frogger!");

	frog player;

	while (screen.isOpen()) { //gameloop
		//input section
		sf::Event event;
		while (screen.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				screen.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				keys[UP] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				keys[DOWN] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				keys[LEFT] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				keys[RIGHT] = true;
			}
			else {
				keys[UP] = false;
				keys[DOWN] = false;
				keys[LEFT] = false;
				keys[RIGHT] = false;
			}
				
		}
		//physics section
		timer++;
		if (timer > 400) {
			player.jump(keys);
			timer = 0;
		}
		

		//render section
		screen.clear();

		player.draw(screen);

		screen.display();
	}
	cout << "GAME OVER" << endl;
	return 0;
}