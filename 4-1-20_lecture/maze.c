#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define VISITED 5

typedef struct {
    int nrows;
    int ncols;
    int **maze;
} Maze;

int8_t findPath(Maze* m, int r, int c) {

    m->maze[r][c] = VISITED;

    if(canUp(m, r - 1, c) && !visited(m, r - 1, c)) {
        if( findPath(m, r - 1, c) ) {
            return 1;
        }
    }
    if(canRight(m, r, c + 1) && !visited(m, r - 1, c)) {
        if( findPath(m, r - 1, c) ) {
            return 1;
        }
    }
    if(canDown(m, r + 1, c) && !visited(m, r - 1, c)) {
        if( findPath(m, r - 1, c) ) {
            return 1;
        }
    }
    if(canLeft(m, r - 1, c - 1) && !visited(m, r - 1, c)) {
        if( findPath(m, r - 1, c) ) {
            return 1;
        }
    }
}

int main() {
    findPath(m,0,0); // m here is just a Matrix struct
    return 0;
}