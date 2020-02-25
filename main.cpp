#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

#define kVel 3

int main() {

  MiModulo *mod = new MiModulo();
  int cambiasprite = 0;
  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "Gremory Hole");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  sf::Texture tex2;

  if (!tex.loadFromFile("resources/Sprites/Guerrera/mercedes.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  if (!tex.loadFromFile("resources/Sprites/Guerrera/mercedesatk.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);
  sf::Sprite spriteatk(tex2);

  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 58, 0 * 58, 58, 58));

  // Lo dispongo en la pantalla
  sprite.setPosition(100, 400);
  // Declaro el tiempo de movimiento del sprite
  /*sf::Time tiempo = sf::seconds(0.2f);
  sf::Vector2f velocidad;
  float rapidez = 0.2f;*/

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
        //sf::sleep (tiempo);
          if(cambiasprite == 4){
            cambiasprite = 0;
          }
          sprite.setTextureRect(sf::IntRect(cambiasprite * 58, 3 * 58, 58, 58));
          //Escala por defecto
          cambiasprite ++;
          sprite.setScale(1, 1);
          sprite.move(kVel,0);
          break;

        case sf::Keyboard::Left:
        //sf::sleep (tiempo);
          if(cambiasprite == 4){
            cambiasprite = 0;
          }
          sprite.setTextureRect(sf::IntRect(cambiasprite * 58, 2 * 58, 58, 58));
          
          //Reflejo vertical
          cambiasprite ++;
          sprite.setScale(1, 1);
          sprite.move(-kVel,0);
          break;

        case sf::Keyboard::Space:
            spriteatk.setTextureRect(sf::IntRect( 0 * 99, 2 * 145, 99, 145));
          break;



        /*case sf::Keyboard::Up:
          sprite.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
          sprite.move(0, -kVel);
          break;

        case sf::Keyboard::Down:
          sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
          sprite.move(0, kVel);
          break;
*/
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

    window.clear();
    window.draw(sprite);
    window.display();
  }

  return 0;
}