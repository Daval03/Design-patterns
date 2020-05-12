#ifndef DATOS_2___2_0_SET_H
#define DATOS_2___2_0_SET_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Set {
public:
    /* Set id. */
    string id;
    /* Set type. */
    string type;
    /* Address of the pointer. */
    void* vsAddress;
    /* Value of the pointer. */
    void* vsData;
    /* Reference Vector. */
    vector<void**>* refsList = new vector<void**>;
    /* Reference to the pointer it points to */
    Set* pointingTo = nullptr;

    /**
     * Set class constructor.
     * @param id
     * @param type
     * @param vsData
     * @param vsAddress
     */
    Set(const string& id, const string& type, void *vsData, void *vsAddress){
        this->id = id;
        this->type = type;
        this->vsData = vsData;
        this->vsAddress = vsAddress;
    }

    /**
     * Print the Set attributes.
     */
    void toString() const{
        cout << "---------\n\tvs: " << id << endl
             << "\ttype: " << type << endl
             << "\trefAddress: " << getDataAddress() << endl
             << "\tpointTo: " << pointingTo << endl
             << "\tvalue: " << getValueData() << endl
             << "\trefCount: " << refsList->size() << endl
             << "\t0: " << vsAddress << "  /Authentic" << endl;
        for(int i = 0; i < refsList->size(); i++){
            cout << "\t"<< i+1 << ": " << refsList->at(i) << endl;
        }
    }

    /**
     * Returns the memory address the pointer points to.
     * @return void**
     */
    void** getDataAddress() const {
        return static_cast<void **>(this->vsData);
    }

    /**
     * Returns the memory address of the pointer.
     * @return void**
     */
    void** getVsAddress() const {
        return static_cast<void **>(this->vsAddress);
    }

    /**
     * Returns the value of the memory address the pointer points to. It's casted to its original type.
     * @return string
     */
    string getValueData() const {
        if (type == "i") {return to_string(*static_cast<int *>(vsData));
        } else if (type == "b") {return to_string(*static_cast<bool *>(vsData));
        } else if (type == "c") {string s(1, *static_cast<char *>(vsData));return s;
        } else if (type == "s") {return to_string(*static_cast<short *>(vsData));
        } else if (type == "l") {return to_string(*static_cast<long *>(vsData));
        } else if (type == "x") {return to_string(*static_cast<long long *>(vsData));
        } else if (type == "f") {return to_string(*static_cast<float *>(vsData));
        } else if (type == "d") {return to_string(*static_cast<double *>(vsData));
        } else if (type == "e") {return to_string(*static_cast<long double *>(vsData));
        } else {cout << "Invalid pointer type" << endl;}
    }

    void removeAddress(void** address) const{
        for(int i = 0; i < refsList->size(); i++) {
            if (refsList->at(i) == address)
                refsList->erase(refsList->begin() + i);
        }
    }



};

#endif //DATOS_2___2_0_SET_H
