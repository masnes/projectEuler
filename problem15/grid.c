#include <stdio.h>
#include <time.h>
#define end -1
#define down 1
#define right 2
#define both 3
#define gridSize 20
// for some reason the size needs to be the actual size of the grid (not one smaller than the grid)
long long int pathNum = 0;
int grid[gridSize+2][gridSize + 1];
int x = 0;

long int gridCount(int i, int j) {
    //test to make sure only one if statement is used
    if (grid[i][j] == both) {
        gridCount(i, j+1);
        gridCount(i+1, j);
    }
    else if (grid[i][j] == right) {
        gridCount(i, j+1);
    }
    else if (grid[i][j] == down) {
        gridCount(i+1, j);
    }
    else if (grid[i][j] == end) {
        pathNum += 1;
    }
    else {
        printf("Control should never reach here!\ni = %d, j = %d, grid[i][j] = %d\npathNum = %lld", i, j, grid[i][j], pathNum);
    }
}

int main() {
    clock_t t;
    t = clock();
    int a = 0;
    // set whole grid to allow travel in both directions
    for (int i = 0; i <= gridSize; i++)
    {
        for (int j = 0; j <= gridSize; j++)
        {
            if (j == gridSize) {
                grid[i][j] = down;
            }
            else if (i == gridSize) {
                grid[i][j] = right;
            }
            else {
                grid[i][j] = both;
            }
        }
    }
    grid[gridSize][gridSize] = end;

    /*for (int i = 0; i <= gridSize; i++) {
        for (int j = 0; j <= gridSize; j++) {
            printf("%d ", grid[i][j]);
            if (grid[i][j] == 1)
                printf("\n");
        }
    }*/
    //gridCount from start of grid
    gridCount(0,0);
    printf("\nThere are %lld paths through a %d by %d grid.\n", pathNum, gridSize, gridSize); t = clock() - t;
    printf("This program took %ld clicks (%f seconds).\n", t, ((float)t)/CLOCKS_PER_SEC);
}

