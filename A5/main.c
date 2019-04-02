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
#include "graph.h"

int main(){
    int n, m;
    Edge e;
    scanf("%d %d",&n, &m);
    if(!GRAPHinit(n)){
        printf("couldn't allocate memory for graph\n");
        return 1;
    }
    for(int k=0; k<m; k++){
        if(scanf("%d %d %d", &e.v, &e.w, &e.wt)!=3){
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
