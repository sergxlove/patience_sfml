#include "drawing.h"
void drawing::first_draw_all_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7)
{
    float total_x = 200.0f;
    float total_y = 300.0f;
    for (auto& el : v1)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(total_x, total_y);
            sprite[el].setPosition(total_x, total_y);
            window.draw(closed_card);
            total_y += 50;
        }
        else
        {
            sprite[el].setPosition(total_x, total_y);
            window.draw(sprite[el]);
            total_y += 50;
        }
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : v2)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(total_x, total_y);
            sprite[el].setPosition(total_x, total_y);
            window.draw(closed_card);
            total_y += 50;
        }
        else
        {
            sprite[el].setPosition(total_x, total_y);
            window.draw(sprite[el]);
            total_y += 50;
        }
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : v3)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(total_x, total_y);
            sprite[el].setPosition(total_x, total_y);
            window.draw(closed_card);
            total_y += 50;
        }
        else
        {
            sprite[el].setPosition(total_x, total_y);
            window.draw(sprite[el]);
            total_y += 50;
        }
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : v4)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(total_x, total_y);
            sprite[el].setPosition(total_x, total_y);
            window.draw(closed_card);
            total_y += 50;
        }
        else
        {
            sprite[el].setPosition(total_x, total_y);
            window.draw(sprite[el]);
            total_y += 50;
        }
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : v5)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(total_x, total_y);
            sprite[el].setPosition(total_x, total_y);
            window.draw(closed_card);
            total_y += 50;
        }
        else
        {
            sprite[el].setPosition(total_x, total_y);
            window.draw(sprite[el]);
            total_y += 50;
        }
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : v6)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(total_x, total_y);
            sprite[el].setPosition(total_x, total_y);
            window.draw(closed_card);
            total_y += 50;
        }
        else
        {
            sprite[el].setPosition(total_x, total_y);
            window.draw(sprite[el]);
            total_y += 50;
        }
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : v7)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(total_x, total_y);
            sprite[el].setPosition(total_x, total_y);
            window.draw(closed_card);
            total_y += 50;
        }
        else
        {
            sprite[el].setPosition(total_x, total_y);
            window.draw(sprite[el]);
            total_y += 50;
        }
    }
}

void drawing::draw_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7)
{
    for (auto& el : v1)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(sprite[el].getPosition());
            window.draw(closed_card);
        }
        else if (arr[el].getCondition() == conditions::open)
        {
            window.draw(sprite[el]);
        }
    }
    for (auto& el : v2)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(sprite[el].getPosition());
            window.draw(closed_card);
        }
        else if (arr[el].getCondition() == conditions::open)
        {
            window.draw(sprite[el]);
        }
    }
    for (auto& el : v3)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(sprite[el].getPosition());
            window.draw(closed_card);
        }
        else if (arr[el].getCondition() == conditions::open)
        {
            window.draw(sprite[el]);
        }
    }
    for (auto& el : v4)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(sprite[el].getPosition());
            window.draw(closed_card);
        }
        else if (arr[el].getCondition() == conditions::open)
        {
            window.draw(sprite[el]);
        }
    }
    for (auto& el : v5)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(sprite[el].getPosition());
            window.draw(closed_card);
        }
        else if (arr[el].getCondition() == conditions::open)
        {
            window.draw(sprite[el]);
        }
    }
    for (auto& el : v6)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(sprite[el].getPosition());
            window.draw(closed_card);
        }
        else if (arr[el].getCondition() == conditions::open)
        {
            window.draw(sprite[el]);
        }
    }
    for (auto& el : v7)
    {
        if (arr[el].getCondition() == conditions::closed)
        {
            closed_card.setPosition(sprite[el].getPosition());
            window.draw(closed_card);
        }
        else if (arr[el].getCondition() == conditions::open)
        {
            window.draw(sprite[el]);
        }
    }
}

void drawing::draw_slots(RenderWindow& window, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& slot_1, vector<int>& slot_2, vector<int>& slot_3, vector<int>& slot_4)
{
    if (!slot_1.empty())
    {
        window.draw(sprite[slot_1[slot_1.size() - 1]]);
    }
    if (!slot_2.empty())
    {
        window.draw(sprite[slot_2[slot_2.size() - 1]]);
    }
    if (!slot_3.empty())
    {
        window.draw(sprite[slot_3[slot_3.size() - 1]]);
    }
    if (!slot_4.empty())
    {
        window.draw(sprite[slot_4[slot_4.size() - 1]]);
    }
}