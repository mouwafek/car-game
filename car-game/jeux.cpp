#include "jeux.h"
#include<iostream>


    Jeux::Jeux(){}

    Jeux::Jeux(std::string image){
    if(!jtexture.loadFromFile(image)){
            std::cerr << "Erreur\n";
        }
        jsprite.setTexture(jtexture);
    }
    void Jeux::dessinerElement(sf::RenderWindow &window){
    window.draw(jsprite);
    }
