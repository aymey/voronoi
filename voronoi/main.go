package main

import rl "github.com/gen2brain/raylib-go/raylib"

type HalfEdge struct {
    origin rl.Vector2
    destination rl.Vector2
    twin *HalfEdge
    incidentFace *Face
    prev *HalfEdge
    next *HalfEdge
}

type Face struct {
    Site *Site
    outerComponent *HalfEdge
}

type Site struct {
    Index int
    Point rl.Vector2
    Face *Face
}

type VoronoiDiagram struct {
    Sites []Site
    Faces []Face
    Verticies []rl.Vector2
    HalfEdges []HalfEdge
}

func main() {
    rl.SetConfigFlags(rl.FlagWindowResizable);
	rl.InitWindow(800, 450, "voronoi")
	defer rl.CloseWindow()

	rl.SetTargetFPS(60)

	for !rl.WindowShouldClose() {
		rl.BeginDrawing()

        rl.ClearBackground(rl.Brown)

		rl.EndDrawing()
	}
}
