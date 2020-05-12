#ifndef DATOS_2___2_0_HASHTABLE_H
#define DATOS_2___2_0_HASHTABLE_H

#include <map>
#include "Set.h++"

template <class K, class V>
class HashTable : multimap<K, V>{

public:
    HashTable(){
        cout << endl << "[Map-Initiate]\tEmpty!" << endl;
    }

    void print() {
        cout << "\n[KEY]\t[ELEMENT]\n";
        for (auto e = this->begin(); e != this->end(); ++e ) {
            cout << e->first << "\t\t"
                 << e->second << "\n";
        }
        cout << endl;
    }


    int length(){
        return this->size();
    }


    bool exist(const K &key) {
        auto it = this->find(key);
        return !(it==this->end());
    }


    void push(K key, V val){
        this->insert(pair<K,V>(key,val));
        cout << "[Map-Added]\t\t" << key <<"\t" << val << endl;
    }


    void remove(const K &key) {
        if (exist(key)) {
            vector<V> *vector = getKeyVector(key);
            this->erase(key);
            for (int i = 0; i < vector->size(); ++i) {
                cout << "[Map-Removed]\t" << key << "\t" << vector->at(i) << endl;
                return;
            }
        }cout << "[Map-not-found]\t" << key << endl;
    }


    void remove(const V &val) {
        for (auto e = this->begin(); e != this->end(); ++e) {
            if (e->second == val) {
                auto key = e->first;
                this->erase(e);
                cout << "[Map-Removed]\t" << key << "\t" << val << endl;
                return;
            }
        }
        cout << "[Map-not-found]\t" << val << endl;
    }


    vector<V>* getKeyVector(const K &key) {
        if(exist(key)){
            auto* vect = new vector<V>;
            auto range = this->equal_range(key);
            for (auto e= range.first; e != range.second; ++e) {
                vect->push_back(e->second);
            }
            return vect;
        }
        cout << "[Map-not-found]\t" << key << endl;
        return nullptr;
    }

    V getValue(const K &key) {
        if(exist(key)){
            auto range = this->equal_range(key);
            for (auto e= range.first; e != range.second; ++e) {
                if (e->first == key)
                    return e->second;
            }
        }
        cout << "[Map-not-found]\t" << key << endl;
        return nullptr;
    }


    V getValue(const V &val) {
        for (auto e = this->begin(); e != this->end(); ++e) {
            if (e->second == val)
                return e;
        }
        cout << "[Map-not-found]\t" << val << endl;
        return nullptr;
    }


    bool isAuthentic(const K &key){
        if(!exist(key)) return false;
        vector<V>* v = getKeyVector(key);
        if (v == nullptr)
            return false;
        return (v->size() == 1);
    }

    vector<Set *> *everySet() {
        auto* vect = new vector<V>;
        for (auto e = this->begin(); e != this->end(); ++e ) {
            vect->push_back(e->second);
        }
        return vect;
    }
};

#endif //DATOS_2___2_0_HASHTABLE_H
