#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "tinyxml2.h"

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
        bool load(const std::string& path, sf::Vector2u tileSize, int*** level, unsigned int witdh, unsigned int heigth, int numLayer);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void mapMatrix(); //Guardar datos del mapa
        tinyxml2::XMLElement *data;
        int ***tilemap;
        int **gidMatrix;
        int widthMap;
        int heightMap;
        int numLayers;
        int widthTile;
        int heightTile;
};