#ifndef DATOS_2___2_0_GBCOLLECTOR_H
#define DATOS_2___2_0_GBCOLLECTOR_H

#include <map>
#include "Set.h++"
#include "HashTable.h++"

class GBCollector {
private:
    GBCollector() {
        cout << "[GBCollector]\tStarted!" << endl << endl;
    }

    static GBCollector *instance; //static class instance

public:
    /* Empty multimap container. HashTable for Sets elements */
    HashTable<string, Set*>* setMap = new HashTable<string, Set*>;

    /**
     * Return reference to static instance o GBCollector.
     * @return GBCollector*
     */
    static GBCollector *getInstance();

    /**
     * Returns the size of the garbage collector HashTable.
     * @return int
     */
    int length() const {
        return setMap->length();
    }

    /**
     * Returns true for original, false for ref.
     * @param id
     * @param address
     * @return bool
     */
    bool deletePtr(const string& id, void ** address) const{
        if(getAuthentic(id) != nullptr){ //authentic
            return true;
        }else { //not authentic
            Set* reference = getRef(id,address);
            if(reference != nullptr){
                return true;
            }
        }return false;
    }

    /**
     * Returns the set that matches the entered ID. Note: Returns authentic Sets.
     * @param id
     * @return Set*
     */
    Set* getAuthentic(const string &id) const {
        if (setMap->isAuthentic(id)){
            Set* authentic = setMap->getValue(id);
            return authentic;
        }return nullptr;
    }

    /**
     * Returns the set that matches the entered ID. Note: Returns authentic Sets.
     * @param id
     * @param address
     * @return Set*
     */
    Set* getRef(const string &id, void** address) const {
        if (setMap->isAuthentic(id)) {
            Set *authentic = setMap->getValue(id);
            return authentic;
        }else if (setMap->exist(id)){
            auto refVector = setMap->getKeyVector(id);
            for (auto & refSet : *refVector) {
                if (refSet->getVsAddress() == address) {
                    return refSet;
                }
            }
        }return nullptr;
    }

    /**
     * Add to the map a new value with its own key.
     * @param id
     * @param set
     */
    void pushReference(Set *set) const {
        setMap->push(set->id,set);
    }

    /**
     * Delete the authentic Set that matches the param.
     * @param id
     */
    void deleteAuthentic(const string &id) const {
        setMap->remove(id); //delete a unique key inside the map.
    }

    /**
     * Delete the reference Set that matches the param.
     * @param ref
     */
    void deleteReference(Set* ref) const{
        setMap->remove(ref); //delete ref Set from the map.
    }

    /**
     * Updates the id and pointed memory address of the pointers involved
     * when creating or deleting a reference.
     * @param id
     * @param tId
     * @param vsAddress
     */
    void update(const string& pointedID, const string& referrerID, void** pointedAddress, void** referrerAddress) const {
        if (setMap->exist(pointedID) && setMap->exist(referrerID) && referrerID != pointedID){
            /* get involved Sets. */
            Set *referrer= getRef(referrerID, referrerAddress); //Referrer : ref that you want to point to another ref.
            Set *pointed = getRef(pointedID, pointedAddress); //Pointed : pointer pointed by the referrer pointer.
            /* remove value from old key & update PointTo of the involved Sets*/
            if (referrer->refsList->empty()){updatePointTo(pointed, referrer);
            }else{updateRefsPointTo(pointed, referrer);}
        }
    }

    void updateRefsPointTo(Set *pointed, Set *referrer) const{
        auto refVector = setMap->everySet();
        cout << "[Map-Info]\t\t" << referrer->id <<" has  "<< referrer->refsList->size() << "  references." << endl;
        int i=1;
        for (auto &refAddress : *referrer->refsList) {
            cout << "\n[Map-Info]\t\t" << "Ref #" << i << endl;
            for (auto &prevReferrerSet : *refVector) {
                if (prevReferrerSet->getVsAddress() == refAddress) {
                    updatePointTo(pointed, prevReferrerSet); //make all its references point to pointed.
                }
            }i++;
        }
        updatePointTo(pointed, referrer); //make the referrer point to pointed.
    }

    void updatePointTo(Set *pointed, Set *referrer) const {
//        cout << "pt Pointed " << pointed->pointingTo << endl;
//        cout << "pt Referrer " << referrer->pointingTo << endl;
        /* if the referrer does not point to anyone. */
        if (referrer->pointingTo == nullptr) {
            deleteAuthentic(referrer->id); //the referrer is authentic.
        }/* if the referrer does point to someone. */
        else {
            deleteReference(referrer); //remove ref from the hash.
            auto refVector = setMap->everySet();
            for (auto &refSet : *refVector) {
                if (refSet == referrer->pointingTo)
                    refSet->removeAddress(referrer->getVsAddress()); //now quit ref to prev reference.
            }
        }
        /* if the pointer does point to someone. */
        if (pointed->pointingTo != nullptr){
            while (pointed->pointingTo != nullptr) {
                pointed = pointed->pointingTo;
            }
        }
        referrer->pointingTo = pointed;
        pointed->refsList->push_back(referrer->getVsAddress()); //now referrer refers to what point refers.
        /* renovate id. */
        cout << "[Map-Update]\tKey  \"" << referrer->id << "\"  renovated to  \"" << pointed->id << "\"" << endl;
        referrer->id = pointed->id; //copy id.
        referrer->vsData = pointed->getDataAddress(); //copy data address.
        /* push value with new key. */
        pushReference(referrer);
        cout << endl;
    }

    void print() const  {
        cout << "\n[GBCollector]\tPrinting!\n";
        vector<Set *> *everySet = setMap->everySet();
        for (auto & i : *everySet) {
            if (!i->pointingTo)
                i->toString();
        }
    }

};

/* Uninitialized. */
GBCollector* GBCollector::instance = nullptr;
GBCollector* GBCollector::getInstance() {
    if (instance == nullptr){
        instance = new GBCollector();
    }
    return instance;
}

#endif //DATOS_2___2_0_GBCOLLECTOR_H
