#include "Scene.h"
#include "fctMoveScene.h"
#include "math.h"

Scene::Scene()
{
	m_nbElem=0;
	time=true;
}

bool Scene::getTime()
{
	return time;
}

/////////////////////////////////////////////////////////////////////

void Scene::addBalle(float radius, sf::Color color, float m, float x, float y, int d)
{
	Balle balle(radius, m);
	balle.setColor(color);
	balle.setPos(x, y);
	if(d)
	{
		balle.setVx(-balle.getVx());
		//balle.setVy(-balle.getVy());
	}
	listBalle.push_back(balle);
	m_nbElem+=1;
	fctMoveScene(this, true);
}

void Scene::addBalle(float radius, float m, float x, float y)
{
	Balle balle(radius, m);
	balle.setColor(sf::Color::Black);
	balle.setPos(x, y);
	listBalle.push_back(balle);
	m_nbElem+=1;
	fctMoveScene(this, true);
}

void Scene::rmvBalle()
{
	if(listBalle.size()>0)
	{
		listBalle.pop_back();
		m_nbElem-=1;
	}
	fctMoveScene(this, true);
}

int Scene::getNbBalle()
{
	return listBalle.size();
}

sf::CircleShape Scene::getShapeBalle(int i)
{
	if(i>=0 && i<listBalle.size())
		return listBalle[i].getShape();
}

float Scene::distBalles(Balle ball1, Balle ball2)
{
	float distance=0;

	distance=sqrt(pow(ball2.getX()-ball1.getX(),2)+pow(ball2.getY()-ball1.getY(),2));
	/*
	if( (ball2.getX()-ball1.getX()) > (ball2.getY()-ball1.getY()))
	{
		
	}
	*/

	return distance;
}

////////////////////////////////////////////////////////////////////

void Scene::addRectangle(sf::Vector2f size, sf::Color color, float x, float y)
{
	Rectangle rectangle(size);
	rectangle.setColor(color);
	rectangle.setPos(x, y);
	listRectangle.push_back(rectangle);
	m_nbElem+=1;
	fctMoveScene(this, true);
}

void Scene::addRectangle(sf::Vector2f size, float x, float y)
{
	Rectangle rectangle(size);
	rectangle.setColor(sf::Color::Black);
	rectangle.setPos(x, y);
	listRectangle.push_back(rectangle);
	m_nbElem+=1;
	fctMoveScene(this, true);
}

void Scene::rmvRectangle()
{
	if(listRectangle.size()>0)
	{
		listRectangle.pop_back();
		m_nbElem-=1;
	}
	fctMoveScene(this, true);

}

int Scene::getNbRectangle()
{
	return listRectangle.size();
}

sf::RectangleShape Scene::getShapeRectangle(int i)
{
	if(i>=0 && i<listRectangle.size())
	{
		return listRectangle[i].getShape();
	}
}


////////////////////////////////////////////////////////////////////////

int Scene::getNbElem()
{
	return m_nbElem;
}

void Scene::moveScene(float dt)
{
	int i=0;
	for(i=0; i<listBalle.size(); i++)
	{
		listBalle[i].move(dt);
	}
	// faire meme boucle pour les rectangles
}


float Scene::getXBall1()
{
	return listBalle[0].getX();
}

float Scene::getYBall1()
{
	return listBalle[0].getY();
}

float Scene::getXBall2()
{
	return listBalle[1].getX();
}

float Scene::getYBall2()
{
	return listBalle[1].getY();
}

float Scene::getVxBall1()
{
	return listBalle[0].getVx();
}
float Scene::getVyBall1()
{
	return listBalle[0].getVy();
}
float Scene::getVxBall2()
{
	return listBalle[1].getVx();
}
float Scene::getVyBall2()
{
	return listBalle[1].getVy();
}

