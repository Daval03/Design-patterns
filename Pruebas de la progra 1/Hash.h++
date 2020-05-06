#ifndef DATOS_2___2_0_HASH_H
#define DATOS_2___2_0_HASH_H

#include <iostream>
#include <vector>
using namespace std;


template<class K, class V>
struct Bucket {
    K key;
    V val;
    Bucket(const K &k, const V &v) : val(v), key(k) {}
};


template<class T> struct Hash {
};


template<> struct Hash<string> {
    static size_t hashFunction(const string& s) {
        return hash<string>()(s);
    }
};


template<> struct Hash<int> {
    static size_t hashFunction(const int m) {
        return hash<int>()(m);
    }
};


template<> struct Hash<char> {
    static size_t hashFunction(const char m) {
        return hash<char>()(m);
    }
};



#endif //DATOS_2___2_0_HASH_H