#ifndef SERPENT_H
#define SERPENT_H

#include"structures.h"
#include "jeu.h"

void Update_Serpent(SERPENT *snake, TERRAIN *terrain);
void Serpent(SERPENT *snake, TERRAIN *terrain, JEU *jeu, PASTILLE *pill, TIMER *temps);


#endif 