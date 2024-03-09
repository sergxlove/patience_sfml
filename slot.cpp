#include "slot.h"
vector<int>& slot::get_slot()
{
    return slot_card;
}

bool slot::add(int value, int index, int mast)
{
    if (this->mast == masts::no_mast && this->index == index)
    {
        this->mast = mast;
        this->index++;
        slot_card.push_back(value);
        return true;
    }
    if (this->mast == mast && this->index == index)
    {
        this->index++;
        slot_card.push_back(value);
        return true;
    }
    else
    {
        return false;
    }
}

int slot::top()
{
    return slot_card[slot_card.size() - 1];
}

