#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Balle.h"
#include "Scene.h"
#include "CallBackTimer.h"
#include "fctMoveScene.h"
#include <math.h>

int main()
{
	// Création de la fênetre principale
	sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "Truc qui bouge pas bien");
	window.clear(sf::Color::White);

	// Variables
	int i=0;
	
	// Creation de la scène
	Scene scene;
	//scene.addBalle(40, sf::Color::Black, 1, 0, HAUTEUR_FENETRE/2, 0);  //-80/sqrt(2)
	//scene.addBalle(40, sf::Color::Red, 1, LARGEUR_FENETRE-40*2, HAUTEUR_FENETRE/2, 1);  //-80/sqrt(2)
	
	scene.addBalle(40, sf::Color::Red, 1, LARGEUR_FENETRE/2, 0, 0);  //-80/sqrt()
	scene.addBalle(40, sf::Color::Black, 1, LARGEUR_FENETRE/2, HAUTEUR_FENETRE-2*40, 1);
	

	// Mise en place du timer de mouvement
	CallBackTimer timer;
	timer.start(DELTA_T*100, fctMoveScene);

	// Boucle principale avec gestion evenement
	sf::Event event;
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					timer.stop();
					window.close();
					break;

				case sf::Event::KeyPressed:
					switch(event.key.code)
					{
						case sf::Keyboard::Escape:
							timer.stop();
							window.close();
							break;

						case sf::Keyboard::R:
							scene.rmvBalle();
							break;

						case sf::Keyboard::C:
							scene.addRectangle(sf::Vector2f(200, 300), sf::Color::Yellow, 200, 300);
							break;

						case  sf::Keyboard::V:
							scene.rmvRectangle();
							break;

						default:
							scene.addBalle(20, sf::Color::Blue, 1, 100, 100, 0);
							break;
					}
					break;

				default:
					break;
			}
		}

	if(!scene.getTime())
	{
		timer.stop();
	}
	else
	{
		printf("Ball1: x=%f y=%f vx=%f vy=%f\n Ball2: x=%f y=%f vx=%f vy=%f\n", scene.getXBall1(), scene.getYBall1(), scene.getVxBall1(), scene.getVyBall1(), scene.getXBall2(), scene.getYBall2(), scene.getVxBall2(), scene.getVyBall2());
	}

	window.clear(sf::Color::White);
	scene.draw(&window);
	window.display();
	}

	return 0;
}

