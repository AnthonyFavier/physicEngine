#ifndef DEF_RECTANGLE
#define DEF_RECTANGLE

#include "constantes.h"
#include <SFML/Graphics.hpp>
#include "Object.h"

class Rectangle : public Object
{
public:
	Rectangle();
	Rectangle(sf::Vector2f size);
	void setColor(sf::Color color);
	void setPos(float x, float y);
	sf::RectangleShape getShape();
private:
	float m_sl;
	float m_sw;
	// Matrice d'inertie
	// Vitesse de rotation
	float m_w;
	sf::RectangleShape rectangle;
};

#endif
