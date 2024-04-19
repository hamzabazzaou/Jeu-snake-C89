#ifndef STRUCTURES_H
#define STRUCTURES_H

/* Structure pour représenter le chronomètre du jeu */
struct Timer_s {
    int seconde;             /* Secondes*/
    int minute;              /* Minutes*/
    int seconde_actuel;      /* Valeur actuelle des secondes*/
    int old_seconde;         /* Ancienne valeur des secondes*/
    char timer[6];           /* Chaîne de caractères représentant le temps*/
    unsigned long int suivant;/* Champ supplémentaire de type unsigned long int*/
};

/* Alias de type TIMER pour la structure Timer_s*/
typedef struct Timer_s TIMER;

/* Structure pour représenter les caractéristiques du terrain de jeu */
struct Terrain_s {
    int x;                /* Coordonnée x du coin supérieur gauche*/
    int y;                /*Coordonnée y du coin supérieur gauche*/ 
    int fond;             /* Couleur de fond*/
    int o;                /* Indice pour les obstacles*/
    int obstacle;         /* Identifiant de l'obstacle*/
    int obstacle_on;      /* Indicateur d'activation des obstacles*/
    int obstaclex[15];    /* Tableau des coordonnées x des obstacles*/
    int obstacley[15];    /* Tableau des coordonnées y des obstacles*/
};

/* Alias de type TERRAIN pour la structure Terrain_s*/
typedef struct Terrain_s TERRAIN;

/* Structure pour représenter les informations sur le jeu */
struct Jeu_s {
    int direction;         /* Direction du serpent*/
    int last_direction;    /* Dernière direction*/
    int jeu_en_cours;      /* Indicateur du statut du jeu*/
    int score;             /* Score du joueur*/
    int touche;            /* Variable liée à une touche*/
    int paused;            /* Variable de pause*/
    char score_str[100];   /* Chaîne de caractères pour le score*/
};

/* Alias de type JEU pour la structure Jeu_s*/
typedef struct Jeu_s JEU;

/* Structure pour représenter les caractéristiques du serpent */
struct Serpent_s {
    int serpent;           /* Identifiant du serpent*/
    int segment;           /* Nombre de segments du serpent*/
    int pos_x[2400];       /* Tableau des positions x du serpent*/
    int pos_y[2400];       /* Tableau des positions y du serpent*/
    int old_x[2400];       /* Tableau des anciennes positions x du serpent*/
    int old_y[2400];       /* Tableau des anciennes positions y du serpent*/
};

/* Alias de type SERPENT pour la structure Serpent_s*/
typedef struct Serpent_s SERPENT;

/* Structure pour représenter les informations sur les pastilles du jeu */
struct Pastille_s {
    int p;                 /* Identifiant de la pastille*/
    int pastille;          /* Identifiant de la pastille*/
    int pastillex[5];      /* Tableau des positions x des pastilles*/
    int pastilley[5];      /* Tableau des positions y des pastilles*/
};

/* Alias de type PASTILLE pour la structure Pastille_s*/
typedef struct Pastille_s PASTILLE;

/* Structure représentant une zone clickable dans l'interface */
typedef struct {
    int x;  /* Coordonnée x du coin supérieur gauche*/
    int y;  /* Coordonnée y du coin supérieur gauche*/
    int L;  /* Largeur de la zone*/
    int H;  /* Hauteur de la zone*/
} Zone;

#endif
