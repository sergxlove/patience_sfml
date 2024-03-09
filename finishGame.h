#pragma once
#ifndef _FINISH_GAME_H_
#define _FINISH_GAME_H_
#include "SFML\Graphics.hpp"
using namespace sf;
class finishGame
{
public:
	finishGame()
	{
		mainRectangle.setFillColor(Color::White);
		mainRectangle.setSize(Vector2f(700.0f, 500.0f));
		mainRectangle.setPosition(Vector2f(300.0f, 300.0f));
	}
	void drawIntro(RenderWindow& window)
	{
		window.draw(mainRectangle);
		
	}
private:
	RectangleShape mainRectangle;
};
#endif