#pragma once
#include <SFML/Graphics.hpp>
#include "spritePersonaje.h"
#include <iostream>
#include <string>

class Jugador{
    public:
        //Constructor
        Jugador(int sprite, int cantidadX1, int cantidadY1, sf::Vector2i frm_act);
        //Destructor
        ~Jugador();

        // Obtener el sprite del jugador
        sf::Sprite get_sprite(){ 
            return *spriteJugador->spr_player;
        }
        sf::Vector2f get_posicion(){ 
            return posicion;
        }
        void set_posicion(sf::Vector2f pos){
            posicion = pos;
            spriteJugador->spr_player->setPosition(posicion);
        }
        
    private:
        spritePersonaje * spriteJugador;
        //Posicion del jugador
        sf::Vector2f posicion;
        int vida;
};