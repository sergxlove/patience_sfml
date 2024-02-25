#include "SFML\Graphics.hpp"
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <memory>
using namespace std;
using namespace sf;
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
enum conditions
{
    open,
    is_shop,
    is_slot,
    closed,
    none
};
class Card
{
public:
    Card(int index, int mast, int color, float pozitionX, float pozitionY, int number);//конструктор с параметрами
    Card();//базовый конструктор
    void setIndex(int index);//передача индекса
    void setMast(int mast);//передача масти
    void setColor(int color);//передача цвета
    void setPozition(float pozitionX, float PozitionY);//передача позиции
    void setNumber(int number);//передача порядкового номера
    void setUsers(bool users);//передача использования карты
    void setCondition(int condition);//передача состояния карты
    void setNumberCols(int number_cols);
    int getIndex();//возврат нидекса
    int getMast();//возврат масти
    int getColor();//возврат цвета
    float getPozitionX();//возврат позиции х
    float getPozitionY();//возврат позиции у
    int getNumber();//возврат порядкового номера
    bool getUsers();//возврат использования карты
    int getCondition();//возврат состояния карты
    int getNumberCols();
private:
    int index;//индекс карты
    int mast;//масть карты
    int color;//цвет карты
    float pozitionX;//позиция по х
    float pozitionY;//позиция по у
    int number;//порядковый номер элемента
    bool users;//использование карты
    int condition;//состояние карты
    int number_cols;//номер колонки в которой находится карта
};
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
class drawing
{
public:
    void first_draw_all_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7);
    void draw_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7);

};
class return_ref
{
public: 
    vector<int>& get_ref(vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7, int poz);
};
class change_vectors
{
public:
    void swaps_card(vector<int>& first_v, vector<int>& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols);
};
int main()
{
	srand(time(NULL));
    RenderWindow window(VideoMode(1600, 900), "Patience");
    Clock clock;
    fielding f;
    drawing d;
    return_ref r;
    change_vectors c;
    Image all_card;
    Image back_image;
    all_card.loadFromFile("images/cards.png");
    back_image.loadFromFile("images/back_image.jpg");
    Texture texture_cards;
    Texture texture_back_image;
    texture_cards.loadFromImage(all_card);
    texture_back_image.loadFromImage(back_image);
    Sprite shop_spr;//иконка магазина
    shop_spr.setTexture(texture_cards);
    shop_spr.setTextureRect(IntRect(2160, 20, 164, 230));
    shop_spr.setPosition(50, 50);
    shop_spr.setScale(0.8f, 0.8f);
    Sprite closed_card;//иконка закрытой карты
    closed_card.setTexture(texture_cards);
    closed_card.setTextureRect(IntRect(2160, 482, 164, 60));
    closed_card.setScale(0.8f, 0.8f);
    Sprite back_spr;
    back_spr.setTexture(texture_back_image);
    back_spr.setTextureRect(IntRect(0, 0, 1600, 900));
    back_spr.setPosition(0, 0);
    vector<Card> arrayCard = f.fieldArray();
    vector<Sprite> slot_for_card = f.field_array_for_card(&texture_cards);//массив спрайтов всех карт
    vector<int> cols_v1 = f.field_cols(arrayCard, 1);//первый столбец карт
    vector<int> cols_v2 = f.field_cols(arrayCard, 2);//второй столбец карт
    vector<int> cols_v3 = f.field_cols(arrayCard, 3);//третий столбец карт
    vector<int> cols_v4 = f.field_cols(arrayCard, 4);//четвертый столбец карт
    vector<int> cols_v5 = f.field_cols(arrayCard, 5);//пятый столбец карт
    vector<int> cols_v6 = f.field_cols(arrayCard, 6);//шестой столбец карт 
    vector<int> cols_v7 = f.field_cols(arrayCard, 7);//седьмой столбец карт
    vector<int> slot_v1;//первый слот карт
    vector<int> slot_v2;//второй слот карт
    vector<int> slot_v3;//третий слот карт
    vector<int> slot_v4;//четвертый слот карт
    vector<int> arr_shop = f.field_array_shop(arrayCard);//массив карт в магазине
    vector<Sprite> arr_sprites = f.field_array_sprite(&texture_cards, arrayCard);//массив для отрисовки карт
    bool first_start = true;
    bool draging = false;
    int dragging_index = 0;
    float dx = 0.0f;
    float dy = 0.0f;
    float step_x = 0.0f;
    float step_y = 0.0f;
    float total_step_x = 0.0f;
    float total_step_y = 0.0f;
    int count = 0;
    float start_x = 0.0f;
    float start_y = 0.0f;
    bool return_sprite = false;
    bool collission = false;
    int current_cols = 0;
    int future_cols = 0;
    random_shuffle(arr_shop.begin(), arr_shop.end());
    f.field_conditions(arrayCard, cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7, slot_v1, slot_v2, slot_v3, slot_v4, arr_shop);
    f.field_number_cols(arrayCard, cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7);
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
                        for (int i = 0;i < arr_sprites.size();i++)
                        {
                            if (arr_sprites[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && arrayCard[i].getCondition() == conditions::open)
                            {
                                cout << "x = " << event.mouseButton.x << " y = " << event.mouseButton.y << " i = " << i << endl;
                                dragging_index = i;
                                draging = true;
                                dx = Mouse::getPosition(window).x - arr_sprites[i].getPosition().x;
                                dy = Mouse::getPosition(window).y - arr_sprites[i].getPosition().y;
                                start_x = arr_sprites[i].getPosition().x;
                                start_y = arr_sprites[i].getPosition().y;
                                cout << "x = " << Mouse::getPosition(window).x << " y = " << Mouse::getPosition(window).y << " i = " << i << endl;
                                return_sprite = false;
                                current_cols = arrayCard[i].getNumberCols();
                                cout << "cols = " << current_cols << endl;
                                break;
                            }
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased)
                {
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        cout << "released button x = " << event.mouseButton.x << " y = " << event.mouseButton.y << endl;
                        draging = false;
                        for (int i = 0;i < arr_sprites.size();i++)
                        {
                            if (i == dragging_index)
                            {
                                continue;
                            }
                            if (arr_sprites[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x, arr_sprites[dragging_index].getPosition().y) || arr_sprites[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x + 164.2, arr_sprites[dragging_index].getPosition().y))
                            {
                                future_cols = arrayCard[i].getNumberCols();
                                if (future_cols != current_cols)
                                {
                                    collission = true;
                                    cout << "collision" << endl;
                                    cout << "cols collision = " << future_cols << endl;
                                    break;
                                }
                                else
                                {
                                    collission = false;
                                    cout << "edentifity cols" << endl;
                                }
                            }
                            else
                            {
                                collission = false;
                            }
                        }
                        if (collission)
                        {
                            return_sprite = false;
                            c.swaps_card(r.get_ref(cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7, current_cols), r.get_ref(cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7, future_cols), arrayCard,arr_sprites, future_cols);
                        }
                        else
                        {
                            total_step_x = arr_sprites[dragging_index].getPosition().x - start_x;
                            total_step_y = arr_sprites[dragging_index].getPosition().y - start_y;
                            step_x = total_step_x / 10;
                            step_y = total_step_y / 10;
                            count = 0;
                            return_sprite = true;
                        }
                    }
                }
            }
            if (draging)
            {
                arr_sprites[dragging_index].setPosition(Mouse::getPosition(window).x - dx, Mouse::getPosition(window).y - dy);
            }
            if (count < 10 && return_sprite)
            {
                count++;
                arr_sprites[dragging_index].setPosition(arr_sprites[dragging_index].getPosition().x - step_x, arr_sprites[dragging_index].getPosition().y - step_y);
            }
            window.clear();
            window.draw(back_spr);
            window.draw(shop_spr);
            for (auto& el : slot_for_card)
            {
                window.draw(el);
            }
            if (first_start)
            {
                d.first_draw_all_cols(window, closed_card, arrayCard, arr_sprites, cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7);
                first_start = false;
            }
            else
            {
                d.draw_cols(window, closed_card, arrayCard, arr_sprites, cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7);
            }
            window.display();
            clock.restart();
        }
    }
	return 0;
}
Card::Card(int index, int mast, int color, float pozitionX, float pozitionY, int number)
{
    this->index = index;
    this->mast = mast;
    this->color = color;
    this->pozitionX = pozitionX;
    this->pozitionY = pozitionY;
    this->number = number;
    this->users = false;
    this->condition = conditions::none;
    this->number_cols = 0;
}

