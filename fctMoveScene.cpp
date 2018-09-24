#include "fctMoveScene.h"

void fctMoveScene(Scene *sceneT, bool fromMain)
{
	static Scene *scene;
	if(fromMain)
		scene=sceneT;
	else
	{
		// Attention ordre d'execution
		// Bouger -> test collision
		// Reverse move ?
		// move adapté
		scene->moveScene(DELTA_T);
		scene->gestionCollision();
	}
}
