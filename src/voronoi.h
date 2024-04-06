#include <raylib.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    float x;
    float y;
    Color colour;
} Point;


Point *generate_points(size_t amount);
Point midpoint(Point a, Point b);
Vector2 calc_vector(Point a, Point b);
void draw_points(Point *points, size_t amount);

bool generate_voronoi(Point *points, size_t amount);
