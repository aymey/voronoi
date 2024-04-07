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
    site *Site
    outerComponent *HalfEdge
}

type Site struct {
    index int
    point rl.Vector2
    face *Face
}

type VoronoiDiagram struct {
    sites []Site
    faces []Face
    verticies []rl.Vector2
    halfEdges []HalfEdge
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
