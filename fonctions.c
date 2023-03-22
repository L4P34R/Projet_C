#include <stdio.h>
#include "fonctions.h"

void menu(){
    int action;
    printf("Veuillez choisir une action :\n1- Ajouter une forme\n2- Afficher la liste des formes\n3- Supprimer une forme\n4- Tracer le dessin\n5- Aide");
    scanf("%d",&action);
    switch (action) {
        case 1:
            menuForme();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Veuiller choisir un choix valide !\n\n");
            menu();
            break;
    }
}

void menuForme(){
    printf("1");
}