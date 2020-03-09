#include "spritePersonaje.h"

spritePersonaje::spritePersonaje(){
    
}

void spritePersonaje::set_sprite(int sprite, int cantidadX1, int cantidadY1, sf::Vector2i frm_act){
    //Variables
    cantidadX = cantidadX1; //Cantidad de grids en x
    cantidadY = cantidadY1; //Cantidad de grids en y
    sprite_actual = sprite; //Sprite a cargar
    txt_player = new sf::Texture(); //Textura de imagen
    sf::String archivo = "resources/Sprites/" + std::to_string(sprite) + ".png"; //Archivo a cargar

    //Cargo la textura
    txt_player->loadFromFile(archivo); //Cargo el recurso desde la ruta
    spr_player = new sf::Sprite(*txt_player); //Nuevo sprite apartir de textura
    tamFrame = sf::Vector2f(txt_player->getSize().x / cantidadX, txt_player->getSize().y / cantidadY); //Dimension de cada frame haciendo la operacion
    frame_actual = frm_act; // cogemos el frame que queremos utilizar
    seleccionar_frame();
}

void spritePersonaje::seleccionar_frame(){
    sf::IntRect rectangulo(frame_actual.x * tamFrame.x,frame_actual.y * tamFrame.y,tamFrame.x,tamFrame.y); //Construimos el rectangulo del tamaño del frame que queremos
    spr_player->setTextureRect(rectangulo); // le insertamos el recorte al sprite
}