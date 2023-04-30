#include <stdio.h>
#include <stdlib.h>

struct Edge {
	int source_vertex;
	int destination_vertex;
	int weight;
	int is_taken; // 0 -> not taken yet, 1 -> taken already, 2 -> rejected because creating cycle
};
typedef struct Edge Edge;


int vertices = 5;
int *path;
int graph[5][5] = {
		{ -1, 2, 1, -1, -1 },
		{ 2, -1, 2, 4, -1 },
		{ 1, 2, -1, 5, 5 },
		{ -1, 4, 5, -1, 2 },
		{ -1, -1, 5, 2, -1 }
};


void kruskals();
int get_minimum_edge(Edge *edges, int no_of_edges);
void add_to_path(int u, int v);
int find_path(int u, int v);


void main() {
	kruskals();
}


void kruskals() {
	int i, j, k, m, no_of_edges = 0;
	Edge *edges = (Edge *)malloc(sizeof(Edge)*(vertices*vertices));
	path = (int *)malloc(sizeof(int)*vertices);

	for (i = 0; i < vertices; i++)
		path[i] = i;

	for (i = 0, k = 0; i < vertices; i++) {
		for (j = 0; j < vertices; j++) {
			// checking if an edge exists
			if (graph[i][j] != -1) {
				// checking for duplicate edge
				int flag = 0;
				for (m = 0; m < no_of_edges; m++) {
					Edge e = edges[m];
					if (e.source_vertex == j && e.destination_vertex == i) {
						flag = 1;
						break;
					}
				}

				// inserting if no duplicate edge is found
				if (flag == 0) {
					Edge new_edge;
					new_edge.source_vertex = i;
					new_edge.destination_vertex = j;
					new_edge.weight = graph[i][j];
					new_edge.is_taken = 0;
					edges[k++] = new_edge;
					no_of_edges++;
				}
				
			}
		}
	}

	for (i = 0; i < vertices - 1;) {
		int min_edge_index = get_minimum_edge(edges, no_of_edges);

		// checking for cycle ----------------------------------
		if (find_path(edges[min_edge_index].source_vertex, edges[min_edge_index].destination_vertex) == 0) {
			add_to_path(edges[min_edge_index].source_vertex, edges[min_edge_index].destination_vertex);
			edges[min_edge_index].is_taken = 1;
			i++;
		} else {
			edges[min_edge_index].is_taken = 2;
		}
		// -----------------------------------------------------
	}

	for (i = 0; i < no_of_edges; i++) {
		Edge e = edges[i];
		if (e.is_taken == 1) {
			printf("source: %d, dest: %d, weight: %d\n", e.source_vertex, e.destination_vertex, e.weight);
		}
	}
}

int get_minimum_edge(Edge *edges, int no_of_edges) {
	int i, min = 9999;
	int min_edge_index;
	for (i = 0; i < no_of_edges; i++) {
		if (edges[i].weight < min && edges[i].is_taken == 0) {
			min = edges[i].weight;
			min_edge_index = i;
		}
	}

	return min_edge_index;
}

int find_path(int u, int v){
    if (path[u] == path[v]) return 1;
    else return 0;
}

void add_to_path(int u, int v) {
	int uid = path[u], i;
	for (i = 0; i < vertices; i++) {
		if (path[i] == uid)
			path[i] = path[v];
	}
}