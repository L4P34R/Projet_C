
#ifndef AREA_H
#define AREA_H

#include "shapes.h"
#define SHAPE_MAX 100   // Nombre maximum de formes
#define BOOL int

struct area {
    unsigned int width; // Nombre de pixels en largeur ou nombre de colonnes (axe y) unsigned int height; // Nombre de pixels en hauteur ou nombre de lignes (axe x) BOOL** mat; // Matrice des pixels de taille (width * height)
    Shape* shapes[SHAPE_MAX]; // Tableau des formes;
    int nb_shape; // Nombre de formes dans le tableau shapes (taille logique)
};
typedef struct area Area;

#endif //PROJET_C_AREA_H
