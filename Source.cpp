#include <SFML/Graphics.hpp>
class Card
{
public:
private:
    int index;
    int mast;
    int color;
    float pozitionX;
    float pozitionY;
};
enum masts
{
    hearts,
    cross,
    booby,
    peaks
};
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
    return 0;
}