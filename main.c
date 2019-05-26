#include "prim.h"

int main(int argc, char* argv[])
{
	int n_edge, n_vertex;
	int i, j;
	int u, v;
	
	EDGE* graph;
	
	graph = read_graph(argv[1], &n_edge, &n_vertex);

	for (i = 0; i < n_vertex; i++)
	{
		for (j = 0; j < n_vertex; j++)
		{
			weightG[i][j] = ((i == j) ? 0 : INF);
		}
	}

	for (i = 0; i < n_edge; i++)
	{
		u = graph[i].u;
		v = graph[i].v;

		weightG[u][v] = weightG[v][u] = graph[i].w;
	}

	for (j = 0; j < n_vertex; j++)
	{
		printf("[%4c] ", 'a' + j);
	}
	printf("\n");

	//primMST()함수 호출
	primMST(2, n_vertex);

	return 0;
}