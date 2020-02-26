#include "Map.h"

Map::Map(){

}

void Map::mapMatrix(){ 
    tinyxml2::XMLDocument document;

    document.LoadFile("resources/Map.tmx");

    //Dimensiones del mapa y tiles
    tinyxml2::XMLElement *map = document.FirstChildElement("map");
    map->QueryIntAttribute("width", &widthMap);
    map->QueryIntAttribute("height", &heightMap);
    map->QueryIntAttribute("tilewidth", &widthTile);
    map->QueryIntAttribute("tileheight", &heightTile);

    //Carga de tileset y background
    tinyxml2::XMLElement *img = map->FirstChildElement("tileset")->FirstChildElement("image");
    const char *filename = img->Attribute("source");

    //Numero de capas 
    tinyxml2::XMLElement *layer = map->FirstChildElement("layer");
    while(layer){
        numLayers++;
        layer = layer->NextSiblingElement("layer");
    }

}