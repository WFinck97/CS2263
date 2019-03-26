#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void gridInit(int *grid, int row, int col);
void printGrid(int *grid, int row, int col);
int countBlob(int r, int c, int row, int col, int *grid);
void unMark(int *grid, int size);
int countOnes(int *grid, int row, int col);

int main(){
	int row, col, i, j, check = 1;
	int *grid, blobSize, invalidIn = 0;
	char coords[20], *str_i, *str_j;

	scanf("%d %d", &row, &col);

	grid = (int *)malloc(sizeof(int)*row*col);
	gridInit(grid, row, col);
	printGrid(grid, row, col);

	while(check){
		printf("enter coordinate i,j (non-numeric to quit): ");
		scanf("%s", coords);
		invalidIn = 0;
		str_i = strtok(coords, ",");
		if(str_i == NULL){
			break;
		}
		str_j = strtok(NULL, ",");
		if(str_j == NULL){
			break;
		}
		i = atoi(str_i);
		if(i == 0 && str_i[0] != '0'){
			break;
		}
		j = atoi(str_j);
		if(j == 0 && str_j[0] != '0'){
			break;
		}
		if(i >= row || i < 0){
			invalidIn = 1;
		}
		if(j >= col || j < 0){
			invalidIn = 1;
		}
		if(invalidIn == 0){
			blobSize = countBlob(i,j,row,col,grid);
			unMark(grid,row*col);
			printf("Blob size: %d (%.1f %% of all 1's)\n", blobSize, (float)100*blobSize/countOnes(grid, row, col));
		}
		else{
			printf("invalid coordinate\n");
		}
	}
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

int countBlob(int r, int c, int row, int col, int *grid){
	if(r < 0 || r >= row){
		return 0;
	}
	if(c < 0 || c >= col){
		return 0;
	}
	if(grid[r*col + c] == 0){
		return 0;
	}
	if(grid[r*col + c] == 1){
		grid[r*col + c] = 2;
		return(1 + countBlob(r - 1, c, row, col, grid) 
			+ countBlob(r - 1, c - 1, row, col, grid) + countBlob(r - 1, c + 1, row, col, grid) 
			+ countBlob(r, c - 1, row, col, grid) + countBlob(r, c + 1, row, col, grid) 
			+ countBlob(r + 1, c - 1, row, col, grid) + countBlob(r + 1, c, row, col, grid) 
			+ countBlob(r + 1, c + 1, row, col, grid));
	}
	else{
		return 0;
	}
}

void unMark(int *grid, int size){
	int i = 0;
	for(i = 0; i < size; i++){
		if(grid[i] == 2){
			grid[i] = 1;
		}
	}
}

int countOnes(int *grid, int row, int col){
	int i, numOnes = 0;
	for(i = 0; i < row*col; i++){
		if(grid[i] == 1){
			numOnes++;
		}
	}
	return numOnes;
}