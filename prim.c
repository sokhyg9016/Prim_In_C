#include "prim.h"

EDGE* read_graph(char *File, int* m, int* n)
{
	FILE* fp;
	EDGE* edges;
	int i;

	if ((fp = fopen(File, "r")) != NULL)
	{
		fscanf(fp, "%d %d", m, n);
		edges = (EDGE*)malloc(sizeof(EDGE)*(*m));

		i = 0;
		while (i < *m)
		{
			fscanf(fp, "%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

			i++;
		}
	}
	else
	{
		fprintf(stderr, "error\n");
		exit(1);
	}
	return edges;
}

int find_min_vertex(int node)
{
	int v, i;

	v = VERTICES - 1;
	D[v] = INF;
	visited[v] = TRUE;

	for (i = 0; i < node; i++)
	{
		if ((!visited[i]) && (D[i] < D[v]))
		{
			v = i;
		}
	}

	return v;
}

void primMST(int p, int node)
{
	int u, v;
	int i, count;

	int v_min, pre[VERTICES];

	////////////Setting//////////////
	D[p] = 0;

	for (u = 0; u < node; u++)
	{
		visited[u] = FALSE;
		D[u] = weightG[p][u];
		pre[u] = p;
	}

	visited[p] = TRUE;
	count = 1;
	//////////////////////////////


	while (count < node)
	{
		v_min = find_min_vertex(node);
		
		if (D[v_min] == INF)
		{
			fprintf(stderr, "error: check input file.\n");
			exit(1);
		}
		visited[v_min] = TRUE;

		for (i = 0; i < node; i++)
		{
			if (v_min == i)
				printf("[%4d] ", D[i]);
			else
				printf("%6d ", D[i]);
		}
		puts("");


		for (v = 0; v < node; v++)
		{
			if (weightG[v_min][v] == INF)
				continue;

			if (!visited[v] && (weightG[v_min][v] < D[v]))
			{
				D[v] = weightG[v_min][v];
				pre[v] = v_min;
			}
		}

		count++;
	}
	for (i = 0; i < node; i++)
	{
		printf("%3c %3c  %3d\n", 'a' + pre[i], 'a' + i, weightG[i][pre[i]]);
	}
}