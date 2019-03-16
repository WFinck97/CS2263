#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gridInit(int *grid, int row, int col);
void printGrid(int *grid, int row, int col);
int countBlob(int row, int col);

int main(){
	int row, col;
	int *grid;

	scanf("%d %d", &row, &col);

	grid = (int *)malloc(sizeof(int)*row*col);
	gridInit(grid, row, col);
	printGrid(grid, row, col);
	free(grid);

	return 0;
}

void gridInit(int *grid, int row, int col){
	int i;
	srand(time(NULL));

	for(i = 0; i < row * col; i++){
		*(grid + i) = rand()%2;
	}
}

void printGrid(int *grid, int row, int col){
	int r, c;

	for(r = 0; r < row; r ++){
		for(c = 0; c < col; c++){
			printf("%d ", grid[r*col + c]);
		}

		printf("\n");
	}
}

int countBlob(int r, int c, int row, int col){
	if(grid[r*col + c] == 0){
		return 0;
	}
	else{
		
	}
}