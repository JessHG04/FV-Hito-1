/*#pragma once*/
#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics.hpp>
#include "tinyxml2.h"
#include "iostream"
using namespace tinyxml2;

//Esto genera un mapa, una vez solo
//el drawable y transformable los heredas de sfml
class Mapa : public sf::Drawable, public sf::Transformable
{
private:
    static Mapa* mapa;
    sf::VertexArray vertex;
    sf::Texture tile;
public:
    Mapa();
    //Relacionado con la herencia
    virtual ~Mapa();
    //Vector2u son vectores que devuelven un 2uint: int sin valores negativos
    bool load(const std::string& path, sf::Vector2u tile_size, int*** nivel, unsigned int ancho, unsigned int largo, int numCapas);
    //El const despues del metodo indica que este metodo no va a cambiar los valores de las variables de clase
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    //Esta es la funcion que te caga el mapa
    void matrizDelMapa();
    //Mapa de tiles
    int*** tilemap;
    //Matriz con los id de los tile
    int** gitMatrix;
    //Ancho y alto DEL MAPA
    int ancho;
    int alto;
    int numCapas;

    //Esto es de donde lees el mapa,como las practicas de lectura de ficheros de p2(aunque no se haga de la misma forma)
    XMLElement *data;

    int anchoTile;
    int altoTile;
};
#endif