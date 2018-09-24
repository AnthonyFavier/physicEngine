#include "Balle.h"

Balle::Balle()
{
	Object();
	m_r=20;
	circle.setRadius(m_r);
	m_vx=0;
	m_vy=0;
}

Balle::Balle(float radius, float masse)
{
	Object();
	m_r=radius;
	circle.setRadius(m_r);
	m_vx=0;
	m_vy=10;
	m_masse=masse;
}

void Balle::setColor(sf::Color color)
{
	circle.setFillColor(color);
}

sf::CircleShape Balle::getShape()
{
	return circle;
}

void Balle::setPos(float x, float y)
{
	m_x=x;
	m_y=y;
	circle.setPosition(m_x, m_y);
}

void Balle::move(float dt)
{
	m_x=m_x+m_vx*dt;
	m_y=m_y+m_vy*dt;
	circle.setPosition(m_x,m_y);
}

float Balle::getRadius()
{
	return m_r;
}
