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
    printf("Votre choix : ");
    scanf("%c",&action);
    switch (action) {
        case 'A':
            menuForme(shapes);
            break;
        case 'B':
            menuAfficherforme(shapes);
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
    printf("Votre choix : ");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            printf("Choisir les coordonées x y du point : \n");
            int px1 = 0;
            int py2 = 0;
            scanf("%d %d", &px1, &py2);
            Shape* point = create_point_shape(px1, py2);
            menuForme(shapes);
            break;
        case 2:
            printf("Choisir les coordonées x1 y1 du premier point de la ligne : \n");
            int py21 = 0;
            int px21 = 0;
            scanf("%d %d", &px21, &py21);
            printf("Choisir les coordonées x2 y2 du deuxième point de la ligne : \n");
            int py22 = 0;
            int px22 = 0;
            scanf("%d %d", &px22, &py22);
            Shape* line = create_line_shape(px21,py21,px22,py22);
            print_shape(line);
            menuForme(shapes);
            break;
        case 3:
            printf("Choisir les coordonées x1 x1 du point : \n");
            int px3 = 0;
            int py3 = 0;
            scanf("%d %d", &px3, &py3);
            printf("Choisir le rayon du cercle : \n");
            int r = 0;
            scanf("%d",&r);
            Shape* circle = create_circle_shape(px3,py3,r);
            menuForme(shapes);
            break;
        case 4:
            printf("Choisir les coordonées x1 x1 du point : \n");
            int px4 = 0;
            int py4 = 0;
            scanf("%d %d", &px4, &py4);
            printf("Choisir la longueur du coté : \n");
            int l1 = 0;
            scanf("%d",&l1);
            Shape* square = create_square_shape(px4, py4, l1);
            menuForme(shapes);
            break;
        case 5:
            printf("Choisir les coordonées x1 x1 du point : \n");
            int px5 = 0;
            int py5 = 0;
            scanf("%d %d", &px5, &py5);
            printf("Choisir la longueur du rectangle : \n");
            int l2 = 0;
            scanf("%d",&l2);
            printf("Choisir la hauteur du rectangle : \n");
            int h1 = 0;
            scanf("%d",&h1);
            Shape* rectangle = create_rectangle_shape(px5, py5,l2,h1);
            menuForme(shapes);
            break;
        case 6:
            menuForme(shapes);
            break;
        case 7:
            menu(shapes);
            break;
        default:
            printf("Veuiller choisir un choix valide !\n\n");
            menuForme(shapes);
    }
}

void menuAfficherforme(void* shapes){
    printf("Liste des formes :");
    print_shape(shapes);
}