#include "Map.h"

Map::Map(){

}

void Map::mapMatrix(){

    tinyxml2::XMLDocument doc;

    doc.LoadFile("resources/Map.tmx");
    //Dimensiones del mapa y tiles
    tinyxml2::XMLElement *map = doc.FirstChildElement("map");

    map->QueryIntAttribute("width", &widthMap);
    map->QueryIntAttribute("height", &heightMap);
    map->QueryIntAttribute("tilewidth", &widthTile);
    map->QueryIntAttribute("tileheight", &heightTile);

    //Carga de tileset y background
    tinyxml2::XMLElement *img = map->FirstChildElement("tileset")->FirstChildElement("image");
    const char *filename = img->Attribute("source");

    tinyxml2::XMLElement* imgBackground = map->FirstChildElement("imagelayer")->FirstChildElement("image");
    const char* filenameback=imgBackground->Attribute("source");

    //Numero de capas 
    tinyxml2::XMLElement *layer = map->FirstChildElement("layer");
    while(layer){
        numLayers++;
        layer = layer->NextSiblingElement("layer");
    }

    //Reserva de memoria de los GIDs de las capas
    tilemap = new int **[numLayers];
    for(unsigned int x = 0; x < numLayers; x++){
        tilemap[x] = new int *[heightMap]; 
    }
    for(unsigned int x = 0; x < numLayers; x++){
        for(unsigned int y = 0; y < heightMap; y++){
            tilemap[x][y] = new int[widthMap];
        }
    }
    this->data = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");

    //Asignacion de cada gids a la matriz de 3x3 (layer-height-width)

    for(unsigned int x = 0; x < numLayers; x++){
        if(x==1){
            this->data = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
        }
        for(unsigned int y = 0; y < heightMap; y++) {
            for(unsigned int z = 0; z < widthMap; z++){
                data->QueryIntAttribute("gid", &tilemap[x][y][z]);
                //Pasamos al siguiente tile
                this->data = data->NextSiblingElement("tile");
            }
        }
    }
    std::cout << "He acabao con la matriz" << std::endl;

    //Segun las diapositivas de teoria
    /*
    tinyxml2::XMLElement *data [0] = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");

    for(unsigned z = 0; z < numLayers; z++){
        for(unsigned y = 0; y < heightMap; y++){
            for(unsigned x = 0; x < widthMap; x++){
                data[z]->QueryIntAtribute("gid", &tilemap[z][x]y]);
                //Paso al siguiente
                data[z] = data[z]->NextSiblingElement("tile");
            }
        }
    }
    */

}

bool Map::load(const std::string& path, sf::Vector2u tileSize, int*** level, unsigned int witdh, unsigned int heigth, int numLayer){
       //std::cout << "Layers: " << numLayer << std::endl;
       //std::cout << "Height: " << heigth << std::endl;
       //std::cout << "Width: " << witdh << std::endl;
       if(!tile.loadFromFile(path)){
           return false;
       }
       vertex.setPrimitiveType(sf::Quads);
       vertex.resize(widthMap * heightMap * 294); //Se multiplica por la cantidad de tiles que hay, so, REVISAR

       for(unsigned int z = 0; z < numLayers; z++){
           for(unsigned int x = 0; x < widthMap; x++){
               for(unsigned int y = 0; y < heightMap; y++){
                   int gid = level[z][y][x];
                   if(gid > 0){
                       gid-=1;
                   }
                   int u; 
                   int v;

                   if(gid!=0){
                       //Posicion del tileset para partirlo
                       u = gid % (tile.getSize().x / tileSize.x); 
                       v = gid / (tile.getSize().x / tileSize.x);
                       //Puntero para apuntar al quad actual
                       sf::Vertex *quad = &vertex[(x+y*widthMap)*294]; //Jess revisa este numero tambien

                       //Definicion de posiciones del quad
                       quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
                       quad[1].position = sf::Vector2f((x+1) * tileSize.x, y * tileSize.y);
                       quad[2].position = sf::Vector2f((x+1) * tileSize.x, (y+1) * tileSize.y);
                       quad[3].position = sf::Vector2f(x * tileSize.x, (y+1) * tileSize.y);

                       //Definicion de posiciones del quad
                       quad[0].texCoords = sf::Vector2f(u*tileSize.x, v*tileSize.y);
                       quad[1].texCoords = sf::Vector2f((u+1)*tileSize.x, v*tileSize.y);
                       quad[2].texCoords = sf::Vector2f((u+1)*tileSize.x, (v+1)*tileSize.y);
                       quad[3].texCoords = sf::Vector2f(u*tileSize.x,(v+1)*tileSize.y);
                   }
               }
           }
       }
    return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = &tile;
    target.draw(vertex,states);
}

Map::~Map(){

}