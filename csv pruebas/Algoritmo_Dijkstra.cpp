#include "Algoritmo_Dijkstra.h"

Algoritmo_Dijkstra::Algoritmo_Dijkstra(int graph[4][4],int src){
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX,
        sptSet[i] = false;
    }dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}
int Algoritmo_Dijkstra::minDistance(int *dist, bool *sptSet){
    // Initialize min value
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void Algoritmo_Dijkstra::printSolution(int *dist){
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}