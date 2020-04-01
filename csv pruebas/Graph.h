//
// Created by aldo on 26/2/20.
//

#ifndef DATOS_2___2_0_GRAPH_H
#define DATOS_2___2_0_GRAPH_H
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

class Graph {
private:
    int V;
    list<pair<int,int>>*adj;
public:
    string respuesta;
    void setDatos(int v);
    Graph();
    Graph(int V);
    void addEdge(int u,int v,int w);
    string Dijkstra(int s);
};


#endif //DATOS_2___2_0_GRAPH_H
