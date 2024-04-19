#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../include/jeu.h"
#include "../include/serpent.h"
#include "../include/structures.h"

/* Fonction principale du déplacement et de la mise à jour du serpent*/
void Serpent(SERPENT *snake, TERRAIN *terrain, JEU *jeu, PASTILLE *pill, TIMER *temps) {
    /* Déplacement du serpent en fonction de la direction choisie*/
    if (jeu->direction == 1 && jeu->direction != 2) {
        snake->pos_y[0] = snake->old_y[0] - 20;
    }
    if (jeu->direction == 2 && jeu->direction != 1) {
        snake->pos_y[0] = snake->old_y[0] + 20;
    }
    if (jeu->direction == 3 && jeu->direction != 4) {
        snake->pos_x[0] = snake->old_x[0] - 20;
    }
    if (jeu->direction == 4 && jeu->direction != 3) {
        snake->pos_x[0] = snake->old_x[0] + 20;
    }

    /* Vérification des conditions de défaite*/
    ConditionDefaite(jeu, terrain, snake);

    /* Vérification de la collision avec les pastilles*/
    for (pill->p = 0; pill->p < 5; pill->p++) {
        if (pill->pastillex[pill->p] == snake->pos_x[0] && pill->pastilley[pill->p] == snake->pos_y[0]) {
            /* Augmentation de la longueur du serpent et mise à jour de la position de la pastille*/
            snake->segment += 2;
            pill->pastillex[pill->p] = ((rand() % (57) + 1) * 20);
            pill->pastilley[pill->p] = ((rand() % (34) + 1) * 20);
            jeu->score += 5;
            Update_Score(jeu);
        }
    }

    /* Mise à jour du serpent et des conditions de défaite*/
    Update_Serpent(snake, terrain);
    ConditionDefaite(jeu, terrain, snake);

    /* Pause pour réguler la vitesse du serpent*/
    Attendre(100000);
}

/* Mise à jour de la position du serpent sur l'écran*/
void Update_Serpent(SERPENT *snake, TERRAIN *terrain) {
    int i;

    /* Suppression de l'ancienne position du dernier segment du serpent*/
    AfficherSprite(terrain->fond, snake->old_x[snake->segment - 1], snake->old_y[snake->segment - 1]);

    /* Affichage du nouveau positionnement de la tête du serpent*/
    AfficherSprite(snake->serpent, snake->pos_x[0], snake->pos_y[0]);

    /*Mise à jour de la position de chaque segment du serpent*/ 
    for (i = 1; i < snake->segment; i++) {
        snake->pos_x[i] = snake->old_x[i - 1];
        snake->pos_y[i] = snake->old_y[i - 1];
        AfficherSprite(snake->serpent, snake->pos_x[i], snake->pos_y[i]);
    }

    /* Mise à jour des anciennes positions du serpent*/
    snake->old_x[0] = snake->pos_x[0];
    snake->old_y[0] = snake->pos_y[0];

    for (i = 1; i < snake->segment; i++) {
        snake->old_x[i] = snake->pos_x[i];
        snake->old_y[i] = snake->pos_y[i];
    }
}
