#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <iterator>
using namespace sf;
using namespace std;
class Card
{
public:
    Card(int index, int mast, int color, float pozitionX, float pozitionY);
    Card();
    void setIndex(int index);
    void setMast(int mast);
    void setColor(int color);
    void setPozition(float pozitionX, float PozitionY);
    int getIndex();
    int getMast();
    int getColor();
    float getPozitionX();
    float getPozitionY();
private:
    int index;
    int mast;
    int color;
    float pozitionX;
    float pozitionY;
};
inline vector<Card> fieldArray();
inline vector<Sprite> field_array_for_card(Texture* texture);
inline vector<int> field_cols(vector<bool>* check, int size);
inline vector<bool> field_check_array();
inline vector<int> field_array_shop(vector<bool>* check);
inline vector<Sprite> field_array_spriet(Texture* texture, vector<Card>* arrayCard);
enum masts
{
    hearts,
    cross,
    booby,
    peaks
};
enum colors
{
    red,
    black
};
int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1500, 900), "Patience");
    vector<Card> arrayCard = fieldArray();
    Image all_card;
    all_card.loadFromFile("images/cards.png");
    Texture texture_cards;
    texture_cards.loadFromImage(all_card);
    Sprite shop_spr;
    shop_spr.setTexture(texture_cards);
    shop_spr.setTextureRect(IntRect(2160, 20, 164, 230));
    shop_spr.setPosition(50, 50);
    shop_spr.setScale(0.8f, 0.8f);
    vector<Sprite> slot_for_card = field_array_for_card(&texture_cards);
    vector<bool> check_using = field_check_array();
    vector<int> cols_v1 = field_cols(&check_using, 1);
    vector<int> cols_v2 = field_cols(&check_using, 2);
    vector<int> cols_v3 = field_cols(&check_using, 3);
    vector<int> cols_v4 = field_cols(&check_using, 4);
    vector<int> cols_v5 = field_cols(&check_using, 5);
    vector<int> cols_v6 = field_cols(&check_using, 6);
    vector<int> cols_v7 = field_cols(&check_using, 7);
    vector<int> arr_shop = field_array_shop(&check_using);
    bool is_sprite_drag = false;
    Vector2f offset;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (shop_spr.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        is_sprite_drag = true;
                        offset = shop_spr.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
                    }
                }
            }
            else if (event.type == Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    is_sprite_drag = false;
                }
            }
            if (is_sprite_drag == true)
            {
                shop_spr.setPosition(Vector2f(Mouse::getPosition(window)) + offset);
            }
        }
        window.clear();
        window.draw(shop_spr);
        for (auto el : slot_for_card)
        {
            window.draw(el);
        }
        window.display();
    }
    return 0;
}

Card::Card(int index, int mast, int color, float pozitionX, float pozitionY)
{
    this->index = index;
    this->mast = mast;
    this->color = color;
    this->pozitionX = pozitionX;
    this->pozitionY = pozitionY;
}
Card::Card()
{
    this->index = 0;
    this->mast = 0;
    this->color = 0;
    this->pozitionX = 0.0f;
    this->pozitionY = 0.0f;
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
inline vector<Card> fieldArray()
{
    vector<Card> result;
    int totalIndex = 0;
    int cols = 0;
    result.reserve(52);
    for (int i = 0;i < 52;i++)
    {
        Card card;
        card.setIndex(totalIndex);
        card.setPozition(20 + (totalIndex * 164.2), 20 + (cols * 230));
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
inline vector<Sprite> field_array_for_card(Texture *texture)
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
inline vector<bool> field_check_array()
{
    vector<bool> result;
    result.reserve(52);
    for (int i = 0;i < 52;i++)
    {
        result.push_back(false);
    }
    return result;
}
inline vector<int> field_cols(vector<bool>* check, int size)
{
    vector<int> result;
    result.reserve(size);
    int value = 0;
    auto it = check->begin();
    for (int i = 0;i < size;)
    {
        value = rand() % 52;
        it = check->begin();
        advance(it, value);
        if (*it == false)
        {
            result.push_back(value);
            *it = true;
            i++;
        }
    }
    return result;
}
inline vector<int> field_array_shop(vector<bool>* check)
{
    vector<int> result;
    int count = 0;
    result.reserve(24);
    for (auto it = check->begin();it !=check->end();it++)
    {
        if (*it == false)
        {
            result.push_back(count);
            *it = true;
        }
        count++;
    }
    return result;
}
inline vector<Sprite> field_array_spriet(Texture* texture, vector<Card>* arrayCard)
{
    vector<Sprite> result;
    result.reserve(52);
    for (auto &cards : *arrayCard)
    {
        Sprite sprite;
        sprite.setTexture(*texture);
        sprite.setTextureRect(IntRect(cards.getPozitionX(), cards.getPozitionY(), 164, 230));
        sprite.setScale(0.8f, 0.8f);
        result.push_back(sprite);
    }
    return result;
}
