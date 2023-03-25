#include<stdio.h>
#include<stdlib.h>

struct Vertex {
	int value;
	struct Vertex *next;
};
typedef struct Vertex Vertex;

Vertex *create_vertex(int value) {
	Vertex *new_vertex = (Vertex*)malloc(sizeof(Vertex));
	new_vertex->value = value;
	new_vertex->next = NULL;

	return new_vertex;
}

void main() {
	int n, i, j, adj, v;
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
			Vertex *new = create_vertex(v);
			Vertex *head = vertices[i];
			Vertex *ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = new;
		}
	}

	for (i = 0; i < n; i++) {
		Vertex *head = vertices[i];
		Vertex *ptr = head;
		while (ptr != NULL) {
			printf("%d -> ", ptr->value);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}
}