#pragma once
#ifndef _SLOT_H_
#define _SLOT_H_
#include <vector>
#include "enums.h"
using namespace std;
class slot
{
public:
    vector<int>& get_slot();
    bool add(int value, int index, int mast);
    int top();
private:
    vector<int> slot_card;
    int mast = masts::no_mast;
    int index = 12;
};
#endif
