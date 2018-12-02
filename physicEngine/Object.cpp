#include "Object.h"

Object::Object()
{
	m_masse=1;
	m_x=0;
	m_y=0;
	m_vx=0;
	m_vy=0;
	m_ax=0;
	m_ay=0;
}

float Object::getM()
{
	return m_masse;
}

float Object::getX()
{
	return m_x;
}
float Object::getY()
{
	return m_y;
}
float Object::getVx()
{
	return m_vx;
}
float Object::getVy()
{
	return m_vy;
}
float Object::getAx()
{
	return m_ax;
}
float Object::getAy()
{
	return m_ay;
}

void Object::setX(float x)
{
	m_x=x;
}
void Object::setY(float y)
{
	m_y=y;
}
void Object::setVx(float vx)
{
	m_vx=vx;
}
void Object::setVy(float vy)
{
	m_vy=vy;
}
void Object::setAx(float ax)
{
	m_ax=ax;
}
void Object::setAy(float ay)
{
	m_ay=ay;
}
