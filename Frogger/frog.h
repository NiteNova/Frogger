#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class frog {
private:
	int lives;
	float xVel;
	float yVel;

public:
	float xpos;
	float ypos;
	frog();
	void draw(sf::RenderWindow& window);
	void jump(bool* keys);
	float returnX() { return xpos; }
	float returnY() { return ypos; }
	void ded();
	int returnLives() { return lives; }
	void printInfo() { cout << "My position is " << xpos << ", " << ypos << endl; }
};

