#include <raylib.h>
#include "voronoi.h"

#define POINTS 3
int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(0, 0, "voronoi");

    Point *points = generate_points(POINTS);
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BROWN);
            draw_points(points, POINTS);
        EndDrawing();
    }

    CloseWindow();

    free(points);
    return 0;
}
