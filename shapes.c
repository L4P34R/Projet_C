#include <stdlib.h>
#include "shapes.h"


Point *create_point(int px, int py){
    Point* p = (Point*) malloc(sizeof(Point));
    p -> pos_x = px;
    p -> pos_y = py;
    return p;
}
void delete_point(Point * point){
    free(point);
}
void print_point(Point * p);

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape)); shp->ptrShape = NULL;
    shp->id = 1; // plus tard on appelera get_next_id(); shp->shape_type = shape_type;
    return shp;
}
Shape *create_point_shape(int px, int py) {
    Shape *shp    = create_empty_shape(POINT);
    Point *p      = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radus);
Shape *create_polygon_shape(int lst[], int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);