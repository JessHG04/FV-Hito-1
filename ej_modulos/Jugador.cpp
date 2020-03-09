#include "Jugador.h"

Jugador::Jugador(int sprite, int cantidadX1, int cantidadY1, sf::Vector2i frm_act){
    //Inicializo la vida
    vida = 10;
    spriteJugador = new spritePersonaje();
    spriteJugador->set_sprite(sprite, cantidadX1, cantidadY1, frm_act);
}