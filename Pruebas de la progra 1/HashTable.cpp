#include "HashTable.h++"

template<class K, class V, class HashGenerator>
HashTable<K, V, HashGenerator>::HashTable() {
    for(int i = 0; i < this->size; i++) {
        vector<Bucket<K, V> > v;
        hashtable.push_back(v);
    }
}


template<class K, class V, class HashGenerator>
void HashTable<K, V, HashGenerator>::set(const K &key, const V &value) {
    Bucket<K, V> b(key, value);
    for(int i = 0; i < hashtable[hash(key)].size(); i++)
        if(hashtable[hash(key)][i].key == key) {
            hashtable[hash(key)][i] = b;
            return;
        }
    hashtable[hash(key)].push_back(b);
}

template<class K, class V, class HashGenerator>
V HashTable<K, V, HashGenerator>::get(const K &key) {
    for(int i = 0; i < hashtable[hash(key)].size(); i++)
        if(hashtable[hash(key)][i].key == key)
            return hashtable[hash(key)][i].val;
}

template<class K, class V, class HashGenerator>
bool HashTable<K, V, HashGenerator>::exist(const K &key) {
    for(int i = 0; i < hashtable[hash(key)].size(); i++)
        if(hashtable[hash(key)][i].key == key)
            return true;
    return false;
}

template<class K, class V, class HashGenerator>
size_t HashTable<K, V, HashGenerator>::hash(const K &key) {
    return HashGenerator::hashFunction(key) % hashtable.size();
}

