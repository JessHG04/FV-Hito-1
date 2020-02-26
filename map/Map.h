#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

//Generacion de un unico mapa
//Drawable y transformable heredados de SFML

class Map : public sf::Drawable, public sf::Transformable{
    private:
        static Map *map;
        sf::VertexArray vertex;
        sf::Texture tile;

    public:
        Map(); //Constructor
        virtual ~Map();
        bool load(const std::string& path, sf::Vector2u tile_size, int*** level, unsigned int witdh, unsigned int heigth, int nLayer);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void mapMatrix();
        int*** tilemap;
        int** getIdMatrix;
        //int 

};