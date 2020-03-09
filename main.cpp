#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/config.h"
#include "ej_modulos/Juego.h"
#include "ej_modulos/Jugador.h"

int main() {

  Juego *juego = new Juego(sf::Vector2u(800,600));
  return 0;
}
