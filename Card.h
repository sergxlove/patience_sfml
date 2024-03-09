#pragma once
#ifndef _CARD_H_
#define _CARD_H_
#include "enums.h"
class Card
{
public:
    Card(int index, int mast, int color, float pozitionX, float pozitionY, int number);//конструктор с параметрами
    Card();//базовый конструктор
    void setIndex(int index);//передача индекса
    void setMast(int mast);//передача масти
    void setColor(int color);//передача цвета
    void setPozition(float pozitionX, float PozitionY);//передача позиции
    void setNumber(int number);//передача порядкового номера
    void setUsers(bool users);//передача использования карты
    void setCondition(int condition);//передача состояния карты
    void setNumberCols(int number_cols);
    int getIndex();//возврат нидекса
    int getMast();//возврат масти
    int getColor();//возврат цвета
    float getPozitionX();//возврат позиции х
    float getPozitionY();//возврат позиции у
    int getNumber();//возврат порядкового номера
    bool getUsers();//возврат использования карты
    int getCondition();//возврат состояния карты
    int getNumberCols();
private:
    int index;//индекс карты
    int mast;//масть карты
    int color;//цвет карты
    float pozitionX;//позиция по х
    float pozitionY;//позиция по у
    int number;//порядковый номер элемента
    bool users;//использование карты
    int condition;//состояние карты
    int number_cols;//номер колонки в которой находится карта
};
#endif // !_CARD_H_