#include "shapes.h"

#ifndef PIXEL_H
#define PIXEL_H

struct pixel {
    int px;
    int py; };
typedef struct pixel Pixel;


Pixel* create_pixel(int px, int py);
void delete_pixel(Pixel* pixel);
void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_line(Shape* line, Pixel*** pixel_tab, int* nb_pixels);
void pixel_circle(Shape* shape, Pixel*** pixel_tab, int *nb_pixels);
void pixel_square(Shape* square, Pixel*** pixel_tab, int* nb_pixels);
void pixel_rectangle(Shape* rectangle, Pixel*** pixel_tab, int* nb_pixels);
void pixel_polygon(Shape* polygon, Pixel*** pixel_tab, int* nb_pixels);
Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);
void delete_pixel_shape(Pixel*** pixel, int nb_pixels);

#endif
