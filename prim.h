#pragma warning(disable: 4996)
#pragma once

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

#define VERTICES 1000
#define INF 100000L

int weightG[VERTICES][VERTICES];
int visited[VERTICES];
int D[VERTICES];

typedef struct edge
{
	int u, v;
	int w;
}EDGE;

EDGE* read_graph(char *File, int* m, int* n);

int find_min_vertex(int node);
void primMST(int p, int node);





