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

int linearSearch(int* arr, int size, int key) {
	int i = 0;
	for (i = 0; i < size; i++) {
		if (arr[i] == key)
			return 1;
	}
	return 0;
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

	/*for (i = 0; i < n; i++) {
		Vertex *head = vertices[i];
		Vertex *ptr = head;
		while (ptr != NULL) {
			printf("%d -> ", ptr->value);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}*/


	int queue[100], front = -1, rear = -1, d, visited[100], k = 0;
	queue[++rear] = 0;
	front++;
	rear = front + 1;

	while (front != rear) {
		// dequeue
		d = queue[front];
		front++;
		visited[k++] = d;

		Vertex *ptr = vertices[d];
		while (ptr != NULL) {
			// 2 checks
			// 1. already visited or not
			int isVisited = linearSearch(visited, k + 1, ptr->value);
			int isInQueue = 0;
			
			if (isVisited == 0) {
				// 2. Already in the queue or not
				for (i = front; i < rear; i++) {
					if (queue[i] == ptr->value) {
						isInQueue = 1;
						break;
					}
				}
			}

			if (isVisited == 0 && isInQueue == 0) {
				queue[rear++] = ptr->value;
			}
			ptr = ptr->next;
		}

		printf("%d ", d);
	}
}