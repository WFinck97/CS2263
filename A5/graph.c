//
//  graph.c
//  
//
//  Created by Gerhard Dueck on 2018-03-27.
//

#include <stdlib.h>
#include <limits.h>
#include "graph.h"

typedef struct graphnode{
    int v;
    int wt;
    struct graphnode *next;
} Node;

typedef struct graph{
    int V;
    int E;
    int *visited; //array of int to keep track of visited nodes
    Node **adj;  //array of ptrs to linked lists
}Graph;

Graph *G;

void printGraph(void){
    printf("node 0 points to node: %d\n", G->adj[0]->v);
    printf("node 0 also points to node: %d\n", G->adj[0]->next->v);
}
int GRAPHinit(int V){
    G = malloc(sizeof(Graph));
    if(G == NULL)
        return 0;
    G->V = V;
    G->E = 0;
    G->visited = calloc(V,sizeof(int));
    G->adj = calloc(V, sizeof(Node *));
    if(G->adj == NULL){
        free(G);
        return 0;
    }
    return 1;
}

static Node *constructEdge(int v, int wt, Node *next){
    Node *p = malloc(sizeof(Node));
    if(p == NULL)
        return NULL;
    p->v = v;
    p->wt = wt;
    p->next = next;
    return p;
}
void GRAPHpathHelper(int v, int *visited){
    visited[v] = 1;
}
int GRAPHpath(int v, int w){
    // returns 1 if simple path between v and w exists, 0 otherwise
    // using theabove algorithm. Also prints edges along path, if it exists.
    // Hint: you’ll want to use a separate recursive helper function, 
    // to include the array ofvisited vertices as a parameter.
    if(v == w){
    	return 1;
    }
    // mark v as visited
    GRAPHpathHelper(v,G->visited);
    // for all edges v-x
    Node *nextNode;
    nextNode = G->adj[v];
    while(nextNode != NULL){
        if(G->visited[nextNode->v] == 0){
            if(GRAPHpath(nextNode->v,w) == 1){
                printf("%d-%d\n", nextNode->v,v);
                return 1;
            }
        }
        nextNode = nextNode->next;
    }
    return 0;
}

void GRAPHprint(FILE *f){
    // Prints graph, with each adjacency list printed on one line, to filehandle f.
    Node *nextNode;
    for(int i = 0; i < G->V; i++){
    	fprintf(f, "%d: ", i);
    	nextNode = G->adj[i];
    	while(nextNode != NULL){
    		fprintf(f, "%d ", nextNode->v);
    		nextNode = nextNode->next;
    	}
    	fprintf(f,"\n");
    }
    
    fclose(f);
}

int GRAPHinsertE(Edge e){
    int v = e.v;
    G->adj[v] =
    constructEdge(e.w, e.wt, G->adj[v]);
    if(G->adj[v] == NULL)
        return 0;
    G->E++;
    return 1;
}

void GRAPHdestroy(){
    for(int v=0; v < G->V; v++){
        Node *t = G->adj[v];
        while(t != NULL){
            Node *temp = t;
            t = t->next;
            free(temp);
        }
    }
    free(G->adj);
    free(G->visited);
    free(G);
}

int *SSSP(int s){
    int n = G->V;
    int *queue;//circular buffer to hold FIFO queue
    int *inQueue;//sparse representation of queue
    int front = 0; //index of front of queue
    int size = 1; //size of list (has source vertex initially)
    int *D;//distance to each vertex
    if((queue = malloc(n*sizeof(int))) == NULL) return NULL;
    if((inQueue = malloc(n*sizeof(int))) == NULL) return NULL;
    if((D = malloc(n*sizeof(int))) == NULL) return NULL;
    for(int i=0; i <n; i++){
        D[i] = INT_MAX;
        inQueue[i] = 0;
    }
    D[s] = 0, queue[0] = s, inQueue[s] = 1;
    while(size > 0){
        int i = queue[front];
        front = (front+1)%n, size--;
        inQueue[i] = 0;
        for(Node *t = G->adj[i]; t!= NULL; t = t->next){
            int j = t->v;
            int wt = t->wt;
            if(D[j] > D[i]+wt){
                D[j] = D[i] + wt;
                if(!inQueue[j]){
                    queue[(front+size)%n] = j;
                    size++;
                    inQueue[j] = 1;
                }
            }
        }
    }
    return D;
}
