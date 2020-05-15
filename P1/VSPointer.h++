#ifndef DATOS_2___2_0_VSPOINTER_H
#define DATOS_2___2_0_VSPOINTER_H

#include "GBCollector.h++"
#include "Set.h++"

template <class T>
class VSPointer {
    /* Garbage collector static instance */
    GBCollector* gbCollector = GBCollector::getInstance();

public:
    /* Pointer */
    T* ptr;
    /* Pointer id */
    string id;
    /* Pointer type */
    string type;
    /* Pointer memory address */
    void** address;
//    /* Pointer memory address */
//    bool isNew;


    VSPointer()=default;

    /**
     * VSPointer class constructor.
     * @param p
     */
    explicit VSPointer(int i) {
//        isNew = false;
        ptr = (typeof(*ptr)*)malloc(sizeof(*ptr));
        type = typeid(*ptr).name();
        id = "id" + to_string(gbCollector->length());
        address = (void **)this;
        Set* set = new Set(id, type, ptr, address); //Wrap Set & push in map.
        gbCollector->setMap->push(id, set); //push in map.
        gbCollector->generalSet->push_back(set); //push in all set map.
        gbCollector->generalPtr->push_back(ptr); //push in all T addresses.
    }

    void toString(){
        cout << "VSP: " << this
             << "\n\tID: " << id
             << "\n\tTYPE: " << type
             << "\n\tREF_TO: " << ptr
             << "\n\tVALUE: " << to_string(*ptr)
             << "\n\thas been created..!" << endl;
    }

    /**
     * Initializer.
     * @return
     */
    static VSPointer New(){
        return VSPointer(0);
    }

    /**
     * VSPointer class destructor.
     * Delete T* and free its memory.
     */
    ~VSPointer() {
        if(gbCollector->deletePtr(id, reinterpret_cast<void**>(this)))
            free (ptr);
    }

    /**
     * Now ampersand dereferences the pointer value.
     * @return T
     */
    T operator &(){
        return *ptr;
    }

    /**
     * Overload * operator.
     * @return T&
     */
    T& operator *() {
        return *ptr;
    }

    /**
     * Overloaded arrow operator.
     * @return T*
     */
    T* operator -> () {
        return ptr;
    }

    /**
     * Operator "=" overload on all supported variable types.
     * @param target
     * @return VSPointer&
     */
    VSPointer& operator=(int target){verifyType(typeid(&target).name(), target);}
    VSPointer& operator=(char target){verifyType(typeid(&target).name(), target);}
    VSPointer& operator=(bool target){verifyType(typeid(&target).name(), target);}
    VSPointer& operator=(float target){verifyType(typeid(&target).name(), target);}
    VSPointer& operator=(double target){verifyType(typeid(&target).name(), target);}
    VSPointer& operator=(short target){verifyType(typeid(&target).name(), target);}
    VSPointer& operator=(long target){verifyType(typeid(&target).name(), target);}
    VSPointer& operator=(long double target){verifyType(typeid(&target).name(), target);}
    VSPointer& operator=(long long target){verifyType(typeid(&target).name(), target);}

    /**
     * Check the type matching before switching the value of the pointer to the target value.
     * @param type
     * @param target
     */
    void verifyType(const string& type2, T target) {
        cout << "\n\t\tTypes: " << type << " - "<<type2 << endl;

        if (type==type2) {
            *ptr = target;
            return;
        }
        cout << "Operation failed, types don't match" << endl;
    }

    /**
     * Check the type matching before coping the pointed ptr to the ptr.
     * @param pointed
     * @return VSPointer&
     */
    VSPointer& operator=(VSPointer pointed){
        cout << "\n[Operator(=)]\t( " << id << ", " << *ptr
             << " )\t->\t( " << pointed.id << ", " << *pointed.ptr << " )" << endl;
        string type2 = typeid(T).name();
        if(type==type2){
            ptr = pointed.ptr;
            gbCollector->update(pointed.id, id, pointed.address,reinterpret_cast<void **>(this));
            id = pointed.id;
        }else{
            cout << "Operation fail, types don't match" << endl;
        }
    }
};

#endif //DATOS_2___2_0_VSPOINTER_H
