#ifndef DATOS_2___2_0_HASHTABLE_H
#define DATOS_2___2_0_HASHTABLE_H

#include "Hash.h++"
#include "LinkedList.h"

using namespace std;

template<class K, class V, class HashGenerator = Hash<K> >
class HashTable {
public:

    HashTable(); //constructor
    ~HashTable() = default; //destructor

    //methods
    bool exist(const K &key);
    void set(const K &key, const V &value);
    void remove(const K &key);
    V get(const K &key);
    void print();

private:
    static const int size = 5; //size
    vector<vector<Bucket<K, V> > > hashtable; //hashtable.
    LinkedList <size_t> list_of_keys; //keys
    size_t hash(const K &key);
    void show(int hashKey,int bucketIndex);
    unsigned long operator()(const K& key);
};

#endif //DATOS_2___2_0_HASHTABLE_H