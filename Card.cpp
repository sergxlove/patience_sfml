#include "Card.h"
Card::Card(int index, int mast, int color, float pozitionX, float pozitionY, int number)
{
    this->index = index;
    this->mast = mast;
    this->color = color;
    this->pozitionX = pozitionX;
    this->pozitionY = pozitionY;
    this->number = number;
    this->users = false;
    this->condition = conditions::none;
    this->number_cols = 0;
}

Card::Card()
{
    this->index = 0;
    this->mast = 0;
    this->color = 0;
    this->pozitionX = 0.0f;
    this->pozitionY = 0.0f;
    this->number = 0;
    this->users = false;
    this->condition = conditions::none;
    this->number_cols = 0;
}
void Card::setIndex(int index)
{
    this->index = index;
}
void Card::setMast(int mast)
{
    this->mast = mast;
}
void Card::setColor(int color)
{
    this->color = color;
}
void Card::setPozition(float pozitionX, float pozitionY)
{
    this->pozitionX = pozitionX;
    this->pozitionY = pozitionY;
}
void Card::setNumber(int number)
{
    this->number = number;
}
void Card::setUsers(bool users)
{
    this->users = users;
}
void Card::setCondition(int condition)
{
    this->condition = condition;
}
void Card::setNumberCols(int number_cols)
{
    this->number_cols = number_cols;
}
int Card::getIndex()
{
    return index;
}
int Card::getMast()
{
    return mast;
}
int Card::getColor()
{
    return color;
}
float Card::getPozitionX()
{
    return pozitionX;
}
float Card::getPozitionY()
{
    return pozitionY;
}
int Card::getNumber()
{
    return number;
}
bool Card::getUsers()
{
    return users;
}
int Card::getCondition()
{
    return condition;
}

int Card::getNumberCols()
{
    return number_cols;
}
