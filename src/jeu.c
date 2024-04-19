#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../include/jeu.h"
#include "../include/serpent.h"
#include "../include/structures.h"
#define CYCLE 10000L
#define TAILLE_INITIALE_SERPENT 10

/* Fonction qui vérifie les conditions de défaite du jeu*/
void ConditionDefaite(JEU *jeu, TERRAIN *terrain, SERPENT *snake) {
    int i = 0;

    /* Conditions liées à la position du serpent*/
    if (snake->pos_x[0] > 1180 || snake->pos_x[0] < 20) {
        jeu->jeu_en_cours = 0;
    }
    if (snake->pos_y[0] < 20 || snake->pos_y[0] > 680) {
        jeu->jeu_en_cours = 0;
    }

    /* Condition de collision avec le corps du serpent*/
    for (i = 1; i < snake->segment; i++) {
        if (snake->pos_x[0] == snake->pos_x[i] && snake->pos_y[0] == snake->pos_y[i])
            jeu->jeu_en_cours = 0;
    }

    /* Condition de collision avec les obstacles du terrain*/
    if (terrain->obstacle_on == 1) {
        for (terrain->o = 0; terrain->o < 11; terrain->o++) {
            if (terrain->obstaclex[terrain->o] == snake->pos_x[0] && terrain->obstacley[terrain->o] == snake->pos_y[0]) {
                jeu->jeu_en_cours = 0;
            }
        }
    }
}

/* Fonction qui gère les commandes du joueur*/
void Controle(JEU *jeu) {
    int pause = 1;

    /* Vérifie si une touche est en attente*/
    if (ToucheEnAttente()) {
        jeu->touche = Touche();

        /* Gestion des commandes*/
        if (jeu->touche == XK_Left) {
            if (jeu->last_direction != 4) {
                jeu->direction = 3;
                jeu->last_direction = 3;
            }
        } else if (jeu->touche == XK_Right) {
            if (jeu->last_direction != 3) {
                jeu->direction = 4;
                jeu->last_direction = 4;
            }
        } else if (jeu->touche == XK_Up) {
            if (jeu->last_direction != 2) {
                jeu->direction = 1;
                jeu->last_direction = 1;
            }
        } else if (jeu->touche == XK_Down) {
            if (jeu->last_direction != 1) {
                jeu->direction = 2;
                jeu->last_direction = 2;
            }
        } else if (jeu->touche == XK_Escape) {
            jeu->direction = 0;
            jeu->jeu_en_cours = 0;
        } else if (jeu->touche == XK_space) {
            jeu->paused = jeu->paused == 1 ? 0 : 1;
        }
    }
}

/* Fonction qui met en pause le jeu pour un certain nombre de microsecondes*/
void Attendre(int microsecondes) {
    unsigned long int attente = Microsecondes() + microsecondes;
    while (Microsecondes() < attente) {
    }
}

/* Fonction qui met à jour le score affiché à l'écran*/
void Update_Score(JEU *jeu) {
    snprintf(jeu->score_str, 100, "SCORE: %d", jeu->score);
    ChoisirCouleurDessin(CouleurParComposante(114, 148, 77));
    RemplirRectangle(1000, 700, 1100, 800);
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(1000, 760, jeu->score_str, 2);
}

/* Fonction qui affiche l'écran de fin du jeu avec le score et le temps final*/
void EcranFinJeu(JEU *jeu, TIMER *temps) {
    ChargerImageFond("image/menudefin.png");

    /* Affichage du score et du temps final*/
    snprintf(jeu->score_str, 100, "%d", jeu->score);
    EcrireTexte(500, 270, jeu->score_str, 2);
    EcrireTexte(500, 400, temps->timer, 2);

    Attendre(30000000);
}
