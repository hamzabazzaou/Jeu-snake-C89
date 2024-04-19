#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/structures.h"



/* Fonction qui vérifie si les coordonnées (x, y) sont à l'intérieur de la zone z*/
int check_zone(Zone z, int x, int y) {
    return (x >= z.x && x <= (z.x + z.L) && y >= z.y && y <= (z.y + z.H));
}

/*Fonction qui affiche le menu et attend la sélection de l'utilisateur*/ 
int afficher_menu(int *choix, int *jeu2, int *exitgame) {
    /* Définition des zones pour les différentes options du menu*/
    Zone commencer = {758, 330, 179, 66};
    Zone obstacle = {758, 418, 179, 66};
    Zone exit = {758, 509, 179, 66};

    /* Chargement de l'image de fond du menu*/
    ChargerImageFond("image/menu.png");

    /* Boucle principale du menu*/
    while (1) {
        SourisPosition();

        /* Vérification si la souris a été cliquée*/
        if (SourisCliquee()) {
            int x = _X;
            int y = _Y;

            /* Vérification dans quelle zone la souris a été cliquée*/
            if (check_zone(commencer, x, y)) {
                *choix = 1;  /* Sélection de l'option "Commencer"*/
                return;
            } else if (check_zone(obstacle, x, y)) {
                *jeu2 = 1;   /* Sélection de l'option "Obstacle"*/
                return;
            } else if (check_zone(exit, x, y)) {
                *exitgame = 1;  /* Sélection de l'option "Quitter"*/
                return;
            }
        }
    }
}
