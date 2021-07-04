#include "voiture.h"
#include<iostream>

Voiture::Voiture(){}
Voiture::Voiture(std::string image)
    {
        if(!vtexture.loadFromFile(image)){
            std::cerr << "Erreur\n";
        }
        vsprite.setTexture(vtexture);
    }
void Voiture::dessinerVoiture(sf::RenderWindow &window){
    window.draw(vsprite);
    }
    void Voiture::bougerJoueur(int x)
    {
        vsprite.move(x,0);
    }
    void Voiture::bougerTraffic()
    {
        vsprite.move(0,1);
    }
    void Voiture::positionInitialeJoueur()
    {
     vsprite.setPosition(190,500);
    }
    void Voiture::positionInitialeTraffic1()
    {
     vsprite.setPosition(50,-100);
    }
    void Voiture::positionInitialeTraffic2()
    {
     vsprite.setPosition(190,-100);
    }
    void Voiture::positionInitialeTraffic3()
    {
     vsprite.setPosition(330,-100);
    }

