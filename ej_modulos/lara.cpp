#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define kVel 5

#include "lara.h"

    lara::lara(){
        numVidas = 3;
        tex = new Texture();
        if (!tex->loadFromFile("resources/401003605_atk.png")) {
            std::cerr << "Error cargando la imagen 401003605_atk.png";
            exit(0);
        } 
        sprite = new Sprite(*tex);
        //Le pongo el centroide donde corresponde
        sprite->setOrigin(39, 32);
        //Cojo el sprite que me interesa por defecto del sheet
        sprite->setTextureRect(sf::IntRect(31, 12, 47, 52));
        
        // Lo dispongo en el centro de la pantalla
        sprite->setPosition(550, 240);
    }

    void lara::cambiarSprite(int x){
        if(x == 0){
            sprite->setTextureRect(sf::IntRect(31, 12, 47, 52));
        }
        if(x == 1){
            sprite->setTextureRect(sf::IntRect(228, 12, 73, 52));
        }
        if(x == 2){
            sprite->setTextureRect(sf::IntRect(115, 12, 78, 52));
        }
        sprite->setScale(1, 1);
    }

    void lara::restartSprite(){
        sprite->setTextureRect(sf::IntRect(31, 12, 47, 52));
        sprite->setScale(1, 1);
    }

    Sprite lara::devolverSprite(){
        return *sprite;
    }