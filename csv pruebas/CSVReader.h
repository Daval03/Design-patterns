//
// Created by aldo on 4/9/19.
//

#ifndef DATOS_2_CSVREADER_H
#define DATOS_2_CSVREADER_H
#include <iostream>
#include <fstream>
#include "Graph.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class CSVReader {
private:
    string fileName;
    int vertices;
public:
    Graph *grafo=new Graph;
    void sacarDatos();
    CSVReader(string filename);
};
#endif //DATOS_2_CSVREADER_H
