#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Jugador{
    public:
        //Constructor
        Jugador(int sprite);
        //Destructor
        ~Jugador();

        // Obtener el sprite del jugador
        sf::Sprite get_sprite(){ 
            return *spr_player;
        }
        sf::Vector2f get_posicion(){ 
            return posicion;
        }
        void set_posicion(sf::Vector2f pos){
            posicion = pos;
            spr_player->setPosition(posicion);
        }
        void set_sprite(int sprite);
    private:
        //Creo el sprite del jugador
        sf::Sprite *spr_player;
        //Textura para el sprite
        sf::Texture *txt_player;
        //Posicion del jugador
        sf::Vector2f posicion;
        // Sprite que va a usar
        int sprite_actual;
        int vida;
};