#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


using namespace std;

int main(){

	//tamanyo de la ventana y tamanyo del bloque
	sf::RenderWindow app(sf::VideoMode(500,500,50),"Colisiones con mapa");
	//velocidad del movimiento del bloque
	app.setFramerateLimit(150);
	//posicion  donde empieza el bloque principal
	int px = 15, py = 350;

	sf::Vector2f previous;
	bool der = false,izq = false,up = false,down = false;
	//dimensiones bloque principal
	int offsetX = 50, offsetY = 50;

	//atribucion de posicion bloque prinicipal
	sf::RectangleShape RS(sf::Vector2f(offsetX, offsetY));

	//color del bloque principal
	RS.setFillColor(sf::Color(51,159,255));

	//dibujamos el map de 10x10
	int tabmap[10][10]={
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,2,2,2,2},
		{0,1,1,0,0,0,2,2,2,2},
		{0,0,0,0,0,0,2,2,2,2},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,1,0,0,0},
		{1,1,1,1,2,2,1,1,1,1}
	};

	//creamos vector
	vector<sf::RectangleShape>vecBox;

	//creamos vector trampa
	vector<sf::RectangleShape>vecBoxTrampa;

	//dimensiones de bloques del vector
	sf::RectangleShape box(sf::Vector2f(offsetX, offsetY));

	//recorremos el mapa para dibujarlo
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 10; x++){
			if(tabmap[y][x]==1){
				sf::RectangleShape box(sf::Vector2f(offsetX, offsetY));
				//color bloques del vector
				box.setFillColor(sf::Color(49,164,67));
				//colocacion bloques del vector
				box.setPosition(sf::Vector2f(x*offsetX, y*offsetY));
				//anyamos bloques con 1 al vector
				vecBox.push_back(box);
			}

			if(tabmap[y][x]==2){
				sf::RectangleShape box(sf::Vector2f(offsetX, offsetY));
				//color bloques del vector
				box.setFillColor(sf::Color(212,46,40));
				//colocacion bloques del vector
				box.setPosition(sf::Vector2f(x*offsetX, y*offsetY));
				//anyamos bloques con 1 al vector
				vecBoxTrampa.push_back(box);
			}
		}
	}

	//inicia
	while(app.isOpen())
	{
		//procesa eventos
		sf::Event event;
		while(app.pollEvent(event))
		{
			switch(event.type)
			{
			//cierra la ventana
			case sf::Event::Closed:
				app.close();
				break;
			}	
		}

		previous.x = px;
		previous.y = py;

		//movimientos del bloque principal
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			py--;
			der = false;izq = false;up = true;down = false;
			for(int i = 0; i < vecBox.size(); i++){
				if(vecBox[i].getGlobalBounds().intersects(RS.getGlobalBounds())){
					px = (previous.x);
					py = (previous.y)+1;
				}
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			py++;
			der = false;izq = false;up = false;down = true;
			for(int i = 0; i < vecBox.size(); i++){
				if(vecBox[i].getGlobalBounds().intersects(RS.getGlobalBounds())){
					px = (previous.x);
					py = (previous.y)-1;
				}
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			px--;
			der = false;izq = true;up = false;down = false;
			for(int i = 0; i < vecBox.size(); i++){
				if(vecBox[i].getGlobalBounds().intersects(RS.getGlobalBounds())){
					px = (previous.x)+1;
					py = (previous.y);
				}
			}
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			px++;
			der = true;izq = false;up = false;down = false;
			for(int i = 0; i < vecBox.size(); i++){
				if(vecBox[i].getGlobalBounds().intersects(RS.getGlobalBounds())){
					px = (previous.x)-1;
					py = (previous.y);
				}
			}
		}

		//colision suelo bien
		for(int i = 0; i < vecBox.size(); i++){
			if(vecBox[i].getGlobalBounds().intersects(RS.getGlobalBounds()) && up==true ){
				px = (previous.x);
				py = (previous.y)+1;
			}else if(vecBox[i].getGlobalBounds().intersects(RS.getGlobalBounds()) && der==true ){
				px = (previous.x)-1;
				py = (previous.y);
			}else if(vecBox[i].getGlobalBounds().intersects(RS.getGlobalBounds()) && down==true ){
				px = (previous.x);
				py = (previous.y)-1;
			}else if(vecBox[i].getGlobalBounds().intersects(RS.getGlobalBounds()) && izq==true ){
				px = (previous.x)+1;
				py = (previous.y);
			}

		}

		//colision trampa
		for(int i = 0; i < vecBoxTrampa.size(); i++){
			if(vecBoxTrampa[i].getGlobalBounds().intersects(RS.getGlobalBounds())){
				px = 15;
				py = 350;
			}
		}


		RS.setPosition(sf::Vector2f(px, py));

		//limpia la pantalla, la rellena de color negro
		app.clear();

		//dibuja el vector
		for(int i = 0; i < vecBox.size(); i++){
			app.draw(vecBox[i]);
		}

		//dibuja el vector trampa
		for(int i = 0; i < vecBoxTrampa.size(); i++){
			app.draw(vecBoxTrampa[i]);
		}

		//dibuja el bloque principal
		app.draw(RS);

		//actualizacion de la ventana
		app.display();
  }
}
