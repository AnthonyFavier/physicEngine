#ifndef DEF_BALLE
#define DEF_BALLE

#include "constantes.h"
#include <SFML/Graphics.hpp>
#include "Object.h"

class Balle : public Object
{
public:
	Balle();
	Balle(float radius, float masse);

	void setColor(sf::Color color);
	void setPos(float x, float y);
	sf::CircleShape getShape();

	void move(float dt);
	float getRadius();

private:
	float m_r;
	// inertie ? vitesse de rotation ?
	sf::CircleShape circle;
};

#endif
