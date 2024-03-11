#pragma once
#ifndef _COLLUM_H_
#define _COLUMN_H_
#include "SFML\Graphics.hpp"
#include "Card.h"
#include <vector>
using namespace std;
using namespace sf;
class coll
{
public:
	coll(vector<Card>& arrayCard, int size)
	{
		isEmptyCollum = false;
		emptyCollum.setSize(Vector2f(164.2, 230));
		emptyCollum.setFillColor(Color(95, 155, 138));
		emptyCollum.setScale(0.8f, 0.8f);
		emptyCollum.setPosition(200.0f * size, 300.0f);
		collum.reserve(size);
		int value = 0;
		auto it = arrayCard.begin();
		for (int i = 0;i < size;)
		{
			value = rand() % 52;
			it = arrayCard.begin();
			advance(it, value);
			if (it->getUsers() == false)
			{
				collum.push_back(value);
				it->setUsers(true);
				i++;
			}
		}
	}
	vector<int> getColl()
	{
		return collum;
	}
	int top()
	{
		return collum[collum.size() - 1];
	}
	bool add(int draggingCardIndex, int draggingCardColor, int commonCardIndex, int commonCardColor)
	{
		if (draggingCardIndex < commonCardIndex && draggingCardColor != commonCardColor)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	vector<int> collum;
	RectangleShape emptyCollum;
	bool isEmptyCollum;
};
#endif