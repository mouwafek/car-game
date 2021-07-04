#include <SFML/Graphics.hpp>

#ifndef JEUX_H
#define JEUX_H


class Jeux
{
public:
    sf::Texture jtexture;
    sf::Sprite jsprite;
    Jeux();
    Jeux(std::string);
    void dessinerElement(sf::RenderWindow &);
};
#endif // JEUX_H
