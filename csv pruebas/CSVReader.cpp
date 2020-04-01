#include "CSVReader.h"
CSVReader::CSVReader(string filename) {
    this->fileName=filename;
}
void CSVReader::sacarDatos(){
    ifstream file(fileName);
    string line = "";
    int i=0;
    while(getline(file, line,'\n')) {
        if (i == 1){
            int num=stoi (line);
            grafo->setDatos(num);
        } else if (i>1) {
            int y=0;
            int *vect;
            vect= static_cast<int *>(malloc(sizeof(int) * 3));
            stringstream ss(line);
            while(ss.good()){
                string substr;
                getline( ss, substr, ',' );
                int num=stoi (substr);
                vect[y]=num;
                y++;
            }grafo->addEdge(vect[0],vect[1],vect[2]);
            free(vect);
        }i++;
    }file.close();
}
