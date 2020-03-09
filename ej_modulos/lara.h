#ifndef lara_h
#define lara_h

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class lara{
    public:
        int direccion;
        Texture *tex;
        int numVidas;
        lara();
        void cambiarSprite(int);
        void restartSprite();
        Sprite devolverSprite();
    private:
        Sprite *sprite;        
};

#endif