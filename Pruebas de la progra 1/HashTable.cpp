#include "HashTable.h++"

template<class K, class V, class HashGenerator>
HashTable<K, V, HashGenerator>::HashTable() {
    for(int i = 0; i < size; i++) {
        vector<Bucket<K, V> > v;
        hashtable.push_back(v);
    }
}

template<class K, class V, class HashGenerator>
void HashTable<K, V, HashGenerator>::set(const K &key, const V &value) {
    Bucket<K, V> b(key, value);
    for(int i = 0; i < hashtable[hash(key)].size(); i++) {
        if (hashtable[hash(key)][i].key == key) {
            hashtable[hash(key)][i] = b;
            return;
        }
    }
    hashtable[hash(key)].push_back(b);
    list_of_keys.add(hash(key));
    list_of_keys.print();
}

template<class K, class V, class HashGenerator>
V HashTable<K, V, HashGenerator>::get(const K &key) {
    for(int i = 0; i < hashtable[hash(key)].size(); i++)
        if(hashtable[hash(key)][i].key == key)
            return hashtable[hash(key)][i].val;
}

template<class K, class V, class HashGenerator>
void HashTable<K, V, HashGenerator>::remove(const K &key) {
    if (!exist(key)){
        cout << "Can't remove hash_value: no match found.\n";
        return;
    }
    cout << "Removed  :  ";
    show(hash(key),0);
    hashtable.erase(hashtable.begin() + hash(key));
    list_of_keys.removeByName(hash(key));
}

template<class K, class V, class HashGenerator>
bool HashTable<K, V, HashGenerator>::exist(const K &key) {
    for (int i = 0; i < hashtable[hash(key)].size(); i++) {
        show(hash(key), i);
        if (hashtable[hash(key)][i].key == key)
            return true;
    }
    return false;
}

template<class K, class V, class HashGenerator>
size_t HashTable<K, V, HashGenerator>::hash(const K &key) {
    size_t val = HashGenerator::hashFunction(key) % hashtable.size();
    if (key<size) {
        cout << "Hashval" << val << endl;
        return val--;
    }
    cout << "Hashval" <<val << endl;
    return val;
}


template<class K, class V, class HashGenerator>
void HashTable<K, V, HashGenerator>::show(int hashKey,int bucketIndex){
    Bucket<K,V> bucket = hashtable[hashKey][bucketIndex];
    bucket.print();
}

template<class K, class V, class HashGenerator>
void HashTable<K, V, HashGenerator>::print(){
    cout << list_of_keys.size();
    list_of_keys.print();
    for (int i=0; i < list_of_keys.size(); ++i){
        show(list_of_keys.get(i),0);
    }

}








