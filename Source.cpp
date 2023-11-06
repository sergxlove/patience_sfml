#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <iterator>
#include <algorithm>
using namespace sf;
using namespace std;
class Card
{
public:
    Card(int index, int mast, int color, float pozitionX, float pozitionY,bool visible);
    Card();
    void setIndex(int index);
    void setMast(int mast);
    void setColor(int color);
    void setPozition(float pozitionX, float PozitionY);
    void setVisible(bool visible);
    int getIndex();
    int getMast();
    int getColor();
    float getPozitionX();
    float getPozitionY();
    bool getVisible();
private:
    int index;
    int mast;
    int color;
    float pozitionX;
    float pozitionY;
    bool visible;
};
inline vector<Card> fieldArray();
inline vector<Sprite> field_array_for_card(Texture* texture);
inline vector<int> field_cols(vector<bool>* check, int size);
inline vector<bool> field_check_array();
inline vector<int> field_array_shop(vector<bool>* check);
inline vector<Sprite> field_array_sprite(Texture* texture, vector<Card>* arrayCard);
inline void draw_all_cols(RenderWindow* window, vector<Sprite> &sprite, vector<int>* v1, vector<int>* v2, vector<int>* v3, vector<int>* v4, vector<int>* v5, vector<int>* v6, vector<int>* v7);
inline vector<int> field_is_open(vector<int>* v1, vector<int>* v2, vector<int>* v3, vector<int>* v4, vector<int>* v5, vector<int>* v6, vector<int>* v7);

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
    RenderWindow window(VideoMode(1600, 900), "Patience");
    Clock clock;
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
    Sprite closed_card;
    closed_card.setTexture(texture_cards);
    closed_card.setTextureRect(IntRect(2160, 482, 164, 230));
    closed_card.setScale(0.8f, 0.8f);
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
    vector<Sprite> arr_sprites = field_array_sprite(&texture_cards, &arrayCard);
    vector<bool> arr_is_open;
    random_shuffle(arr_shop.begin(), arr_shop.end());
    int count = 0;
    bool ch = true;
    while (window.isOpen())
    {
        Event event;
        if (clock.getElapsedTime().asSeconds() > 1.0f / 15.0f)
        {
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
                            count++;
                            if (count == arr_shop.size())
                            {
                                count = 0;
                            }
                        }
                    }
                }
            }
            window.clear();
            window.draw(shop_spr);
            for (auto el : slot_for_card)
            {
                window.draw(el);
            }
            window.draw(arr_sprites[arr_shop[count]]);
            draw_all_cols(&window, arr_sprites, &cols_v1, &cols_v2, &cols_v3, &cols_v4, &cols_v5, &cols_v6, &cols_v7);
            window.display();
            clock.restart();
        }
    }
    return 0;
}

Card::Card(int index, int mast, int color, float pozitionX, float pozitionY,bool visible)
{
    this->index = index;
    this->mast = mast;
    this->color = color;
    this->pozitionX = pozitionX;
    this->pozitionY = pozitionY;
    this->visible = visible;
}
Card::Card()
{
    this->index = 0;
    this->mast = 0;
    this->color = 0;
    this->pozitionX = 0.0f;
    this->pozitionY = 0.0f;
    this->visible = false;
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
void Card::setVisible(bool visible)
{
    this->visible = visible;
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
bool Card::getVisible()
{
    return visible;
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
inline vector<Sprite> field_array_sprite(Texture* texture, vector<Card>* arrayCard)
{
    vector<Sprite> result;
    result.reserve(52);
    for (auto &cards : *arrayCard)
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
inline void draw_all_cols(RenderWindow* window, vector<Sprite> &sprite, vector<int>* v1, vector<int>* v2, vector<int>* v3, vector<int>* v4, vector<int>* v5, vector<int>* v6, vector<int>* v7)
{
    float total_x = 200.0f;
    float total_y = 300.0f;
    for (auto& el : *v1)
    {
        sprite[el].setPosition(total_x, total_y);
        window->draw(sprite[el]);
        total_y += 50;
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : *v2)
    {
        sprite[el].setPosition(total_x, total_y);
        window->draw(sprite[el]);
        total_y += 50;
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : *v3)
    {
        sprite[el].setPosition(total_x, total_y);
        window->draw(sprite[el]);
        total_y += 50;
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : *v4)
    {
        sprite[el].setPosition(total_x, total_y);
        window->draw(sprite[el]);
        total_y += 50;
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : *v5)
    {
        sprite[el].setPosition(total_x, total_y);
        window->draw(sprite[el]);
        total_y += 50;
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : *v6)
    {
        sprite[el].setPosition(total_x, total_y);
        window->draw(sprite[el]);
        total_y += 50;
    }
    total_x += 200.0f;
    total_y = 300.0f;
    for (auto& el : *v7)
    {
        sprite[el].setPosition(total_x, total_y);
        window->draw(sprite[el]);
        total_y += 50;
    }
}
inline vector<int> field_is_open(vector<int>* v1, vector<int>* v2, vector<int>* v3, vector<int>* v4, vector<int>* v5, vector<int>* v6, vector<int>* v7)
{
    vector<int>result;
    return result;
}
