#include "Jugador.h"

Jugador::Jugador(int sprite){

    //El sprite actual 
    set_sprite(sprite);
    
    //Inicializo la vida
    vida = 10;
}

void Jugador::set_sprite(int sprite){
    sprite_actual = sprite;
    txt_player = new sf::Texture();
    sf::String archivo = "resources/Sprites/" + std::to_string(sprite) + ".png";
    //Cargo la textura
    txt_player->loadFromFile(archivo);
    spr_player = new sf::Sprite();
}