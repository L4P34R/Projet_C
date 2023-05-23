#include "pixel.h"
#include "shapes.h"
#include <stdlib.h>


Pixel *create_pixel(int px, int py){
    Pixel* pix;
    pix->px = px;
    pix->py = py;
    return pix;
}

void delete_pixel(Pixel* pixel){
    free(pixel);
}

void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels){
    Point* pt    = (Point*) shape->ptrShape;
    *pixel_tab    = (Pixel**) malloc (sizeof (Pixel*));
    *pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels   += 1;
}

void pixel_line(Shape* line, Pixel*** pixel_tab, int* nb_pixels){
    Line* l = line->ptrShape;
    int xa = l->p1->pos_x;
    int ya = l->p1->pos_y;
    int xb = l->p2->pos_x;
    int yb = l->p2->pos_x;
    int dx = xb - xa;
    int dy = yb - ya;
    if(dx > 0){
        int dmin = 0;
        int dmax = 0;
        if(dy >= 0){
          if(dx > dy){
              dmin = dy;
              dmax = dx;
          }
          else{
              dmin = dx;
              dmax = dy;
          }
        }
        else{
            if(dx > -dy){
                dmin = -dy;
                dmax = dx;
            }
            else{
                dmin = dx;
                dmax = -dy;
            }
        }
        int nb_seg = dmin + 1;
        int taille = (dmax + 1)/nb_seg;
        int* segments = malloc(nb_seg*sizeof(int));
        for (int i = 0; i < nb_seg; i++){
            segments[i] = taille;
        }
        int reste = (dmax + 1)%nb_seg;
        int *cumuls = (int *)malloc(nb_seg*sizeof(int)); cumuls[0]=0;
        for (int i = 1; i < nb_seg;i++)
        {
            cumuls[i] = ((i+1)*reste)%(dmin+1) < (i*reste)%(dmin+1);
            segments[i] = segments[i]+cumuls[i];
        }
        if (dy < 0){
            if (dx > -dy) {
                int pix_x = xa;
                int pix_y = ya;
                for (int i =0; i < nb_seg - 1; i++){
                    for(int j = 0; j < segments[i]; j++){
                        pix_x += j;
                        *pixel_tab[(*nb_pixels)++] = create_pixel(pix_x, pix_y);
                    }
                    pix_y -= i;
                }
            }
            else{
                int pix_x = xa;
                int pix_y = ya;
                for (int i =0; i < nb_seg - 1; i++){
                    for(int j = 0; j < segments[i]; j++){
                        pix_y -= j;
                        *pixel_tab[(*nb_pixels)++] = create_pixel(pix_x, pix_y);
                    }
                    pix_x += i;
                }
            }
        }
        else{
            if (dx > dy){
                int pix_x = xa;
                int pix_y = ya;
                for (int i =0; i < nb_seg - 1; i++){
                    for(int j = 0; j < segments[i]; j++){
                        pix_x += j;
                        *pixel_tab[(*nb_pixels)++] = create_pixel(pix_x, pix_y);
                    }
                    pix_y += i;
                }
            }
            else{
                int pix_x = xa;
                int pix_y = ya;
                for (int i =0; i < nb_seg - 1; i++){
                    for(int j = 0; j < segments[i]; j++){
                        pix_y += j;
                        *pixel_tab[(*nb_pixels)++] = create_pixel(pix_x, pix_y);
                    }
                    pix_x += i;
                }
            }

        }
    }
    else{
        int dmin = 0;
        int dmax = 0;
        if(dy >= 0){
            if(-dx > dy){
                dmin = dy;
                dmax = -dx;
            }
            else{
                dmin = -dx;
                dmax = dy;
            }
        }
        else{
            if(-dx > -dy){
                dmin = -dy;
                dmax = -dx;
            }
            else{
                dmin = -dx;
                dmax = -dy;
            }
        }
        int nb_seg = dmin + 1;
        int taille = (dmax + 1)/nb_seg;
        int* segments = malloc(nb_seg*sizeof(int));
        for (int i = 0; i < nb_seg; i++){
            segments[i] = taille;
        }
        int reste = (dmax + 1)%nb_seg;
        int *cumuls = (int *)malloc(nb_seg*sizeof(int)); cumuls[0]=0;
        for (int i = 1; i < nb_seg;i++)
        {
            cumuls[i] = ((i+1)*reste)%(dmin+1) < (i*reste)%(dmin+1);
            segments[i] = segments[i]+cumuls[i];
        }
        if (dy < 0){
            if (-dx > -dy) {
                int pix_x = xa;
                int pix_y = ya;
                for (int i =0; i < nb_seg - 1; i++){
                    for(int j = 0; j < segments[i]; j++){
                        pix_x -= j;
                        *pixel_tab[(*nb_pixels)++] = create_pixel(pix_x, pix_y);
                    }
                    pix_y -= i;
                }
            }
            else{
                int pix_x = xa;
                int pix_y = ya;
                for (int i =0; i < nb_seg - 1; i++){
                    for(int j = 0; j < segments[i]; j++){
                        pix_y -= j;
                        *pixel_tab[(*nb_pixels)++] = create_pixel(pix_x, pix_y);
                    }
                    pix_x -= i;
                }
            }
        }
        else{
            if (-dx > dy){
                int pix_x = xa;
                int pix_y = ya;
                for (int i =0; i < nb_seg - 1; i++) {
                    for (int j = 0; j < segments[i]; j++) {
                        pix_x -= j;
                        *pixel_tab[(*nb_pixels)++] = create_pixel(pix_x, pix_y);
                    }
                    pix_y += i;
                }
            }
            else{
                int pix_x = xa;
                int pix_y = ya;
                for (int i =0; i < nb_seg - 1; i++) {
                    for (int j = 0; j < segments[i]; j++) {
                        pix_y += j;
                        *pixel_tab[(*nb_pixels)++] = create_pixel(pix_x, pix_y);
                    }
                    pix_x -= i;
                }
            }

        }
    }
}


