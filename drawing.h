#pragma once
#ifndef _DRAWING_H_
#define _DRAWING_H_
#include "SFML\Graphics.hpp"
#include <vector>
#include "Card.h"
using namespace std;
using namespace sf;
class drawing
{
public:
    void first_draw_all_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7);
    void draw_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7);
    void draw_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7, RectangleShape&  emptyColl);
    void draw_slots(RenderWindow& window, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& slot_1, vector<int>& slot_2, vector<int>& slot_3, vector<int>& slot_4);

};
#endif // !_DRAWING_H_
