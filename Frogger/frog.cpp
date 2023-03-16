#include "frog.h"
#include "globals.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

frog::frog() {
	xpos = 500;
	ypos = 954;
	lives = 5;
	xVel = 0;
	yVel = 0;
}

void frog::draw(sf::RenderWindow& window) {
	sf::RectangleShape FrogPic(sf::Vector2f(20, 20));
	FrogPic.setFillColor(sf::Color(50, 200, 50));
	FrogPic.setPosition(xpos, ypos);
	window.draw(FrogPic);
}

void frog::jump(bool* keys) {
	if (keys[UP] == true)
		yVel = -50;
	else if (keys[DOWN] == true)
		yVel = 50;
	else if (keys[LEFT] == true)
		xVel = -50;
	else if (keys[RIGHT] == true)
		xVel = 50;
	else {
		yVel = 0;
		xVel = 0;
	}

	
	xpos += xVel;
	ypos += yVel;
}

void frog::ded() {
	Beep(500, 500);
	lives--;
	xpos = 500;
	ypos = 954;
}