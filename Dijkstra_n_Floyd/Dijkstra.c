#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VTX 6
int graph[MAX_VTX][MAX_VTX] = {
    {0, 50, 45, 10, 0, 0},
    {0, 0, 10, 15, 0, 0},
    {0, 0, 0, 0, 30, 0},
    {10, 0, 0, 0, 15, 0},
    {0, 20, 35, 0, 0, 0},
    {0, 0, 0, 0, 3, 0}
};


/**
 * Gets all the unvisited adjacent vertices of vtx from graph
 * returns -1 when no adjacent vertices are found
 * returns the no. of adjacent vertices when found
*/
int get_unvisited_adjacent_vertex(int vtx, int *visited, int **arr);
int get_nearest_unvisited_vertex(int *cost, int *visited);

void main() {
    int i, start;
    int visited[MAX_VTX], cost[MAX_VTX];

    for (i = 0; i < MAX_VTX; i++)
        visited[i] = 0;
    for (i = 0; i < MAX_VTX; i++)
        cost[i] = INT_MAX;
    
    printf("Enter the start vertex: ");
    scanf("%d", &start);

    cost[start] = 0;

    int *arr = (int *)malloc(sizeof(int)*MAX_VTX);
    
    while (1) {
        int n = get_nearest_unvisited_vertex(cost, visited);
        if (n == -1) break;
        visited[n] = 1;

        int num_of_adj_vertices = get_unvisited_adjacent_vertex(n, visited, &arr);
        if (num_of_adj_vertices == -1) {
            continue;
        }

        for (i = 0; i < num_of_adj_vertices; i++) {
            if (cost[arr[i]] > cost[n] + graph[n][arr[i]])
                cost[arr[i]] = cost[n] + graph[n][arr[i]];
        }
    }

    for (i = 0; i < MAX_VTX; i++)
        printf("%d\n", cost[i]);
}

int get_nearest_unvisited_vertex(int *cost, int *visited) {
    int i, min = INT_MAX, min_vtx = 0, flag = 0;
    if (visited[min_vtx] == 0)
        return min_vtx;

    for (i = 0; i < MAX_VTX; i++) {
        if (cost[i] != 0) {
            min_vtx = i;
            break;
        }
    }
    for (i = 0; i < MAX_VTX; i++) {
        if (cost[i] < cost[min_vtx] && visited[i] != 1) {
            flag = 1;
            min     = cost[i];
            min_vtx = i;
        }
    }

    if (flag == 0) return -1;       // no unvisited vertex found with minimum cost
    else return min_vtx;
}

int get_unvisited_adjacent_vertex(int vtx, int *visited, int **arr) {
    int i, j, flag = 0;

    for (i = 0, j = 0; i < MAX_VTX; i++) {
        if (graph[vtx][i] != 0 && visited[i] != 1) {
            flag = 1;
            (*arr)[j++] = i;
        }
    }

    if (flag == 1) return j;    // j adj vertices are found
    else return -1;             // no adj vertices are found
}