#include "Map.h"

int main(){
    //Creacion de ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Prueba mapa");

    //Objeto tipo Map
    Map *map = new Map();

    //Falta inicializar el mapa

    //GameLoop
    while(window.isOpen()){
        //Ventana en color blanco
        window.clear(sf::Color::White);

        //Dibujo el mapa revisar
        //window.draw(map);

        //Bucle de obtencion de eventos
        sf::Event event;
        while (window.pollEvent(event)){
            switch ((event.type)){
            case sf::Event::Closed:
                window.close();
                break;

            //Verificacion de mis teclas
            case sf::Event::KeyPressed:
                switch (event.key.code){
                    //Tecla escape para salir
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    default:
                        std::cout << event.key.code << std::endl;
                        break;
                }
            }
        }
    }
}