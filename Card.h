#pragma once
#ifndef _CARD_H_
#define _CARD_H_
#include "enums.h"
class Card
{
public:
    Card(int index, int mast, int color, float pozitionX, float pozitionY, int number);//����������� � �����������
    Card();//������� �����������
    void setIndex(int index);//�������� �������
    void setMast(int mast);//�������� �����
    void setColor(int color);//�������� �����
    void setPozition(float pozitionX, float PozitionY);//�������� �������
    void setNumber(int number);//�������� ����������� ������
    void setUsers(bool users);//�������� ������������� �����
    void setCondition(int condition);//�������� ��������� �����
    void setNumberCols(int number_cols);
    int getIndex();//������� �������
    int getMast();//������� �����
    int getColor();//������� �����
    float getPozitionX();//������� ������� �
    float getPozitionY();//������� ������� �
    int getNumber();//������� ����������� ������
    bool getUsers();//������� ������������� �����
    int getCondition();//������� ��������� �����
    int getNumberCols();
private:
    int index;//������ �����
    int mast;//����� �����
    int color;//���� �����
    float pozitionX;//������� �� �
    float pozitionY;//������� �� �
    int number;//���������� ����� ��������
    bool users;//������������� �����
    int condition;//��������� �����
    int number_cols;//����� ������� � ������� ��������� �����
};
#endif // !_CARD_H_