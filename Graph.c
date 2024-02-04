#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Graph{
    int vertices;
    struct Node** list;
};

struct Node* createNode(int data){
   struct Node* p = (struct Node*)malloc(sizeof(struct Node));
   p->data = data;
   p->next = NULL;
   return p;
}
struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->list = (struct Node*)malloc(vertices *sizeof(struct Node));

    for (int i = 0; i < vertices; ++i)
    {
        graph->list[i] = NULL;
    }
    return graph;

}
void addEdge(struct Graph* graph, int source, int destination){
    struct Node* q = createNode(destination);
    q -> next = graph->list[source];
    graph -> list[source] = q;
    q = createNode(source);
    q -> next = graph -> list[destination];
    graph -> list[destination] = q;
}
void displayGraph(struct Graph* graph){
    for (int i = 0; i < graph->vertices; ++i)
    {
        printf("Vertex %d", i);
        struct Node* current = graph->list[i];
        while (current != NULL)
        {
            printf(" -> %d", current->data);
            current = current -> next;
        }
        printf("\n");

    }
}
int main(){
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);
    displayGraph(graph);
    return 0;


}