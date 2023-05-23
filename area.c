#include "area.h"
#include <stdio.h>
#include <stdlib.h>

Area* create_area(unsigned int width, unsigned int height){
    Area area;
    area.width = width;
    area.height = height;
    area.mat = malloc(height * width *sizeof(BOOL));
    return &area;
}
void add_shape_to_area(Area* area, Shape* shape){
    area->shapes[area->nb_shape++] = shape;
}
void clear_area(Area* area){
    for(int i = 0; i < area->height; i++){
        for(int j = 0; j < area->width; j++){
            area->mat[i][j] = 0;
        }
    }
}
void erase_area(Area* area){
    for(int i = 0; i < area->nb_shape; i++){
        delete_shape(area->shapes[i]);
    }
}
void delete_area(Area* area){
    free(area->mat);
    erase_area(area);
    free(area);
}
void draw_area(Area* area){
    for(int i = 0; i < area->nb_shape; i++){
        Pixel** pixels  = create_shape_to_pixel(area->shapes[i]);
    }
}
void print_area(Area* area);
