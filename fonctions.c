#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "shapes.h"

void menu(void* shapes){
    char action;
    printf(" Veuillez choisir une action :\n"
           "        A- Ajouter une forme\n"
           "        B- Afficher la liste des formes\n"
           "        C- Supprimer une forme\n"
           "        D- Tracer le dessin\n"
           "        E- Aide\n");
    scanf("%c",&action);
    printf("Votre choix");
    switch (action) {
        case 'A':
            menuForme(shapes);
            break;
        case 'B':
            break;
        case 'C':
            break;
        case 'D':
            break;
        case 'E':
            break;
        default:
            printf("Veuiller choisir un choix valide !\n\n");
            menu(shapes);
            break;
    }
}

void menuForme(void* shapes){
    int choix;
    printf("Veuillez choisir une action :\n"
            "            1- Ajouter un point\n"
            "            2- Ajouter une ligne\n"
            "            3- Ajouter cercle\n"
            "            4- Ajouter un carre\n"
            "            5- Ajouter un rectangle\n"
            "            6- Ajouter un polygone\n"
            "            7- Revenir au menu precedent\n");
    scanf("%d", &choix);
    switch(choix){
        int px;
        case 1:
            px = 0;
            int py = 0;
            printf("Choisir les coordonées px py du point : \n");
            scanf("%d %d", &px, & py);
            void* shp = create_point_shape(px, py);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            printf("Veuiller choisir un choix valide !\n\n");
            menuForme(shapes);
    }
}