#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../include/serpent.h"
#include "../include/timer.h"
#include "../include/structures.h"
#include "../include/jeu.h"
#define CYCLE 10000L


/* Fonction pour mettre à jour l'affichage du minuteur*/
void Update_Timer(TIMER *temps){
    /* Formatage du temps sous forme de texte (MM:SS)*/
    snprintf(temps->timer, 6, "%02d:%02d", temps->minute, temps->seconde);

    /* Effacement de la zone du minuteur*/
    ChoisirCouleurDessin(CouleurParComposante(114,148,77));
    RemplirRectangle(0, 700, 400, 800);

    /* Affichage du minuteur en blanc*/
    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
    EcrireTexte(10, 760, temps->timer, 2);
}

/* Fonction pour gérer la logique du minuteur*/
void Timer(TIMER *temps) { 
    /* Vérification si le cycle est écoulé*/
    if (Microsecondes() > temps->suivant) {
        /* Mise à jour du prochain cycle*/
        temps->suivant = Microsecondes() + CYCLE;

        /* Récupération de la seconde actuelle*/
        temps->seconde_actuel = (temps->suivant / 1000000) % 10;

        /* Vérification si la seconde a changé depuis la dernière mise à jour*/
        if (temps->seconde_actuel != temps->old_seconde) {
            /* Mise à jour de l'ancienne seconde*/
            temps->old_seconde = temps->seconde_actuel;

            /* Vérification si une minute est écoulée*/
            if (temps->seconde == 59) {
                temps->minute += 1;
                temps->seconde = 0;

                /* Mise à jour de l'affichage du minuteur*/
                Update_Timer(temps);
            } else {
                temps->seconde = temps->seconde + 1;

                /* Mise à jour de l'affichage du minuteur*/
                Update_Timer(temps); 
            }
        }
    }
}
