#pragma once
#ifndef _FEELDING_H_
#define _FEELDING_H_
#include <vector>
#include "SFML\Graphics.hpp"
#include "Card.h"
using namespace std;
using namespace sf;
class fielding
{
public:
    vector<Card> fieldArray();
    vector<Sprite> field_array_for_card(Texture* texture);
    vector<int> field_cols(vector<Card>& check, int size);
    vector<int>field_array_shop(vector<Card>& check);
    vector<Sprite> field_array_sprite(Texture* texture, vector<Card>& arrayCard);
    void field_conditions(vector<Card>& arrayCard, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7, vector<int>& slot_v1, vector<int>& slot_v2, vector<int>& slot_v3, vector<int>& slot_v4, vector<int>& shop_arr);
    void field_number_cols(vector<Card>& arrayCard, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7);
};
#endif
