#include <SFML/Graphics.hpp>
#include <vector>
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
private:
    int index;
    int mast;
    int color;
    float pozitionX;
    float pozitionY;
};
vector<Card> fieldArray();
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
    RenderWindow window(VideoMode(800, 800), "Patience");
    vector<Card> arrayCard = fieldArray();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
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
vector<Card> fieldArray()
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