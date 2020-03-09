#include "Juego.h"
#include <SFML/Graphics.hpp>




Juego::Juego(sf::Vector2u resolucion){
    //Creamos una ventana
    ventana = new sf::RenderWindow(sf::VideoMode(resolucion.x,resolucion.y), "Gremory Hole");
    //Iniciamos el juego
    iniciar();

    //----------------------------------------BUCLE DEL JUEGO------------------------------------------------------------------------------
    while(gameover != true){
        *crono1 = reloj1->getElapsedTime(); // Obtener tiempo transcurrido 

        if(crono1->asSeconds() > 0.08){ // comparamos si el tiempo transcurrido es 1 fps (1 frame) si es asi ejecuttamos un instante
            while(ventana->pollEvent(*evento)){
                procesar_eventos();
            }
            // Si sigue saltando la gravedad le sigue afectando
            if(j1->saltando){
                j1->vel_salto += 2.0f;
                if(!j1->movimiento)
                    j1->set_velocidad(sf::Vector2f(0,j1->vel_salto));
                else if(j1->direccion == izq)
                    j1->set_velocidad(sf::Vector2f(-j1->vel_desp,j1->vel_salto));
                else if(j1->direccion == der)
                    j1->set_velocidad(sf::Vector2f(j1->vel_desp,j1->vel_salto));
            }

            if(j1->movimiento){
                j1->animar();
            }

            j1->update();
            dibujar();
            //Si sigue saltando y llega a la posicion de donde salto se para
            //EN EL JUEGO CAMBIAR ESTA CONDICION POR LA COLISION CON EL MAPA PORQUE PUEDE SER QUE SE SUBA A UNA PLATAFORMA Y NO VUELVA A LA POSICION INICIAL
            if(j1->saltando && j1->posInicial.y == j1->get_posicion().y){
                j1->saltando = false;
                j1->movimiento = false;
                j1->vel_salto = -20.0f;
                j1->set_velocidad(sf::Vector2f(0,0));
                 if(j1->direccion == izq){
                        j1->set_sprite(1,4,4,sf::Vector2i(0,2));
                    }
                    
                    if(j1->direccion == der){
                        j1->set_sprite(1,4,4,sf::Vector2i(0,3));
                    }
            }
            reloj1->restart();
        }
    }
}

void Juego::iniciar(){
    fps = 60;
    reloj1 = new sf::Clock();
    crono1 = new sf::Time();
    j1 = new Jugador(1,4,4,sf::Vector2i(0,0));
    j1->set_posicion(sf::Vector2f(300,300));
    evento = new sf::Event();
}

void Juego::dibujar(){
    ventana->clear();
    ventana->draw(j1->get_sprite());
    ventana->display();
}

/*void Juego::logica(){

}*/

void Juego::procesar_eventos(){
            
                    
                

    switch (evento->type)
    {
        case sf::Event::Closed:
            exit(1);
            break;
        case sf::Event::KeyPressed:
            // si se pulsta la tecla izquierda
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                 j1->direccion = izq;

                
                    j1->movimiento = true;
                    j1->direccion = izq;
                    j1->set_frameY(2); 
                    j1->set_velocidad(sf::Vector2f(-j1->vel_desp,0));
                    //j1->set_posicion(sf::Vector2f(j1->get_posicion().x - j1->vel_desp,(j1->get_posicion().y)));
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        if(!j1->saltando){
                            j1->saltando = true;
                            if (j1->movimiento != true)
                                j1->posInicial = sf::Vector2f(j1->get_posicion().x, j1->get_posicion().y);
                            //j1->movimiento = true;
                            j1->set_velocidad(sf::Vector2f(0,j1->vel_salto));     
                        }
                    }
                }
            
            // si se pulsa la tecla derecha
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                j1->direccion = der;

                
                    j1->movimiento = true;
                    j1->direccion = der;
                    j1->set_frameY(3);
                    j1->set_velocidad(sf::Vector2f(j1->vel_desp,0));
                    //j1->set_posicion(sf::Vector2f(j1->get_posicion().x + j1->vel_desp,(j1->get_posicion().y)));
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        if(!j1->saltando){
                            j1->saltando = true;
                            if (j1->movimiento != true)
                                j1->posInicial = sf::Vector2f(j1->get_posicion().x, j1->get_posicion().y);
                            //j1->movimiento = true;
                            j1->set_velocidad(sf::Vector2f(0,j1->vel_salto));     
                        }
                    }
                
            }

//--------------------------SALTO-------------------------------------------------
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                if(!j1->saltando){
                    j1->saltando = true;
                    if (j1->movimiento != true)
                        j1->posInicial = sf::Vector2f(j1->get_posicion().x, j1->get_posicion().y);
                    //j1->movimiento = true;
                    j1->set_velocidad(sf::Vector2f(0,j1->vel_salto));     
                }
            }
                break;


                /**** TECLAS SIN PULSAR ****/

            case sf::Event::KeyReleased: // si se suelta la tecla
                // si se despulsta la tecla izquierda
                if(evento->key.code == (sf::Keyboard::Left)){
                    j1->movimiento = false;
                    j1->set_frameX(0);
                    j1->direccion = izq;
                    j1->set_velocidad(sf::Vector2f(0,0));
                    //j1->set_posicion(sf::Vector2f(j1->get_posicion().x - kVel,(j1->get_posicion().y)));
                }
                // si se despulsa la tecla derecha
                else if(evento->key.code == (sf::Keyboard::Right)){
                    j1->movimiento = false;
                    j1->set_frameX(0);
                    j1->direccion = der;
                    j1->set_velocidad(sf::Vector2f(0,0));
                
                    //j1->set_posicion(sf::Vector2f(j1->get_posicion().x + kVel,(j1->get_posicion().y)));
                }
               

                break;
        
        default:
                 //j1->movimiento = false;
                 
        break;

    }
}
