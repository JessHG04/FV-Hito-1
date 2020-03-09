#include "Jugador.h"

Jugador::Jugador(int sprite, int cantidadX1, int cantidadY1 , sf::Vector2i frm_act){
    //Inicializo la vida
    vida = 10;
    //spriteJugador = new spritePersonaje();
    set_sprite(sprite, cantidadX1, cantidadY1, frm_act);
    vel_desp = 7.3f;
}

void Jugador::update(){ //Actuaiza fisicas del jugador
    //if(movimiento){
        set_translacion(velocidad);
    //}
}