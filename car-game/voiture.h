

#include <SFML/Graphics.hpp>

#ifndef VOITURE_H
#define VOITURE_H
class Voiture
{
public :
    int abs;
    int ord;
    sf::Texture vtexture;
    sf::Sprite vsprite;
    Voiture();
    Voiture(std::string);

    void dessinerVoiture(sf::RenderWindow &);

    void bougerJoueur(int);
    void bougerTraffic();
    void positionInitialeJoueur();
    void positionInitialeTraffic1();
    void positionInitialeTraffic2();
    void positionInitialeTraffic3();
};
#endif // VOITURE_H


