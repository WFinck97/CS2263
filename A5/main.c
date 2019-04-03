
#include <stdio.h>
#include<stdlib.h>
#include "graph.h"

int main(int argc, char * argv[]){
    FILE *fptr;
    FILE *fout;
    int n, m, n1 = 7, n2 = 4;
    Edge e;

    if(argc < 3){
    	printf("need to enter input and output file.\n");
    	return EXIT_FAILURE;
    }

    fptr = fopen(argv[1], "r");
	if (fptr == NULL){
		printf("fopen fail.\n");
		return EXIT_FAILURE;
	}

	fout = fopen(argv[2], "w");
	if (fout == NULL){
		fclose (fptr);
		return EXIT_FAILURE;
	}

	if(fscanf(fptr,"%d %d", &n, &m) != 2){
		printf("error reading values from file.\n");
	}

    if(!GRAPHinit(n)){
        printf("couldn't allocate memory for graph\n");
        return 1;
    }
    for(int k=0; k<m; k++){
        if(fscanf(fptr,"%d %d", &e.v, &e.w)!=2){
            printf("input invalid\n");
            return 1;
        }
        if(e.v > n-1 || e.w > n-1){
            printf("vertex index too large\n");
            return 1;
        }
        if(!GRAPHinsertE(e)){
            printf("couldn't insert edge\n");
            return 1;
        }
    }
    while(!feof(stdin)){
    	printf("Enter a pair of vertices (^D to quit): ");
    	if(scanf("%d %d", &n1, &n2) == 2){
			if(n1 > n-1 || n2 > n-1){
				printf("vertex index to large!\n");
			}
			else if(n1 < 0 || n2 < 0){
				printf("vertex must be 0 or greater!\n");
			}
			else if(GRAPHpath(n1,n2)){
	        	printf("\npath exists\n");
	    	}
	    	else if(GRAPHpath(n1, n2) == 0){
	    		printf("path does not exist\n");
	    	}
	    	resetVisited();
		}

		else{
			break;
		}
    }
   
    GRAPHprint(fout);
    GRAPHdestroy();
    return 0;
}
