#include <stdio.h>
#include <stdlib.h>

int vertices = 5;
int graph[5][5] = {
		{ -1, 2, 5, -1, -1 },
		{ 2, -1, 2, 4, -1 },
		{ 5, 2, -1, 5, 5 },
		{ -1, 4, 5, -1, 2 },
		{ -1, -1, 5, 2, -1 }
	};

void prims();

void main() {
	prims();
}


void prims() {
	int visited[vertices];
	int i, j, k;
	int edges = 0;
	int min, a, b;

	for (i = 0; i < vertices; i++) {
		visited[i] = 0;
	}
	visited[0] = 1;

	while (edges < vertices - 1) {

		min = 9999;
		for (i = 0; i < vertices; i++) {
			for (j = 0; j < vertices; j++) {
				if (visited[i] == 1 && visited[j] == 0) {
					if (graph[i][j] != -1 && graph[i][j] < min) {
						min = graph[i][j];
						a = i;
						b = j;
					}
				} else if (visited[j] == 1 && visited[i] == 0) {
					if (graph[i][j] != -1 && graph[i][j] < min) {
						min = graph[i][j];
						a = i;
						b = j;
					}
				}
			}
		}

		edges++;
		visited[a] = 1;
		visited[b] = 1;
		printf("%d -> %d\n", a, b);

	}
}