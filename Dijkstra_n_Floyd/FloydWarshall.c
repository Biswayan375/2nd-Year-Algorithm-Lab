/**
 * Implementation of Floyd Warshall Algorithm - all pair shortest path finding
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>		// for infinity INT_MAX

#define MAX_VTX 4

int graph[MAX_VTX][MAX_VTX] = {
	{ 0, 3, 0, 7 },
	{ 8, 0, 2, 0 },
	{ 5, 0, 0, 1 },
	{ 2, 0, 0, 0 }
};

int main() {
	int i, j, k;
	int dist_k_1[MAX_VTX][MAX_VTX];
	
	// filling up the distance matrix with initial values i.e.: A0
	for (i = 0; i < MAX_VTX; i++) {
		for (j = 0; j < MAX_VTX; j++) {
			if (i == j) {
				dist_k_1[i][j] = 0;
			} else {
				if (graph[i][j] == 0)
					dist_k_1[i][j] = INT_MAX;
				else
					dist_k_1[i][j] = graph[i][j];
			}
		}
	}
	
	// printf("initial values of distance matrix\n");
	// for (i = 0; i < MAX_VTX; i++) {
	// 	for (j = 0; j < MAX_VTX; j++) {
	// 		if (dist_k_1[i][j] != INT_MAX)
	// 			printf("%d\t\t", dist_k_1[i][j]);
	// 		else
	// 			printf("Infinity\t\t");
	// 	}
	// 	printf("\n");
	// }
	// printf("------------------------------------------------\n");
	
	// calculating all the distance matrices
	for (k = 1; k <= MAX_VTX; k++) {
		for (i = 0; i < MAX_VTX; i++) {
			for (j = 0; j < MAX_VTX; j++) {
				if (dist_k_1[i][k-1] != INT_MAX && dist_k_1[k-1][j] != INT_MAX) {
					if (i != j && i != k-1 && j != k-1) {
						if (dist_k_1[i][j] > dist_k_1[i][k-1]+dist_k_1[k-1][j])
							dist_k_1[i][j] = dist_k_1[i][k-1]+dist_k_1[k-1][j];
					}
				}
			}
		}
		// printf("Distances when traveling via %d\n", k-1);
		// for (i = 0; i < MAX_VTX; i++) {
		// 	for (j = 0; j < MAX_VTX; j++) {
		// 		if (dist_k_1[i][j] != INT_MAX)
		// 			printf("%d\t\t", dist_k_1[i][j]);
		// 		else
		// 			printf("Infinity\t\t");
		// 	}
		// 	printf("\n");
		// }
	}

	for (i = 0; i < MAX_VTX; i++) {
		for (j = 0; j < MAX_VTX; j++)
			printf("%d\t", dist_k_1[i][j]);
		printf("\n");
	}
}
