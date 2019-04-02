//
//  graph.h
//  
//
//  Created by Gerhard Dueck on 2018-03-27.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>

typedef struct {
    int v;
    int w;
    int wt;
} Edge;

/* GRAPHinit and GRAPHinsertE return 1 if successful
 and return 0 if malloc fails */
int GRAPHinit(int);
int GRAPHinsertE(Edge);
void GRAPHdestroy();
int *SSSP(int);
void printGraph(void);


#endif /* graph_h */
