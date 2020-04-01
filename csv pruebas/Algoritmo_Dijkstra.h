//
// Created by aldo on 25/2/20.
//

#ifndef DATOS_2___2_0_ALGORITMO_DIJKSTRA_H
#define DATOS_2___2_0_ALGORITMO_DIJKSTRA_H
#include <string>
#define INT_MAX
using namespace std;
class Algoritmo_Dijkstra {
    const int V=4;
    string rutas;
    int minDistance(int dist[], bool sptSet[]);
    Algoritmo_Dijkstra(int graph[4][4], int src);
    Algoritmo_Dijkstra();
    void printSolution(int dist[]);
};


#endif //DATOS_2___2_0_ALGORITMO_DIJKSTRA_H
