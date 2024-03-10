#pragma once
#ifndef _FINISH_GAME_H_
#define _FINISH_GAME_H_
#include "SFML\Graphics.hpp"
using namespace sf;
class finishGame
{
public:
	finishGame(RenderWindow& window)
	{
		this->rectangleX = window.getSize().x / 2;
		this->rectangleY = window.getSize().y / 2;
		this->positionX = window.getSize().x / 4;
		this->positionY = window.getSize().y / 4;
		mainRectangle.setFillColor(Color(82,182,154));
		mainRectangle.setSize(Vector2f(this->rectangleX, this->rectangleY));
		mainRectangle.setPosition(Vector2f(this->positionX, this->positionY));
		buttonExit.setFillColor(Color(153, 217, 140));
		buttonExit.setSize(Vector2f(rectangleX / 2.5, rectangleY / 5));
		buttonExit.setPosition(Vector2f(positionX + positionX / 10, positionY + positionY * 1.5));
		buttonNewGame.setFillColor(Color(153, 217, 140));
		buttonNewGame.setSize(Vector2f(rectangleX / 2.5, rectangleY / 5));
		buttonNewGame.setPosition(Vector2f(positionX + rectangleX - positionX / 10 - rectangleX/2.5, positionY + positionY * 1.5));
		font.loadFromFile("fonts\\fontFinish.ttf");
		congratulation.setFont(font);
		congratulation.setString("Congratulations, you won!");
		congratulation.setOutlineThickness(14);
		congratulation.setPosition(positionX + rectangleX / 4, positionY + rectangleY / 3);
		congratulation.setStyle(Text::Bold);
		exit.setFont(font);
		exit.setString("Exit");
		exit.setOutlineThickness(12);
		exit.setPosition(positionX + positionX / 10 + rectangleX / 6, positionY + positionY * 1.5 + rectangleY / 15);
		newGame.setFont(font);
		newGame.setString("New game");
		newGame.setOutlineThickness(12);
		newGame.setPosition(positionX + rectangleX - positionX / 10 - rectangleX / 2.5 + rectangleX / 8, positionY + positionY * 1.5 + rectangleY / 15);
	}
	void drawIntro(RenderWindow& window)
	{
		window.draw(mainRectangle);
		window.draw(buttonExit);
		window.draw(buttonNewGame);
		window.draw(congratulation);
		window.draw(exit);
		window.draw(newGame);
	}
private:
	RectangleShape mainRectangle;
	RectangleShape buttonExit;
	RectangleShape buttonNewGame;
	Font font;
	Text congratulation;
	Text exit;
	Text newGame;
	float rectangleX;
	float rectangleY;
	float positionX;
	float positionY;
};
#endif