CC = gcc
CFLAGS = -Wall -Wextra -lm -lraylib

voronoi: src/*.c
	$(CC) $(CFLAGS) src/*.c -o voronoi
