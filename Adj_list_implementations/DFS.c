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


int main() {
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


    int stack[100], top = -1, visited[100];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    
    stack[++top] = 0;
    visited[0] = 1;
    printf("%d\n", stack[top]);

    // dfs loop
    while (top != -1) {
        int u = stack[top];

        Vertex *ptr = vertices[u]->next;
        int flag = 0;
		while (ptr != NULL) {
            int isVisited = 0, isInStack = 0;
            // checking if already visited
            if (visited[ptr->value] == 1)
                isVisited = 1;

            if (isVisited == 0 && isInStack == 0) {
                flag = 1;
                printf("%d\n", ptr->value);
                visited[ptr->value] = 1;
                stack[++top] = ptr->value;
                break;
            }
            ptr = ptr->next;
        }

        if (flag == 0)
            top--;
    }
}