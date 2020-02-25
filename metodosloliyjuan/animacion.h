#include <SFML/Graphics.hpp>
#include <iostream>

class animacion{
    public:
        animacion();
        ~animacion();
    private:
        sf::Vector2u ContadorImagen;
        sf::Vector2u ImagenActual;
};