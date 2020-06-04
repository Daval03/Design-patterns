#include <zconf.h>
#include "P1/VSPointer.h"
#include "P1/LinkedList.h"

auto gbCollector = GBCollector::getInstance();

void hashTest(){

    VSPointer<int> vs0 = VSPointer<int>::New();
    *vs0 = 0;
    VSPointer<int> vs1 = VSPointer<int>::New();
    *vs1 = 1;
    VSPointer<int> vs2 = VSPointer<int>::New();
    *vs2 =2;
    VSPointer<int> vs3 =  VSPointer<int>::New();
    *vs3 = 3;
    VSPointer<int> vs4 =  VSPointer<int>::New();
    *vs4 = 4;
    vs1=vs0;
    vs2=vs1;
    sleep(5);
    vs0=vs3;
    vs4=vs3;
    sleep(5);

    //print element
    gbCollector->setMap->print();
    gbCollector->print();


}


int main() {
    //tests with hash
    hashTest();
}


