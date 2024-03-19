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
		this->isEmptyCollum = false;
		this->emptyCollum.setSize(Vector2f(164.2, 230));
		this->emptyCollum.setFillColor(Color(95, 155, 138));
		this->emptyCollum.setScale(0.8f, 0.8f);
		this->emptyCollum.setPosition(200.0f * size, 300.0f);
		this->collum.reserve(size);
		int value = 0;
		auto it = arrayCard.begin();
		for (int i = 0;i < size;)
		{
			value = rand() % 52;
			it = arrayCard.begin();
			advance(it, value);
			if (it->getUsers() == false)
			{
				this->collum.push_back(value);
				it->setUsers(true);
				i++;
			}
		}
	}
	vector<int>& getColl()
	{
		return this->collum;
	}
	int top()
	{
		return this->collum[collum.size() - 1];
	}
	int top(int index)
	{
		return this->collum[index];
	}
	bool add(int draggingCardIndex, int draggingCardColor, int commonCardIndex, int commonCardColor, int totalIndex)
	{
		if (draggingCardIndex + 1 == commonCardIndex && draggingCardColor != commonCardColor)
		{
			this->collum.push_back(totalIndex);
			return true;
		}
		else
		{
			return false;
		}
	}
	bool getCondition()
	{
		return this->isEmptyCollum;
	}
	void setCondition(bool isEmptyCollum)
	{
		this->isEmptyCollum = isEmptyCollum;
	}
	void delLast()
	{
		this->collum.erase(this->collum.begin() + (this->collum.size() - 1));
	}
	int getSize()
	{
		return this->collum.size();
	}
private:
	vector<int> collum;
	RectangleShape emptyCollum;
	bool isEmptyCollum;
};
#endif