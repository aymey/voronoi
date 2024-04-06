#include "voronoi.h"
#include <time.h>

bool generate_voronoi(Point *points, size_t amount) {

}

Point *generate_points(size_t amount) {
    Point *points = malloc(sizeof(Point)*amount);
    srand(time(NULL));
    for(size_t i = 0; i < amount; i++)
        points[i] = (Point){
            rand()%GetScreenWidth(),
            rand()%GetScreenHeight(),
            BLACK
        };

    return points;
}

Point calc_midpoint(Point a, Point b) {
    return (Point) {
        (a.x + b.x)/2.,
        (a.y + b.y)/2.,
        BLACK
    };
}

Vector2 calc_vector(Point a, Point b) {
    return (Vector2) {
        b.x - a.x,
        b.y - a.y
    };
}

Vector2 calc_normal(Vector2 vector) {
    return (Vector2) {
        -vector.y,
        vector.x
    };
}

void draw_points(Point *points, size_t amount) {
    for(size_t i = 0; i < amount; i++)
        DrawCircle(points[i].x, points[i].y, 5, BLACK);

    for(size_t i = 0; i < amount; i++) {
        for(size_t j = 0; j < amount; j++) {
            if(i == j)
                continue;
            Point midpoint = calc_midpoint(points[i], points[j]);
            Vector2 vector = calc_vector(points[i], points[j]);
            Vector2 normal = calc_normal(vector);
            DrawLine(
                midpoint.x, midpoint.y,
                midpoint.x + normal.x, midpoint.y + normal.y,
                BLACK
            );
        }
    }
}
