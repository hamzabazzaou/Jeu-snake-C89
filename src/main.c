#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../include/serpent.h"
#include "../include/pastilles.h"
#include "../include/terrain.h"
#include "../include/jeu.h"
#include "../include/structures.h"
#include "../include/menu.h"
#include "../include/timer.h"
#define CYCLE 10000L

/* Fonction pour lancer le premier jeu*/
int lancer_jeu() {
    JEU jeu;
    TIMER temps;
    TERRAIN terrain;
    SERPENT snake;
    PASTILLE pill;

    /* Initialisation des structures de jeu*/
    jeu.direction = 4;
    jeu.last_direction = 4;
    jeu.score = 0;
    jeu.touche = 0;
    jeu.jeu_en_cours = 1;

    terrain.x = 600;
    terrain.y = 400;
    terrain.fond;
    terrain.o = 0;
    terrain.obstacle;
    terrain.obstacle_on = 0;
    terrain.obstaclex[15];
    terrain.obstacley[15];

    snake.pos_x[2400];
    snake.pos_y[2400];
    snake.old_x[2400];
    snake.old_y[2400];
    snake.serpent;
    snake.segment = 10;

    pill.pastille;
    pill.pastillex[5];
    pill.pastilley[5];

    /* Initialisation graphique*/
    EffacerEcran(CouleurParComposante(114, 148, 77));
    temps.suivant = Microsecondes() + CYCLE;
    temps.old_seconde = (temps.suivant / 1000000) % 10;
    DessinerScene(&temps, &terrain, &snake, &pill);
    ChoisirCouleurDessin(CouleurParComposante(114, 148, 77));
    RemplirRectangle(0, 700, 1200, 800);

    /* Boucle principale du jeu*/
    while (jeu.jeu_en_cours) {
        Controle(&jeu);
        if (jeu.paused == 0) {
            Timer(&temps);
            Update_Timer(&temps);
            Serpent(&snake, &terrain, &jeu, &pill, &temps);
            Pastille(&pill);
            Update_Score(&jeu);
        }
    }

    /* Appel de l'écran de fin du jeu*/
    EcranFinJeu(&jeu, &temps);
    return EXIT_SUCCESS;
}

/* Fonction pour lancer le deuxième jeu*/
int lancer_jeu2() {
    JEU jeu;
    TIMER temps;
    TERRAIN terrain;
    SERPENT snake;
    PASTILLE pill;

    /* Initialisation des structures de jeu*/
    jeu.direction = 4;
    jeu.last_direction = 4;
    jeu.score = 0;
    jeu.touche = 0;
    jeu.jeu_en_cours = 1;
    jeu.score_str[100];

    terrain.x = 600;
    terrain.y = 400;
    terrain.fond;
    terrain.o = 0;
    terrain.obstacle;
    terrain.obstacle_on = 1;
    terrain.obstaclex[15];
    terrain.obstacley[15];

    snake.pos_x[2400];
    snake.pos_y[2400];
    snake.old_x[2400];
    snake.old_y[2400];
    snake.serpent;
    snake.segment = 10;

    pill.pastille;
    pill.pastillex[5];
    pill.pastilley[5];

    /* Initialisation graphique*/
    EffacerEcran(CouleurParComposante(114, 148, 77));
    temps.suivant = Microsecondes() + CYCLE;
    temps.old_seconde = (temps.suivant / 1000000) % 10;
    DessinerScene(&temps, &terrain, &snake, &pill);
    ChoisirCouleurDessin(CouleurParComposante(114, 148, 77));
    RemplirRectangle(0, 700, 1200, 800);

    /*Boucle principale du jeu*/ 
    while (jeu.jeu_en_cours) {
        Controle(&jeu);
        if (jeu.paused == 0) {
            Timer(&temps);
            Update_Timer(&temps);
            Serpent(&snake, &terrain, &jeu, &pill, &temps);
            Pastille(&pill);
            Update_Score(&jeu);
        }
    }

    /* Appel de l'écran de fin du jeu*/
    EcranFinJeu(&jeu, &temps);
    return EXIT_SUCCESS;
}

/* Fonction principale*/
int main() {
    int choix = 0;
    int jeu2 = 0;
    int exitgame = 0;

    /*Initialisation graphique*/
    InitialiserGraphique();
    CreerFenetre(0, 0, 1200, 800);

    /* Affichage du menu et gestion du choix*/
    afficher_menu(&choix, &jeu2, &exitgame);
    if (choix == 1) {
        lancer_jeu();
    } else if (jeu2 == 1) {
        lancer_jeu2();
    } else if (exitgame == 1) {
        FermerGraphique();
        return EXIT_SUCCESS;
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}
