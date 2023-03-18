/**
 * Topic for today's class was -
 * 	1. What are the 3 types of graph representation in our machine
 *	2. How to represent undirected unweighted, directed unweighted, undirected weighted
 *	   and directed weighted graph using adjacency matrix
 */

#include<stdio.h>

void main() {
	int vertices, i, j, k, edges, degree, weight;

	printf("How many vertices? ");
	scanf("%d", &vertices);

	int graph[vertices][vertices];
	for (i = 0; i < vertices; i++)
		for (j = 0; j < vertices; j++)
			graph[i][j] = 0;

	for (i = 0; i < vertices; i++) {
		printf("How many edges from vertex %d? ", i);
		scanf("%d", &edges);
		for (j = 0; j < edges; j++) {
			printf("Enter the vertex ");
			scanf("%d", &k);
			printf("What is the weight of the edge? ");
			scanf("%d", &weight);
			graph[i][k] = weight;
		}
	}

	printf("The adjacency matrix is: \n");
	for (i = 0; i < vertices; i++) {
		for (j = 0; j < vertices; j++)
			printf("%d ", graph[i][j]);
		printf("\n");
	}

	for (i = 0; i < vertices; i++) {
		degree = 0;
		for (j = 0; j < vertices; j++) {
			if (graph[i][j] != 0)
				degree++;
		}
		printf("Degree of vertex %d is %d\n", i, degree);
	}
}