void pixel_circle(Shape* shape, Pixel*** pixel_tab, int *nb_pixels){
    int x = 0;
    int posX = ((Circle*)shape->ptrShape)->center->pos_x;
    int posY = ((Circle*)shape->ptrShape)->center->pos_y;
    int y = ((Circle*)shape->ptrShape)->radius;
    int d = y-1;
    Pixel* px = NULL;
    while (y >= x){
        px = create_pixel(posX + x, posY + y);
        *pixel_tab[(*nb_pixels)++] = px;

        px = create_pixel(posX + y, posY + x);
        *pixel_tab[(*nb_pixels)++] = px;

        px = create_pixel(posX - x, posY + y);
        *pixel_tab[(*nb_pixels)++] = px;

        px = create_pixel(posX - y, posY + x);
        *pixel_tab[(*nb_pixels)++] = px;

        px = create_pixel(posX + x, posY - y);
        *pixel_tab[(*nb_pixels)++] = px;

        px = create_pixel(posX + y, posY - x);
        *pixel_tab[(*nb_pixels)++] = px;

        px = create_pixel(posX - x, posY - y);
        *pixel_tab[(*nb_pixels)++] = px;

        px = create_pixel(posX - y, posY - x);
        *pixel_tab[(*nb_pixels)++] = px;
        if(d >= 2*x){
            d -= 2*x + 1;
            x++;
        }
        else if(d < 2 * ((Circle*)shape->ptrShape)->radius - y){
            d += 2 * y - 1;
            y--;
        }
        else{
            d += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
}

void pixel_square(Shape* square, Pixel*** pixel_tab, int* nb_pixels){
    int x = ((Square*)square->ptrShape)->p->pos_x;
    int y  = ((Square*)square->ptrShape)->p->pos_y;
    int longueur = ((Square*)square->ptrShape)->longueur;
    for(int i  = 0; i < longueur; i++){
        (*pixel_tab)[*nb_pixels++] = create_pixel(x + i, y);
        (*pixel_tab)[*nb_pixels++] = create_pixel(x , y + i);
        (*pixel_tab)[*nb_pixels++] = create_pixel(x + longueur, y + i);
        (*pixel_tab)[*nb_pixels++] = create_pixel(x + i , y + longueur);
    }
}

void pixel_rectangle(Shape* rectangle, Pixel*** pixel_tab, int* nb_pixels){
    int x = ((Square*)rectangle->ptrShape)->p->pos_x;
    int y  = ((Square*)rectangle->ptrShape)->p->pos_y;
    int longueur = ((Rectangle*)rectangle->ptrShape)->width;
    int hauteur = ((Rectangle*)rectangle->ptrShape)->height;
    for(int i  = 0; i < longueur; i++){
        (*pixel_tab)[*nb_pixels++] = create_pixel(x + i, y);
        (*pixel_tab)[*nb_pixels++] = create_pixel(x + i , y + hauteur);
    }
    for(int i  = 0; i < hauteur; i++) {
        (*pixel_tab)[*nb_pixels++] = create_pixel(x , y + i);
        (*pixel_tab)[*nb_pixels++] = create_pixel(x + longueur, y + i);
    }
}

void pixel_polygon(Shape* polygon, Pixel*** pixel_tab, int* nb_pixels){
    Point** points = ((Polygon*)polygon->ptrShape)->points;
    int n = ((Polygon*)polygon->ptrShape)->n;
    for (int i = 0; i < n - 1; i++){
        int px1 = points[i]->pos_x;
        int py1 = points[i]->pos_y;
        int px2 = points[i + 1]->pos_x;
        int py2 = points[i + 1]->pos_y;
        pixel_line(create_line_shape(px1, py1, px2, py2), pixel_tab, nb_pixels);
    }
}

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels){
    Pixel** pixels = malloc(*nb_pixels * sizeof(Pixel*));
    switch (shape -> shape_type){
        case 0:
            pixel_point(shape, &pixels, nb_pixels);
            break;
        case 1:
            pixel_line(shape, &pixels, nb_pixels);
            break;
        case 2:
            pixel_line(shape, &pixels, nb_pixels);
            break;
        case 3:
            pixel_rectangle(shape, &pixels, nb_pixels);
            break;
        case 4:
            pixel_circle(shape, &pixels, nb_pixels);
            break;
        case 5:
            pixel_polygon(shape, &pixels, nb_pixels);
            break;
    }
    return pixels;
}

void delete_pixel_shape(Pixel*** pixel, int nb_pixels){
    for(int i = nb_pixels; i >= 0; i--){
        delete_pixel(pixel[i]);
    }
}
