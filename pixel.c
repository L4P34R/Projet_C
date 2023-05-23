#include "pixel.h"
#include "shapes.h"
#include <stdlib.h>

void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels)
{
    Point* pt    = (Point*) shape->ptrShape;
    *pixel_tab    = (Pixel**) malloc (sizeof (Pixel*));
    *pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels   = 1;
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