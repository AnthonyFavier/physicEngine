#include "Rectangle.h"

Rectangle::Rectangle()
{
	rectangle.setSize(sf::Vector2f(40, 40));
	m_sl=40;
	m_sw=40;

	m_w=0;
}

Rectangle::Rectangle(sf::Vector2f size)
{
	rectangle.setSize(size);
	m_sl=size.x;
	m_sw=size.y;

	m_w=0;
}

sf::RectangleShape Rectangle::getShape()
{
	return rectangle;
}

void Rectangle::setColor(sf::Color color)
{
	rectangle.setFillColor(color);
}

void Rectangle::setPos(float x, float y)
{
	m_x=x;
	m_y=y;
	rectangle.setPosition(m_x, m_y);
}
