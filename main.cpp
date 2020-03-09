#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#include "include/config.h"
#include "ej_modulos/lara.h"
#include "ej_modulos/bala.h"
#include "ej_modulos/cuadradoD.h"

#define kVel 5

int main() {
  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

  lara *larita = new lara();
  bala *balera = new bala();
  cuadradoD *cuadri = new cuadradoD();

  Clock reloj, relojb;
  float sgs2 = relojb.getElapsedTime().asSeconds();
  float sgs = reloj.getElapsedTime().asSeconds();
  int x = 0;
  bool yasta = false, fin = false;
  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;
    while (window.pollEvent(event)) {

      switch (event.type) {

      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window.close();
        break;

      //Se pulsó una tecla, imprimo su codigo
      case sf::Event::KeyPressed:

        //Verifico si se pulsa alguna tecla de movimiento
        switch (event.key.code) {

        //Mapeo del cursor
        case sf::Keyboard::Right:

          break;

        case sf::Keyboard::Left:
          break;

        case sf::Keyboard::Up:
          break;

        case sf::Keyboard::Down:
          break;

        //Tecla ESC para salir
        case sf::Keyboard::Escape:
          window.close();
          break;

        //Cualquier tecla desconocida se imprime por pantalla su código
        default:
          std::cout << event.key.code << std::endl;
          break;
        }
      }
    }
    sgs2 = relojb.getElapsedTime().asSeconds();
    sgs = reloj.getElapsedTime().asSeconds();
      if(sgs >= 2 && yasta == false){
        larita->cambiarSprite(x);
        x++;
        if(x == 3){
          yasta = true;
          x = 0;
        }
        reloj.restart();
      }
    window.clear();
    window.draw(larita->devolverSprite());
    window.draw(cuadri->devolverSprite2());
    if(sgs2 >= 7.8){
      if(fin == false){
        window.draw(balera->devolverSprite());
        balera->movimientoBala();
      }
      larita->restartSprite();
    }
    if(fin == false){
      if(balera->devolverSprite().getGlobalBounds().intersects(cuadri->devolverSprite2().getGlobalBounds())){
        cout << "Colision con el cuadrado" << endl;
        delete balera;
        fin = true;
      }
    }
    window.display();
  }

  return 0;
}