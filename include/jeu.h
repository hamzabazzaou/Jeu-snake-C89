#ifndef JEU_H
#define JEU_H
#include "structures.h"



void Controle(JEU *jeu);
void ConditionDefaite(JEU *jeu, TERRAIN *terrain, SERPENT *snake);
void obstacle(void);
void Update_Score(JEU *jeu);
void Attendre(int microsecondes);
void EcranFinJeu(JEU *jeu, TIMER *temps);


#endif
