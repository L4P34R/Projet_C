#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main() {
    void* shapes;
    shapes = malloc(0);
    menu(shapes);
    return 0;
}
