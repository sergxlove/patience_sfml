#include "feelding.h"
vector<Card> fielding::fieldArray()
{
    vector<Card> result;
    int totalIndex = 0;
    int cols = 0;
    int n = 0;
    result.reserve(52);
    for (int i = 0;i < 52;i++)
    {
        Card card;
        card.setIndex(totalIndex);
        card.setPozition(20 + (totalIndex * 164.2), 20 + (cols * 230));
        card.setNumber(n);
        n++;
        if (cols == 0)
        {
            card.setColor(colors::red);
            card.setMast(masts::hearts);
        }
        else if (cols == 1)
        {
            card.setColor(colors::black);
            card.setMast(masts::cross);
        }
        else if (cols == 2)
        {
            card.setColor(colors::red);
            card.setMast(masts::booby);
        }
        else if (cols == 3)
        {
            card.setColor(colors::black);
            card.setMast(masts::peaks);
        }
        totalIndex++;
        if (totalIndex > 12)
        {
            totalIndex = 0;
            cols++;
        }
        result.push_back(card);
    }
    return result;
}

vector<Sprite> fielding::field_array_for_card(Texture* texture)
{
    vector<Sprite> result;
    float pozitionX = 500.0;
    float pozitionY = 50.0;
    for (int i = 0;i < 4;i++)
    {
        Sprite card_spr;
        card_spr.setTexture(*texture);
        card_spr.setTextureRect(IntRect(2160, 250, 164, 230));
        card_spr.setScale(0.8f, 0.8f);
        card_spr.setPosition(pozitionX, pozitionY);
        pozitionX += 170;
        result.push_back(card_spr);
    }
    return result;
}

vector<int> fielding::field_cols(vector<Card>& check, int size)
{
    vector<int> result;
    result.reserve(size);
    int value = 0;
    auto it = check.begin();
    for (int i = 0;i < size;)
    {
        value = rand() % 52;
        it = check.begin();
        advance(it, value);
        if (it->getUsers() == false)
        {
            result.push_back(value);
            it->setUsers(true);
            i++;
        }
    }
    return result;
}

vector<int> fielding::field_array_shop(vector<Card>& check)
{
    vector<int> result;
    int count = 0;
    result.reserve(24);
    for (auto it = check.begin();it != check.end();it++)
    {
        if (it->getUsers() == false)
        {
            result.push_back(count);
            it->setColor(true);
        }
        count++;
    }
    return result;
}

vector<Sprite> fielding::field_array_sprite(Texture* texture, vector<Card>& arrayCard)
{
    vector<Sprite> result;
    result.reserve(52);
    for (auto& cards : arrayCard)
    {
        Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setTextureRect(IntRect(cards.getPozitionX(), cards.getPozitionY(), 164, 230));
        sprite.setScale(0.8f, 0.8f);
        sprite.setPosition(200, 50);
        result.push_back(sprite);
    }
    return result;
}

void fielding::field_conditions(vector<Card>& arrayCard, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7, vector<int>& slot_v1, vector<int>& slot_v2, vector<int>& slot_v3, vector<int>& slot_v4, vector<int>& shop_arr)
{
    auto it = arrayCard.begin();
    if (!slot_v1.empty())
    {
        for (auto& el : slot_v1)
        {
            advance(it, el);
            it->setCondition(conditions::is_slot);
            it = arrayCard.begin();
        }
    }
    if (!slot_v2.empty())
    {
        for (auto& el : slot_v2)
        {
            advance(it, el);
            it->setCondition(conditions::is_slot);
            it = arrayCard.begin();
        }
    }
    if (!slot_v3.empty())
    {
        for (auto& el : slot_v3)
        {
            advance(it, el);
            it->setCondition(conditions::is_slot);
            it = arrayCard.begin();
        }
    }
    if (!slot_v4.empty())
    {
        for (auto& el : slot_v4)
        {
            advance(it, el);
            it->setCondition(conditions::is_slot);
            it = arrayCard.begin();
        }
    }
    auto it_v = v1.begin();
    for (auto& el : v1)
    {
        it = arrayCard.begin();
        if (it_v == v1.end() - 1)
        {
            advance(it, el);
            it->setCondition(conditions::open);
        }
        else
        {
            advance(it, el);
            it->setCondition(conditions::closed);
            it_v++;
        }
    }
    it_v = v2.begin();
    for (auto& el : v2)
    {
        it = arrayCard.begin();
        if (it_v == v2.end() - 1)
        {
            advance(it, el);
            it->setCondition(conditions::open);
        }
        else
        {
            advance(it, el);
            it->setCondition(conditions::closed);
            it_v++;
        }
    }
    it_v = v3.begin();
    for (auto& el : v3)
    {
        it = arrayCard.begin();
        if (it_v == v3.end() - 1)
        {
            advance(it, el);
            it->setCondition(conditions::open);
        }
        else
        {
            advance(it, el);
            it->setCondition(conditions::closed);
            it_v++;
        }
    }
    it_v = v4.begin();
    for (auto& el : v4)
    {
        it = arrayCard.begin();
        if (it_v == v4.end() - 1)
        {
            advance(it, el);
            it->setCondition(conditions::open);
        }
        else
        {
            advance(it, el);
            it->setCondition(conditions::closed);
            it_v++;
        }
    }
    it_v = v5.begin();
    for (auto& el : v5)
    {
        it = arrayCard.begin();
        if (it_v == v5.end() - 1)
        {
            advance(it, el);
            it->setCondition(conditions::open);
        }
        else
        {
            advance(it, el);
            it->setCondition(conditions::closed);
            it_v++;
        }
    }
    it_v = v6.begin();
    for (auto& el : v6)
    {
        it = arrayCard.begin();
        if (it_v == v6.end() - 1)
        {
            advance(it, el);
            it->setCondition(conditions::open);
        }
        else
        {
            advance(it, el);
            it->setCondition(conditions::closed);
            it_v++;
        }
    }
    it_v = v7.begin();
    for (auto& el : v7)
    {
        it = arrayCard.begin();
        if (it_v == v7.end() - 1)
        {
            advance(it, el);
            it->setCondition(conditions::open);
        }
        else
        {
            advance(it, el);
            it->setCondition(conditions::closed);
            it_v++;
        }
    }
    for (auto& el : arrayCard)
    {
        if (el.getCondition() == conditions::none)
        {
            el.setCondition(conditions::is_shop);
        }
    }
}

void fielding::field_number_cols(vector<Card>& arrayCard, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7)
{
    for (auto& el : arrayCard)
    {
        el.setNumberCols(0);
    }
    for (auto& el : v1)
    {
        arrayCard[el].setNumberCols(1);
    }
    for (auto& el : v2)
    {
        arrayCard[el].setNumberCols(2);
    }
    for (auto& el : v3)
    {
        arrayCard[el].setNumberCols(3);
    }
    for (auto& el : v4)
    {
        arrayCard[el].setNumberCols(4);
    }
    for (auto& el : v5)
    {
        arrayCard[el].setNumberCols(5);
    }
    for (auto& el : v6)
    {
        arrayCard[el].setNumberCols(6);
    }
    for (auto& el : v7)
    {
        arrayCard[el].setNumberCols(7);
    }
}
