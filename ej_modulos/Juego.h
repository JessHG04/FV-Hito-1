#pragma once
#include <SFML/Graphics.hpp>
#include "Jugador.h"
class Juego{
    public:
        Juego(sf::Vector2u tam_pantalla);
        void iniciar(); //Inicia variables y diferentes aspectos
        void dibujar(); //dibujar elementos
        void logica(); // procesa logicas del juego
        void procesar_eventos(); // elementos de entrada, teclado...
        void cortarEventoDash(int distancia);

    private:
        bool gameover = false;
        //Creamos al jugador
        Jugador *j1;
        //El evento que se recibe
        sf::Event *evento;
        // La ventana de nuestro juego
         sf::RenderWindow *ventana;
         //Creamos el reloj
         sf::Clock *reloj1;
         sf::Time *crono1;
         int fps;
};