Card::Card()
{
    this->index = 0;
    this->mast = 0;
    this->color = 0;
    this->pozitionX = 0.0f;
    this->pozitionY = 0.0f;
    this->number = 0;
    this->users = false;
    this->condition = conditions::none;
    this->number_cols = 0;
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
void Card::setNumber(int number)
{
    this->number = number;
}
void Card::setUsers(bool users)
{
    this->users = users;
}
void Card::setCondition(int condition)
{
    this->condition = condition;
}
void Card::setNumberCols(int number_cols)
{
    this->number_cols = number_cols;
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
int Card::getNumber()
{
    return number;
}
bool Card::getUsers()
{
    return users;
}
int Card::getCondition()
{
    return condition;
}

int Card::getNumberCols()
{
    return number_cols;
}

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

vector<int>& return_ref::get_ref(vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7, int poz)
{
    switch (poz)
    {
    case 1:
        return v1;
        break;
    case 2:
        return v2;
        break;
    case 3:
        return v3;
        break;
    case 4:
        return v4;
        break;
    case 5:
        return v5;
        break;
    case 6:
        return v6;
        break;
    case 7:
        return v7;
        break;
    default:
        return v1;
        break;
    }
}

void change_vectors::swaps_card(vector<int>& first_v, vector<int>& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols)
{
    last_v.push_back(first_v[first_v.size() - 1]);
    arr[first_v[first_v.size() - 1]].setNumberCols(cols);
    first_v.erase(first_v.begin() + (first_v.size() - 1));
    if (first_v.size() != 0)
    {
        arr[first_v[first_v.size() - 1]].setCondition(conditions::open);
    }
    arr_spr[last_v[last_v.size()-1]].setPosition(200.0f * cols, 300.0f + (50.0f * (last_v.size() - 1)));
}
