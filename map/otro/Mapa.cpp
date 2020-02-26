#include "Mapa.h"
Mapa:: Mapa(){

}
//Este metodo se guarda los datos del mapa
void Mapa::matrizDelMapa(){
    
    XMLDocument doc;

    doc.LoadFile("resources/Prueba.tmx");

    //Aqui obtenemos las dimensiones del mapa y los tiles
    XMLElement* map = doc.FirstChildElement("map");
    map->QueryIntAttribute("width",&ancho);
    map->QueryIntAttribute("height",&alto);
    map->QueryIntAttribute("tilewidth",&anchoTile);
    map->QueryIntAttribute("tileheight",&altoTile);

    //Ahora cargaremos la imagen tileset.png y el background
    XMLElement* img = map->FirstChildElement("tileset")->FirstChildElement("image");
    const char* filename=img->Attribute("source");

    /*XMLElement* imgback = map->FirstChildElement("imagelayer")->FirstChildElement("image");
    const char* filenameback=imgback->Attribute("source");*/

    //Esto es para encontrar todas las capas del mapa. Como estan al mismo nivel, buscaremos por hermanso una vez encuentres la primera capa
    XMLElement* layer = map->FirstChildElement("layer");
    while (layer){
        numCapas++;
        layer=layer->NextSiblingElement("layer");
    }

    //Y ahora cargamos los GIDS(los ids de los tiles, mas o menos) de las capas
    tilemap = new int**[numCapas];
    for (int i = 0; i < numCapas; i++){
        tilemap[i] = new int* [alto];
    }
    for (int i = 0; i < numCapas; i++){
        for (int j = 0; j < alto; j++){
            tilemap[i][j] = new int[ancho];
        }
    }
    this->data = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");


    //Estamos haciendo un apatriz de 3 dimensiones(capa-alti-ancho) y la recorremos entera leyendo y guardando cada uno de los Gids
    for (int i = 0; i < numCapas; i++){
        if(i==1){
             this->data = map->FirstChildElement("layer")->NextSiblingElement("layer")->FirstChildElement("data")->FirstChildElement("tile");}
        for (int j = 0; j <alto ; j++){
            for (int k = 0; k <ancho; k++){
                data->QueryIntAttribute("gid",&tilemap[i][j][k]);
                //Para cambiar de tile
                this->data = data->NextSiblingElement("tile");
            }
            
        }
        //Para cambiar de capa
        //this->data = map->FirstChildElement("layer")->NextSiblingElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    }
    
    
}

bool Mapa::load(const std::string& path, sf::Vector2u tile_size, int*** nivel, unsigned int ancho, unsigned int alto, int numCapas){
    std::cout<<"Ancho: "<<ancho<<std::endl;
    std::cout<<"Alto: "<<alto<<std::endl;
    std::cout<<"NumCapas: "<<numCapas<<std::endl;
    if(!tile.loadFromFile(path))return false;
    //Juan dijo que se hace asi
    vertex.setPrimitiveType(sf::Quads);
    vertex.resize(ancho*alto*4);

    for (unsigned int k = 0; k < numCapas; k++){
        for (unsigned int i = 0; i < ancho; i++){
            for (unsigned int j = 0; j < alto; j++){
                int gid = nivel[k][j][i];
                if (gid>0){
                    gid=gid-1;
                }
                int u;
                int v;

                if(gid!=0){
                    u = gid % (tile.getSize().x/tile_size.x);
                    v = gid / (tile.getSize().x/tile_size.x);

                    sf::Vertex* quad = &vertex[(i+j*ancho)*4];
                    
                    quad[0].position = sf::Vector2f(i * tile_size.x, j * tile_size.y);
                    quad[1].position = sf::Vector2f((i+1)*tile_size.x, j*tile_size.y);
                    quad[2].position = sf::Vector2f((i+1)*tile_size.x, (j+1)*tile_size.y);
                    quad[3].position = sf::Vector2f(i*tile_size.x,(j+1)*tile_size.y);

                    quad[0].texCoords = sf::Vector2f(u*tile_size.x, v*tile_size.y);
                    quad[1].texCoords = sf::Vector2f((u+1)*tile_size.x, v*tile_size.y);
                    quad[2].texCoords = sf::Vector2f((u+1)*tile_size.x, (v+1)*tile_size.y);
                    quad[3].texCoords = sf::Vector2f(u*tile_size.x,(v+1)*tile_size.y);
                }
            }
        }
    }
    return true;
}

void Mapa::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = &tile;
    target.draw(vertex,states);
}
Mapa::~Mapa(){
    
}