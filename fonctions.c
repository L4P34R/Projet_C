#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "shapes.h"
#include "id.h"

Shape *tableau[100];
int nb_shape = 0;

void menu(){
    char action = 'A';
    printf(" Veuillez choisir une action :\n"
           "        A- Ajouter une forme\n"
           "        B- Afficher la liste des formes\n"
           "        C- Supprimer une forme\n"
           "        D- Tracer le dessin\n"
           "        E- Aide\n");
    printf("Votre choix : ");
    scanf(" %c",&action);
    switch (action) {
        case 'A':
            menuForme();
            break;
        case 'B':
            menuAfficherforme();
            break;
        case 'C':
            break;
        case 'D':
            break;
        case 'E':
            break;
        default:
            printf("Veuiller choisir un choix valide !\n\n");
            menu();
            break;
    }
}

void menuForme(){
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
            int py1 = 0;
            scanf("%d %d", &px1, &py1);
            Shape* point = create_point_shape(px1,py1);
            tableau[nb_shape] = point;
            nb_shape ++;
            menu();
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
            Shape* line = create_line_shape(px1, py1, px22, py22);
            tableau[nb_shape] = line;
            nb_shape ++;
            menu();
            break;
        case 3:
            printf("Choisir les coordonées x1 y1 du point : \n");
            int px3 = 0;
            int py3 = 0;
            scanf("%d %d", &px3, &py3);
            printf("Choisir le rayon du cercle : \n");
            int r = 0;
            scanf("%d",&r);
            Shape* circle = create_circle_shape(px3,py3,r);
            tableau[nb_shape] = circle;
            nb_shape ++;
            menu();
            break;
        case 4:
            printf("Choisir les coordonées x1 y1 du point : \n");
            int px4 = 0;
            int py4 = 0;
            scanf("%d %d", &px4, &py4);
            printf("Choisir la longueur du coté : \n");
            int l1 = 0;
            scanf("%d",&l1);
            Shape* square = create_square_shape(px4, py4, l1);
            tableau[nb_shape] = square;
            nb_shape ++;
            menu();
            break;
        case 5:
            printf("Choisir les coordonées x y du point : \n");
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
            tableau[nb_shape] = rectangle;
            nb_shape ++;
            menu();
            break;
        case 6:
            printf("Choisir le nombre de sommet du polygone :\n");
            int n;
            int *coord = malloc(n * sizeof(int)) ;
            scanf("%d",&n);
            int px6 = 0;
            int py6 = 0;
            for (int i = 0; i<n; i++) {
                printf("Choisir les coordonées x y du point : \n");
                scanf("%d %d", &px6, &py6);
                coord[2 * i] = px6;
                coord[2 * i + 1] = py6;
            }
            Shape* poly = create_polygon_shape(coord, n);
            tableau[nb_shape] = poly;
            nb_shape ++;
            menu();
            break;
        case 7:
            menu();
            break;
        default:
            printf("Veuiller choisir un choix valide !\n");
            menuForme();
            break;
    }
}

void menuAfficherforme(void* shapes){
    printf("Liste des formes :\n");
    for (int i = 0; i < nb_shape; i++){
        print_shape(tableau[i]);
    }
    menu();
}