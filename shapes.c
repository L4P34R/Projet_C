#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"


Point *create_point(int px, int py){
    Point* p = (Point*) malloc(sizeof(Point*));
    p -> pos_x = px;
    p -> pos_y = py;
    return p;
}
void delete_point(Point * point){
    free(point);
}
void print_point(Point * p){
    printf("%d %d ", p -> pos_x, p -> pos_y);
}

Line *create_line(Point * p1, Point * p2){
    Line* line = (Line*)malloc(sizeof (Line*));
    line -> p1 = p1;
    line -> p2 = p2;
    return line;
}
void delete_line(Line * line){
    free(line);
}
void print_line(Line * line){
    print_point(line -> p1);
    print_point(line -> p2);
}

Square *create_square(Point * point, int length){
    Square* square;
    square -> p = point;
    square -> longueur = length;
    return square;
}
void delete_square(Square * square){
    free(square);
}
void print_square(Square * square){
    print_point(square -> p);
    printf("%d ", square -> longueur);
}

Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle* rect;
    rect -> p = point;
    rect -> width = width;
    rect -> height = height;
    return rect;
}
void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
}
void print_rectangle(Rectangle * rectangle){
    print_point(rectangle -> p);
    printf("%d %d ", rectangle -> width, rectangle -> width);
}

Circle *create_circle(Point * center, int radius){
    Circle* circle;
    circle -> center = center;
    circle -> radius = radius;
    return circle;
}
void delete_circle(Circle * circle){
    free(circle);
}
void print_circle(Circle * circle){
    print_point(circle -> center);
    printf("%d", circle -> radius);
}

Polygon *create_polygon(int n, Point lst[]){
    Polygon* poly = (Polygon*) malloc(sizeof(Polygon));
    poly -> points = lst;
    return poly;
}
void delete_polygon(Polygon * polygon){
    free(polygon);
}
void print_polygon(Polygon * polygon){
    for(int i = 0; i < polygon -> n; i++){
        print_point(polygon -> points[i]);
    }
}

Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape)); shp->ptrShape = NULL;
    shp->id = 1; // plus tard on appelera get_next_id()
    shp-> shape_type = shape_type;
    return shp;
}
Shape *create_point_shape(int px, int py) {
    Shape *shp    = create_empty_shape(POINT);
    Point *p      = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}
Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape* shp = create_empty_shape(LINE);
    Point* p1 = create_point(px1, py1);
    Point* p2 = create_point(px2, py2);
    Line* line = create_line(p1, p2);
    shp -> ptrShape = line;
    return shp;
}
Shape *create_square_shape(int px, int py, int length){
    Shape* shp = create_empty_shape(SQUARE);
    Point* p = create_point(px, py);
    Square* square = (Square*) malloc(sizeof(Square*));
    square -> p = p;
    square -> longueur = length;
    shp -> ptrShape = square;
    return shp;
}
Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape* shp = create_empty_shape(RECTANGLE);
    Point* p = create_point(px, py);
    Rectangle* rect = (Rectangle*) malloc(sizeof(Rectangle*));
    rect -> p = p;
    rect -> height = height;
    rect -> width = width;
    shp -> ptrShape = rect;
    return shp;
}
Shape *create_circle_shape(int px, int py, int radius){
    Shape* shp = create_empty_shape(CIRCLE);
    Point* p = create_point(px, py);
    Circle* circle = create_circle(p, radius);
    shp -> ptrShape = circle;
    return shp;
}
Shape *create_polygon_shape(int lst[], int n){
    Shape* shp = create_empty_shape(POLYGON);
    Point** points = (Point**) malloc(n * sizeof(Point*));
    for (int i = 0; i < n; i++){
        points[i] = create_point(lst[2 * i], lst[2 * i + 1]);
    }
    Polygon* poly = (Polygon*) malloc(sizeof(Polygon*));
    poly -> n = n;
    poly -> points = points;
    shp -> ptrShape = poly;
    return shp;
}
void delete_shape(Shape * shape){
    switch (shape -> shape_type){
        case 0:
            delete_point(shape -> ptrShape);
        case 1:
            delete_line(shape -> ptrShape);
        case 2:
            delete_square(shape -> ptrShape);
        case 3:
            delete_rectangle(shape -> ptrShape);
        case 4:
            delete_circle(shape -> ptrShape);
        case 5:
            delete_polygon(shape -> ptrShape);
    }
    free(shape);
}
void print_shape(Shape * shape){
    switch (shape -> shape_type){
        case 0:
            printf("POINT ");
            print_point(shape -> ptrShape);
        case 1:
            printf("LINE ");
            print_line(shape -> ptrShape);
        case 2:
            printf("SQUARE ");
            print_square(shape -> ptrShape);
        case 3:
            printf("RECTANGLE" );
            print_rectangle(shape -> ptrShape);
        case 4:
            printf("CIRCLE ");
            print_circle(shape -> ptrShape);
        case 5:
            printf("POLYGON ");
            print_polygon(shape -> ptrShape);
    }
    printf("\n");
}