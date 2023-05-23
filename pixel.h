#include "shapes.h"

#ifndef PIXEL_H
#define PIXEL_H

struct pixel {
    int px;
    int py; };
typedef struct pixel Pixel;
Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel * pixel);


Pixel* create_pixel(int px, int py);
void delete_pixel(Pixel* pixel);
void pixel_forme(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_line(Shape* line, Pixel*** pixel_tab, int* nb_pixels);
void pixel_circle(Shape* shape, Pixel*** pixel_tab, int *nb_pixels);

#endif
