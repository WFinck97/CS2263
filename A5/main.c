//
//  main.c
//  
//
//  Created by Gerhard Dueck on 2018-03-27.
//


/* Using Graph ADT to solve SSSP
 * Requires graph input in edge list
 */

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
	printf("the name of the output file is %s", argv[2]);

	if(fscanf(fptr,"%d %d", &n, &m) != 2){
		printf("error reading values from file.\n");
	}

	printf("n = %d and m = %d\n", n, m);

	printf("the name of the file is %s", argv[1]);
    //scanf("%d %d",&n, &m);
    
    if(!GRAPHinit(n)){
        printf("couldn't allocate memory for graph\n");
        return 1;
    }
    for(int k=0; k<m; k++){
        if(fscanf(fptr,"%d %d %d", &e.v, &e.w, &e.wt)!=3){
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

    if(GRAPHpath(n1,n2)){
        printf("there is a path from %d to %d\n", n1, n2);
    }
    printGraph();
    int s;
    scanf("%d",&s);
    if(s >= n || s < 0){
        printf("invalid source vertex\n");
        return 1;
    }
    int *D = SSSP(s);
    if(D == NULL){
        printf("SSSP malloc error\n");
        return 1;
    }
    for(int i=0;i<n;i++)
        printf("%d ",D[i]);
    printf("\n");
    GRAPHdestroy();
}
