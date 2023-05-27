#include <stdio.h>
#include <stdlib.h>

struct Edge {
	int source_vertex;
	int destination_vertex;
	int weight;
	int is_taken; // 0 -> not taken yet, 1 -> taken already, 2 -> rejected because creating cycle
};
typedef struct Edge Edge;

struct Vertex {
	int value;
	int weight;
	struct Vertex *next;
};
typedef struct Vertex Vertex;

Vertex *create_vertex(int value) {
	Vertex *new_vertex = (Vertex*)malloc(sizeof(Vertex));
	new_vertex->value = value;
	new_vertex->weight = 0;
	new_vertex->next = NULL;

	return new_vertex;
}

void kruskals(Vertex** graph, int vertices);
int get_minimum_edge(Edge *edges, int no_of_edges);
void add_to_path(int *path, int u, int v, int vertices);
int find_path(int *path, int u, int v);

void main() {
	int n, i, j, adj, v, w;
	Vertex **vertices;
	printf("How many vertices are there?\n");
	scanf("%d", &n);
	vertices = malloc(n * sizeof(Vertex*));

	for (i = 0; i < n; i++) {
		vertices[i] = create_vertex(i);
	}

	for (i = 0; i < n; i++) {
		printf("How many adjacent vertices are there for vertex %d\n", i);
		scanf("%d", &adj);
		for (j = 0; j < adj; j++) {
			printf("Enter the vertex: ");
			scanf("%d", &v);
			printf("What is the weight of the edge: ");
			scanf("%d", &w);
			Vertex *new = create_vertex(v);
			new->weight = w;
			Vertex *head = vertices[i];
			Vertex *ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = new;
		}
	}

	kruskals(vertices, n);
	
}


void kruskals(Vertex** graph, int vertices) {
	int i, j, k, m, *path, no_of_edges = 0;
	Edge *edges = (Edge *)malloc(sizeof(Edge)*(vertices*vertices));
	path = (int *)malloc(sizeof(int)*vertices);
	/*for (i = 0; i < n; i++) {
		Vertex *head = vertices[i];
		Vertex *ptr = head;
		while (ptr != NULL) {
			printf("[v: %d, w: %d ] -> ", ptr->value, ptr->weight);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}*/

	for (i = 0; i < vertices; i++)
		path[i] = i;

	for (i = 0, k = 0; i < vertices; i++) {
		Vertex *head = graph[i];
		Vertex *ptr = head;
		ptr = ptr->next;


		while (ptr != NULL) {
			int flag = 0;
			for (m = 0; m < no_of_edges; m++) {
				Edge e = edges[m];
				if (e.source_vertex == ptr->value && e.destination_vertex == head->value) {
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				Edge new_edge;
				new_edge.source_vertex = head->value;
				new_edge.destination_vertex = ptr->value;
				new_edge.weight = ptr->weight;
				new_edge.is_taken = 0;
				edges[k++] = new_edge;
				no_of_edges++;
			}

			ptr = ptr->next;
		}
	}

	// for (i = 0; i < no_of_edges; i++)
	// 	printf("[src: %d, dst: %d, weight: %d]\n", edges[i].source_vertex, edges[i].destination_vertex, edges[i].weight);



	for (i = 0; i < vertices - 1;) {
		int min_edge_index = get_minimum_edge(edges, no_of_edges);

		// checking for cycle ----------------------------------
		if (find_path(path, edges[min_edge_index].source_vertex, edges[min_edge_index].destination_vertex) == 0) {
			add_to_path(path, edges[min_edge_index].source_vertex, edges[min_edge_index].destination_vertex, vertices);
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

int find_path(int *path, int u, int v){
    if (path[u] == path[v]) return 1;
    else return 0;
}

void add_to_path(int *path, int u, int v, int vertices) {
	int uid = path[u], i;
	for (i = 0; i < vertices; i++) {
		if (path[i] == uid)
			path[i] = path[v];
	}
}