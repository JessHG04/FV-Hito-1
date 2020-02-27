#include "Juego.h"
#include <SFML/Graphics.hpp>

#define kVel 3

Juego::Juego(sf::Vector2u resolucion){
    //Creamos una ventana
    ventana = new sf::RenderWindow(sf::VideoMode(resolucion.x,resolucion.y), "Gremory Hole");
    //Iniciamos el juego
    iniciar();

    //bucle del juego
    while(ventana->isOpen()){
        while(ventana->pollEvent(*evento)){
            procesar_eventos();
        }
        
        dibujar();
    }
}

void Juego::iniciar(){
    j1 = new Jugador(1);
}

void Juego::dibujar(){
    ventana->draw(j1->get_sprite());
    ventana->display;
}

void Juego::logica(){

}

void Juego::procesar_eventos(){
    switch (evento->type)
    {
        case sf::Event::Closed:
            exit(1);
            break;
        case sf::Event::KeyPressed:
            // si se pulsta la tecla izquierda
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                    j1->set_posicion(sf::Vector2f(j1->get_posicion().x - kVel,(j1->get_posicion().y)));
            }
            // si se pulsa la tecla derecha
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    j1->set_posicion(sf::Vector2f(j1->get_posicion().x + kVel,(j1->get_posicion().y)));

            break;
        
        default:

        break;
    }
}
