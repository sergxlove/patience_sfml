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
    Card(int index, int mast, int color, float pozitionX, float pozitionY,int number);//конструктор с параметрами
    Card();//базовый конструктор
    void setIndex(int index);//передача индекса
    void setMast(int mast);//передача масти
    void setColor(int color);//передача цвета
    void setPozition(float pozitionX, float PozitionY);//передача позиции
    void setNumber(int number);//передача порядкового номера
    void setUsers(bool users);//передача использования карты
    void setCondition(int condition);//передача состояния карты
    int getIndex();//возврат нидекса
    int getMast();//возврат масти
    int getColor();//возврат цвета
    float getPozitionX();//возврат позиции х
    float getPozitionY();//возврат позиции у
    int getNumber();//возврат порядкового номера
    bool getUsers();//возврат использования карты
    int getCondition();//возврат состояния карты
private:
    int index;//индекс карты
    int mast;//масть карты
    int color;//цвет карты
    float pozitionX;//позиция по х
    float pozitionY;//позиция по у
    int number;//порядковый номер элемента
    bool users;//использование карты
    int condition;//состояние карты
};
inline vector<Card> fieldArray();//заполнение массива карт
inline vector<Sprite> field_array_for_card(Texture* texture);//заполнение массива спрайтов карт
inline vector<int> field_cols(vector<Card>* check, int size);//заполнение колонки
inline vector<int>field_array_shop(vector<Card>* check);//заполнение массива магазина картами
inline vector<Sprite> field_array_sprite(Texture* texture, vector<Card>* arrayCard);//заполнение массива для отрисовки
inline void first_draw_all_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7);
inline void field_conditions(vector<Card>* arrayCard, vector<int>* v1, vector<int>* v2, vector<int>* v3, vector<int>* v4, vector<int>* v5, vector<int>* v6, vector<int>* v7, vector<int>* slot_v1, vector<int>* slot_v2, vector<int>* slot_v3, vector<int>* slot_v4, vector<int>* shop_arr);//заполнение состояния карты
inline void draw_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7);
inline vector<int>& getVector(int value, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7);
inline void swaps_card(vector<int>* past, vector<int>* current);

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
int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1600, 900), "Patience");
    Clock clock;
    //оформление
    vector<Card> arrayCard = fieldArray();
    Image all_card;
    all_card.loadFromFile("images/cards.png");
    Texture texture_cards;
    texture_cards.loadFromImage(all_card);
    Sprite shop_spr;//иконка магазина
    shop_spr.setTexture(texture_cards);
    shop_spr.setTextureRect(IntRect(2160, 20, 164, 230));
    shop_spr.setPosition(50, 50);
    shop_spr.setScale(0.8f, 0.8f);
    Sprite closed_card;//иконка закрытой карты
    closed_card.setTexture(texture_cards);
    closed_card.setTextureRect(IntRect(2160, 482, 164, 230));
    closed_card.setScale(0.8f, 0.8f);
    //
    //
    //
    vector<Sprite> slot_for_card = field_array_for_card(&texture_cards);//массив спрайтов всех карт
    vector<int> cols_v1 = field_cols(&arrayCard, 1);//первый столбец карт
    vector<int> cols_v2 = field_cols(&arrayCard, 2);//второй столбец карт
    vector<int> cols_v3 = field_cols(&arrayCard, 3);//третий столбец карт
    vector<int> cols_v4 = field_cols(&arrayCard, 4);//четвертый столбец карт
    vector<int> cols_v5 = field_cols(&arrayCard, 5);//пятый столбец карт
    vector<int> cols_v6 = field_cols(&arrayCard, 6);//шестой столбец карт 
    vector<int> cols_v7 = field_cols(&arrayCard, 7);//седьмой столбец карт
    vector<int> slot_v1;//первый слот карт
    vector<int> slot_v2;//второй слот карт
    vector<int> slot_v3;//третий слот карт
    vector<int> slot_v4;//четвертый слот карт
    vector<int> arr_shop = field_array_shop(&arrayCard);//массив карт в магазине
    vector<Sprite> arr_sprites = field_array_sprite(&texture_cards, &arrayCard);//массив для отрисовки карт
    vector<int>* past_v = nullptr;
    vector<int>* current_v = nullptr;
    random_shuffle(arr_shop.begin(), arr_shop.end());
    field_conditions(&arrayCard, &cols_v1, &cols_v2, &cols_v3, &cols_v4, &cols_v5, &cols_v6, &cols_v7, &slot_v1, &slot_v2, &slot_v3, &slot_v4, &arr_shop);
    int count = 0;
    bool first = true;
    bool dragging = false;
    bool check = false;
    Vector2f offset;
    Vector2f currentPoz;
    int dragging_index = -1;
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
                        for (int i = 0;i < arr_sprites.size();i++)
                        {
                            if (arr_sprites[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && arrayCard[i].getCondition() == conditions::open)
                            {
                                dragging = true;
                                offset = Vector2f(event.mouseButton.x, event.mouseButton.y) - arr_sprites[i].getPosition();
                                currentPoz = arr_sprites[i].getPosition();
                                dragging_index = i;
                                break;
                            }
                        }
                    }
                }
                if (event.type == Event::MouseButtonReleased)
                {
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        dragging = false;
                        if (dragging_index != -1)
                        {
                            check = false;
                            *past_v = getVector(dragging_index, cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7);
                            for (int i = 0;i < arr_sprites.size();i++)
                            {
                                if (arr_sprites[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && arrayCard[i].getCondition() == conditions::open)
                                {
                                    //*current_v = getVector(i, cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7);
                                    check = true;
                                }
                            }
                            if (check == false)
                            {
                                arr_sprites[dragging_index].setPosition(currentPoz);
                            }
                        }
                    }
                }
            }
            if (dragging&&!check)
            {
                arr_sprites[dragging_index].setPosition(Vector2f(Mouse::getPosition(window))-offset);
            }
            window.clear();
            window.draw(shop_spr);
            for (auto &el : slot_for_card)
            {
                window.draw(el);
            }
            window.draw(arr_sprites[arr_shop[count]]);
            if (first)
            {
                first_draw_all_cols(window, closed_card, arrayCard, arr_sprites, cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7);
                first = false;
            }
            else
            {
                draw_cols(window, closed_card, arrayCard, arr_sprites, cols_v1, cols_v2, cols_v3, cols_v4, cols_v5, cols_v6, cols_v7);
            }
            if (dragging)
            {
                window.draw(arr_sprites[dragging_index]);
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
inline vector<Card> fieldArray()
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
inline vector<int> field_cols(vector<Card>* check, int size)
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
        if (it->getUsers() == false)
        {
            result.push_back(value);
            it->setUsers(true);
            i++;
        }
    }
    return result;
}
inline vector<int>field_array_shop(vector<Card>* check)
{
    vector<int> result;
    int count = 0;
    result.reserve(24);
    for (auto it = check->begin();it != check->end();it++)
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
inline void first_draw_all_cols(RenderWindow& window, Sprite &closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7)
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
inline void field_conditions(vector<Card>* arrayCard, vector<int>* v1, vector<int>* v2, vector<int>* v3, vector<int>* v4, vector<int>* v5, vector<int>* v6, vector<int>* v7, vector<int>* slot_v1, vector<int>* slot_v2, vector<int>* slot_v3, vector<int>* slot_v4, vector<int>* shop_arr)
{
    auto it = arrayCard->begin();
    if (!slot_v1->empty())
    {
        for (auto& el : *slot_v1)
        {
            advance(it, el);
            it->setCondition(conditions::is_slot);
            it = arrayCard->begin();
        }
    }
    if (!slot_v2->empty())
    {
        for (auto& el : *slot_v2)
        {
            advance(it, el);
            it->setCondition(conditions::is_slot);
            it = arrayCard->begin();
        }
    }
    if (!slot_v3->empty())
    {
        for (auto& el : *slot_v3)
        {
            advance(it, el);
            it->setCondition(conditions::is_slot);
            it = arrayCard->begin();
        }
    }
    if (!slot_v4->empty())
    {
        for (auto& el : *slot_v4)
        {
            advance(it, el);
            it->setCondition(conditions::is_slot);
            it = arrayCard->begin();
        }
    }
    auto it_v = v1->begin();
    for (auto& el : *v1)
    {
        it = arrayCard->begin();
        if (it_v == v1->end() - 1)
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
    it_v = v2->begin();
    for (auto& el : *v2)
    {
        it = arrayCard->begin();
        if (it_v == v2->end() - 1)
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
    it_v = v3->begin();
    for (auto& el : *v3)
    {
        it = arrayCard->begin();
        if (it_v == v3->end() - 1)
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
    it_v = v4->begin();
    for (auto& el : *v4)
    {
        it = arrayCard->begin();
        if (it_v == v4->end() - 1)
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
    it_v = v5->begin();
    for (auto& el : *v5)
    {
        it = arrayCard->begin();
        if (it_v == v5->end() - 1)
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
    it_v = v6->begin();
    for (auto& el : *v6)
    {
        it = arrayCard->begin();
        if (it_v == v6->end() - 1)
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
    it_v = v7->begin();
    for (auto& el : *v7)
    {
        it = arrayCard->begin();
        if (it_v == v7->end() - 1)
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
    for (auto& el : *arrayCard)
    {
        if (el.getCondition() == conditions::none)
        {
            el.setCondition(conditions::is_shop);
        }
    }
}
inline void draw_cols(RenderWindow& window, Sprite& closed_card, vector<Card>& arr, vector<Sprite>& sprite, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7)
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
inline vector<int>& getVector(int value, vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7)
{
    bool check = false;
    for (auto& el : v1)
    {
        if (el == value)
        {
            check = true;
        }
        if (check)
        {
            return v1;
        }
    }
    for (auto& el : v2)
    {
        if (el == value)
        {
            check = true;
        }
        if (check)
        {
            return v2;
        }
    }
    for (auto& el : v3)
    {
        if (el == value)
        {
            check = true;
        }
        if (check)
        {
            return v3;
        }
    }
    for (auto& el : v4)
    {
        if (el == value)
        {
            check = true;
        }
        if (check)
        {
            return v4;
        }
    }
    for (auto& el : v5)
    {
        if (el == value)
        {
            check = true;
        }
        if (check)
        {
            return v5;
        }
    }
    for (auto& el : v6)
    {
        if (el == value)
        {
            check = true;
        }
        if (check)
        {
            return v6;
        }
    }
    for (auto& el : v7)
    {
        if (el == value)
        {
            check = true;
        }
        if (check)
        {
            return v7;
        }
    }
}
inline void swaps_card(vector<int>* past, vector<int>* current)
{

}

