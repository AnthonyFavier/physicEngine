#ifndef DEF_SCENE
#define DEF_SCENE

#include "constantes.h"
#include "Object.h"
#include "Balle.h"
#include "Rectangle.h"
#include <vector>

class Scene
{
public:
	Scene();

	void addBalle(float radius, sf::Color color, float m, float x, float y, int d);
	void addBalle(float radius, float m,  float x, float y);
	void rmvBalle(); // enleve forcement le dernier objet, trouver comment faire
	int getNbBalle();
	sf::CircleShape getShapeBalle(int i);
	float distBalles(Balle ball1, Balle ball2);

	void addRectangle(sf::Vector2f size, sf::Color color, float x, float y);
	void addRectangle(sf::Vector2f size, float x, float y);
	void rmvRectangle();
	int getNbRectangle();
	sf::RectangleShape getShapeRectangle(int i);

	void moveScene(float dt);
	int getNbElem();
	void draw(sf::RenderWindow *window);
	bool gestionCollision();

	/////// Pour le debug /////////
	bool getTime();
	float getXBall1();
	float getYBall1();
	float getXBall2();
	float getYBall2();
	float getVxBall1();
	float getVyBall1();
	float getVxBall2();
	float getVyBall2();

private:
	int m_nbElem;
	bool time;
	std::vector<Balle> listBalle;
	std::vector<Rectangle> listRectangle;

	// fond fenetre (pas sur, peut etre à une classe d'affichage ?)
};

#endif
