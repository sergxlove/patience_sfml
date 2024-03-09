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
        if (this->index == 12)
        {
            this->index = 0;
        }
        else
        {
            this->index++;
        }
        slot_card.push_back(value);
        return true;
    }
    if (this->mast == mast && this->index == index)
    {
        if (this->index == 12)
        {
            this->index = 0;
        }
        else
        {
            this->index++;
        }
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

