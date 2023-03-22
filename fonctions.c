#include <stdio.h>
#include "fonctions.h"

void menu(){
    int action;
    printf("choisissez :");
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