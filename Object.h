#ifndef DEF_OBJECT
#define DEF_OBJECT

#include "constantes.h"
#include <SFML/Graphics.hpp>

class Object
{
public:
	Object();

	float getM();

	float getX();
	float getY();
	float getVx();
	float getVy();
	float getAx();
	float getAy();

	void setX(float x);
	void setY(float y);
	void setVx(float vx);
	void setVy(float vy);
	void setAx(float ax);
	void setAy(float ay);

protected:
	float m_masse;
	float m_x, m_y;
	float m_vx, m_vy;
	float m_ax, m_ay;
};

#endif