void Scene::draw(sf::RenderWindow *window)
{
	int i;
	for(i=0; i<listBalle.size(); i++)
	{
		window->draw(listBalle[i].getShape());
	}

	for(i=0; i<listRectangle.size(); i++)
	{
		window->draw(listRectangle[i].getShape());
	}
}

bool Scene::gestionCollision()
{
	bool reverse; // Si on doit faire un reverseMove
	int i=0, j=0;

	// Gestion seulement des balles
	for(i=0; i<listBalle.size(); i++)
	{
		//collision bord ecran balle
		if(listBalle[i].getX()+2*listBalle[i].getRadius()>LARGEUR_FENETRE)
		{
			// Attention le cas pile égale !

			// Recalage
			float a=listBalle[i].getX()+2*listBalle[i].getRadius()-LARGEUR_FENETRE;
			float p=listBalle[i].getVy()/listBalle[i].getVx();
			float b=p*a;

			listBalle[i].setPos(listBalle[i].getX()-a, listBalle[i].getY()-b);

			// Rebond
			listBalle[i].setVx(listBalle[i].getVx()*(-1));
		}

		if(listBalle[i].getX()<0)
		{
			// Attention le cas pile égale !

			// Recalage
			float a=-listBalle[i].getX();
			float p=listBalle[i].getVy()/listBalle[i].getVx();
			float b=p*a;

			listBalle[i].setPos(listBalle[i].getX()+a, listBalle[i].getY()+b);

			// Rebond
			listBalle[i].setVx(listBalle[i].getVx()*(-1));
		}

		if(listBalle[i].getY()+2*listBalle[i].getRadius()>HAUTEUR_FENETRE)
		{
			// Attention le cas pile égale !

			// Recalage
			float b=listBalle[i].getY()+2*listBalle[i].getRadius()-HAUTEUR_FENETRE;
			float p=listBalle[i].getVx()/listBalle[i].getVy();
			float a=p*b;

			listBalle[i].setPos(listBalle[i].getX()-a, listBalle[i].getY()-b);

			// Rebond
			listBalle[i].setVy(listBalle[i].getVy()*(-1));
		}

		if(listBalle[i].getY()<0)
		{
			// Attention le cas pile égale !

			// Recalage
			float b=-listBalle[i].getY();
			float p=listBalle[i].getVx()/listBalle[i].getVy();
			float a=p*b;

			listBalle[i].setPos(listBalle[i].getX()+a, listBalle[i].getY()+b);

			// Rebond
			listBalle[i].setVy(listBalle[i].getVy()*(-1));
		}

		for(j=i+1; j<listBalle.size(); j++)
		{
			//collision entre balle
			// Detection
			if(distBalles(listBalle[i], listBalle[j])<listBalle[i].getRadius()+listBalle[j].getRadius())
		{
//				time=false;

				// RECALLAGE //
				// Recalage (avant / après changement de repère ?)
				// Attention direction verticale / horizontale
				// pour le moment verticale
// PETAGE DE CABLE A CAUSE DU RECALLAGE
// FAUT RECALCULER LES PENTES
//
// 			FAIRE CONDITION ET PLUSIEURS CAS POUR DEFINITION DE CET ANGLE AUSSI !!!!!!!! classique ou PI/2 - new
				float angle;
				//angle=PI/2-acos((listBalle[j].getX()-listBalle[i].getX())/(sqrt(pow(listBalle[j].getX()-listBalle[i].getX(),2)+pow(listBalle[j].getY()-listBalle[i].getY(),2))));
				if(abs(listBalle[j].getX()-listBalle[i].getX())>=(listBalle[j].getY()-listBalle[i].getY()))
				{
					angle=atan((listBalle[j].getY()-listBalle[i].getY())/(listBalle[j].getX()-listBalle[i].getX()));
				}
				else
				{
				}

				// Pour calcul des pentes tester si Vy>Vx et décaller de PI/2, inverse def de la pente x/y au lieu de y/x
				printf("Detection\nangle=%f\nBall1: x=%f y=%f vx=%f vy=%f\nBall2: x=%f y=%f vx=%f vy=%f\n", angle,listBalle[i].getX(), listBalle[i].getY(), listBalle[i].getVx(), listBalle[i].getVy(), listBalle[j].getX(), listBalle[j].getY(), listBalle[j].getVx(), listBalle[j].getVy());
				float p1, p2;
				float r1, r2;
				float d;
				float a1, a2, b;
				r1=listBalle[i].getRadius();
				r2=listBalle[i].getRadius();
				d=distBalles(listBalle[i], listBalle[j]);
				// attention faire difference i j
// typiquement si un def comme avant et l'autre en nouveau -> pas clair

				// vitesse après changement de repère
				float Ux1, Uy1, Ux2, Uy2;
				float Vx1, Vy1, Vx2, Vy2;
				// Changement de repere
				Ux1=cos(angle)*listBalle[i].getVx()+sin(angle)*listBalle[i].getVy();
				Uy1=-sin(angle)*listBalle[i].getVx()+cos(angle)*listBalle[i].getVy();
				Ux2=cos(angle)*listBalle[j].getVx()+sin(angle)*listBalle[j].getVy();
				Uy2=-sin(angle)*listBalle[j].getVx()+cos(angle)*listBalle[j].getVy();
				
				printf("Ux1=%f Uy1=%f Ux2=%f Uy2=%f \n", Ux1,Uy1,Ux2,Uy2);


				if( abs(Ux1) >= abs(Uy1) )
					p1=abs(Uy1/Ux1);
				else
					p1=(PI/2-abs(Ux1/Uy1));

				if( abs(Ux2) >= abs(Uy2) )
					p2=abs(Uy2/Ux2);
				else
					p2=abs(PI/2-abs(Ux2/Uy2));

				p1=tan(Uy1/Ux1);
				p2=tan(Uy2/Ux2);
				
				//a1=(p2*(r1+r2-d))/(p1+p2)*cos(PI/2-angle);
				//a2=-(p1*(r1+r2-d))/(p1+p2)*cos(PI/2-angle);
				//b=(p1*p2*(r1+r2-d))/(p1+p2)*sin(PI/2-angle);
				
				a1=((r1+r2-d)*Ux1*Uy2)/(Ux1*Uy2+Ux2*Uy1);
				a2=((r1+r2-d)*Ux2*Uy1)/(Ux1*Uy2+Ux1*Uy2);
				b=((r1+r2-d)*Uy1*Uy2)/(Ux1+Ux2);


				printf("\nd=%f\np1=%f\np2=%f\na1=%f\na2=%f\nb=%f\nangle=%f\n", d,p1,p2,a1,a2,b,angle);

				listBalle[i].setPos(listBalle[i].getX()+a1, listBalle[i].getY()+b);
				listBalle[j].setPos(listBalle[j].getX()+a2, listBalle[j].getY()+b);
				// Fin recallage

				// COLLISION //

				// Calcul Collision
				Vx1=(Ux1*listBalle[i].getM()+Ux2*listBalle[j].getM()-(Ux1-Ux2)*listBalle[j].getM())/(listBalle[i].getM()+listBalle[j].getM());
				Vy1=-Uy1;
				Vx2=(Ux1*listBalle[i].getM()+Ux2*listBalle[j].getM()-(Ux2-Ux1)*listBalle[j].getM())/(listBalle[i].getM()+listBalle[j].getM());
				Vy2=-Uy2;

				// Retour repere de base
				listBalle[i].setVx(cos(angle)*Vx1-sin(angle)*Vy1);
				listBalle[i].setVy(sin(angle)*Vx1+cos(angle)*Vy1);
				listBalle[j].setVx(cos(angle)*Vx2-sin(angle)*Vy2);
				listBalle[j].setVy(sin(angle)*Vx2+cos(angle)*Vy2); //-sin 2eme

			}
		}
	}

	return reverse;
}
