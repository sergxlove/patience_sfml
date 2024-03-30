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
	bool checkQauntityCard(int dragging_index)
	{
		int quantity = 0;
		bool isFound = false;
		for (auto& el : collum)
		{
			if (isFound)
			{
				quantity++;
			}
			if (el == dragging_index)
			{
				quantity++;
				isFound = true;
			}
		}
		if (quantity == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
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
	void getArrayDraggingCard(vector<int>& arr, int dragging_index)
	{
		bool isCheck = false;
		arr.clear();
		for (auto& el : collum)
		{
			if (isCheck)
			{
				arr.push_back(el);
			}
			if (el == dragging_index)
			{
				isCheck = true;
			}
		}
	}
private:
	vector<int> collum;
	RectangleShape emptyCollum;
	bool isEmptyCollum;
};
#endif