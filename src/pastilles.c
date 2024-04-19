#include <stdlib.h>
#include <graph.h>
#include "../include/serpent.h"
#include "../include/structures.h"

/* Fonction qui affiche les sprites de pastilles à leurs positions respectives*/
void Pastille(PASTILLE *pill) {
    int pp;

    /* Boucle sur chaque pastille*/
    for (pp = 0; pp < 5; ++pp) {
        /* Affichage du sprite de pastille à la position (pastillex[pp], pastilley[pp])*/
        AfficherSprite(pill->pastille, pill->pastillex[pp], pill->pastilley[pp]);
    }
}
