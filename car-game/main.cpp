#include<iostream>
#include <SFML/Graphics.hpp>
#include<sstream> /// Pour les types string
#include<windows.h>
#include "voiture.h"
#include "jeux.h"
using namespace sf;
using namespace std;
/// convertir un nombre en chaine de caractères pour l'affichage du score
   inline string convertirScore(double nb){
        stringstream s;
        s<<nb;
        return s.str();
    }
int main()
{
    int i=0,j=0,k=0,randm , frontiere = 0;
    double score;
    double meilleurScore;
    int vitesse;
    float hauteur = 600;
    float largeur = 700;
    RenderWindow window(VideoMode(largeur, hauteur), "Jeux de voiture");

    Voiture joueur("voiture.png");
    Voiture traffic1("traffic1.png");
    Voiture traffic2("traffic2.png");
    Voiture traffic3("traffic3.png");
    Jeux ARP1("bg.png");
    Jeux ARP2("bg2.png");

    n:
    vitesse = 300;

        if(meilleurScore < score)
            meilleurScore = (int)score;

    score = 0;
    while (window.isOpen())
    {

        window.clear();
        ARP1.dessinerElement(window);
        window.display();
        Event b;
        while(window.pollEvent(b))
        {
            if(b.type==Event::Closed)
                window.close();
                if(b.type==Event::KeyPressed)
                {
                    if(b.key.code==Keyboard::Enter)
                    {
                        cout << "Touche Entrer pressé" << endl; /// Si on presse "Entrer" le jeux commence en exécutant les instructions
                        goto a;                                /// trouvées dans la section "a" par la ligne goto a;
                    }
                    if(b.key.code==Keyboard::Escape)
                    {
                        cout << "Touche Echape pressé" << endl;
                        window.close();             /// Si on presse "Echap" on sort du jeux
                    }

                }
        }
    }
    a:
    Texture b;
    b.loadFromFile("boom.png");
    Sprite boom(b);
    boom.move(70,300);
    joueur.positionInitialeJoueur();
    traffic1.positionInitialeTraffic1();
    traffic2.positionInitialeTraffic2();
    traffic3.positionInitialeTraffic3();
    Font myfont;
    Text myscore, meilleur_Score,text1,text2, text3;
    if(!myfont.loadFromFile("ariblk.ttf"))  /// Necessaire pour ajouter du texte
        printf("error");

    while(window.isOpen()){

        myscore.setFont(myfont);
        myscore.setString(convertirScore(score));  ///Changer le score en string
        myscore.setCharacterSize(30);
        myscore.setColor(Color(255,0,0));
        myscore.setPosition(560,140);
        score+=0.01;

        meilleur_Score.setFont(myfont);
        meilleur_Score.setString(convertirScore(meilleurScore)); /// Changer le meilleur score en string
        meilleur_Score.setCharacterSize(25);
        meilleur_Score.setColor(Color(0,255,0));
        meilleur_Score.setPosition(650,280);

        text1.setFont(myfont);
        text1.setString("JEUX VOITURE"); /// Texte
        text1.setCharacterSize(30); /// Taille du texte
        text1.setColor(Color(0,0,255)); /// Couleur (rouge)
        text1.setPosition(430,10); ///Position dans la fenetre

        text2.setFont(myfont);
        text2.setString("SCORE : ");
        text2.setCharacterSize(30);
        text2.setColor(Color(255,0,0));
        text2.setPosition(430,140);

        text3.setFont(myfont);
        text3.setString("Meilleur score : ");
        text3.setCharacterSize(25);
        text3.setColor(Color(0,255,0));
        text3.setPosition(430,280);

        joueur.abs = joueur.vsprite.getPosition().x;
        traffic1.ord = traffic1.vsprite.getPosition().y;
        traffic2.ord = traffic2.vsprite.getPosition().y;
        traffic3.ord = traffic3.vsprite.getPosition().y;

        /// Les tests
        /// Les condition ou le joueur perd le jeux
        if(joueur.abs == 50 && traffic1.ord>=400)
        {
            joueur.vsprite.setPosition(50,500);
            window.clear();
            ARP2.dessinerElement(window);
            joueur.dessinerVoiture(window);
            traffic1.dessinerVoiture(window);
            traffic2.dessinerVoiture(window);
            traffic3.dessinerVoiture(window);
            window.draw(myscore);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.draw(meilleur_Score);
            window.draw(boom);
            window.display();
            Sleep(3000);
            goto n;

        }
        if(joueur.abs == 190 && traffic2.ord>=400)
        {
            joueur.vsprite.setPosition(190,500);
            window.clear();
            ARP2.dessinerElement(window);
            joueur.dessinerVoiture(window);
            traffic1.dessinerVoiture(window);
            traffic2.dessinerVoiture(window);
            traffic3.dessinerVoiture(window);
            window.draw(myscore);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.draw(meilleur_Score);
            window.draw(boom);
            window.display();
            Sleep(3000);
            goto n;
        }
        if(joueur.abs == 330 && traffic3.ord>=400)
        {
            joueur.vsprite.setPosition(330,500);
            window.clear();
            ARP2.dessinerElement(window);
            joueur.dessinerVoiture(window);
            traffic1.dessinerVoiture(window);
            traffic2.dessinerVoiture(window);
            traffic3.dessinerVoiture(window);
            window.draw(myscore);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.draw(meilleur_Score);
            window.draw(boom);
            window.display();
            Sleep(3000);
            goto n;
        }
         /// Si la voiture traffic 1 (prend i comme compteur)  ou traffic 2(prend j comme compteur)  ou traffic 3 (prend k comme compteur)
        /// arrive à la fin d'écran on génère un nouveau nombre par hasard qui sera notre condition pour afficher des voitures traffic
        /// dans les emplacements que l'on veut

            if(i == 599 || j==599 || k==599)
               {
                   randm = (rand() % 6) + 1;
               }

        if(randm==1)
        {
            traffic1.bougerTraffic();
        }
        if(randm==2)
        {
            traffic2.bougerTraffic();
        }
        if(randm==3)
        {
            traffic3.bougerTraffic();
        }
        if(randm==4)
        {
            traffic1.bougerTraffic();
            traffic2.bougerTraffic();
        }
        if(randm==5)
        {
            traffic1.bougerTraffic();
            traffic3.bougerTraffic();
        }
        if(randm==6)
        {
            traffic2.bougerTraffic();
            traffic3.bougerTraffic();
        }
        //////////////////////////////////////////////////Vitesse/////////////////////////////////////////////////////////

        /// Si la voiture traffic 1 (prend i comme compteur)  ou traffic 2(prend j comme compteur)  ou traffic 3 (prend k comme compteur)
        /// arrive à la fin d'écran la vitesse augmente de "5" à chaque fois
        if(i==600)
        {

            if(score > 30 && score <60)
                vitesse = 500;
            if (score > 60 && score <100)
                vitesse = 590;
            if (score >100)
                vitesse = 700;

                i=0;
            traffic1.positionInitialeTraffic1();
        }

        if(j==600)
        {

            if(score > 30 && score <60)
                vitesse = 500;
            if (score > 60 && score <100)
                vitesse = 590;
            if (score >100)
                vitesse = 700;

                j=0;
            traffic2.positionInitialeTraffic2();
        }
        if(k==600)
        {

            if(score > 30 && score <60)
                vitesse = 500;
            if (score > 60 && score <100)
                vitesse = 590;
            if (score >100)
                vitesse = 700;

                k=0;
            traffic3.positionInitialeTraffic3();
        }

        i++,j++,k++;

            window.setFramerateLimit(vitesse); /// Ce bout de code controle la vitesse de tout le jeux

        Event e;
        while (window.pollEvent(e))
        {
            if(e.type == Event::Closed)
                window.close();

                  if(e.type == Event::KeyPressed)
                  {
                      if(e.key.code==Keyboard::Left && frontiere>=-100) /// Déplacer vers la gauche en cliquant sur <-
                      {
                        cout << "fleche gauche pressé" << endl;
                        frontiere = frontiere-140;
                        joueur.bougerJoueur(-140);
                      }
                      if(e.key.code==Keyboard::Right && frontiere<=100) /// Déplacer vers la droite en cliquant sur ->
                      {
                          cout << "fleche droite pressé" << endl;
                          frontiere = frontiere+140;
                          joueur.bougerJoueur(140);
                      }
                  }
        }
            window.clear();
            ARP2.dessinerElement(window);
            joueur.dessinerVoiture(window);
            traffic1.dessinerVoiture(window);
            traffic2.dessinerVoiture(window);
            traffic3.dessinerVoiture(window);
            window.draw(myscore);
            window.draw(meilleur_Score);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.display();
    }
    return 0;
}

