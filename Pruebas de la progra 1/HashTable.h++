#ifndef DATOS_2___2_0_HASHTABLE_H
#define DATOS_2___2_0_HASHTABLE_H

#include "Hash.h++"

using namespace std;

template<class K, class V, class HashGenerator = Hash<K> >
class HashTable {
public:

    HashTable(); //constructor
    ~HashTable() = default; //destructor

    //methods
    bool exist(const K &key);
    void set(const K &key, const V &value);
    V get(const K &key);

private:
    static const int size = 10; //size
    vector<vector<Bucket<K, V> > > hashtable; //hashtable.
    size_t hash(const K &key);
};

#endif //DATOS_2___2_0_HASHTABLE_H