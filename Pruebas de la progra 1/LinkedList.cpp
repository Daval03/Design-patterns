#include "LinkedList.h"

//check if our list is currently empty
template<class T>
bool LinkedList<T>::isEmpty() {
    return (length==0);
}

template<class T>
int LinkedList<T>::size() {
    return length;
}

template<class T>
void LinkedList<T>::add(T data) {
    if (!first) {
        // The list is empty
        first = new node<T>;
        first->data = data;
        first->next = NULL;
        last = first;
    } else {
        // The list isn't empty
        if (last == first) {
            // The list has one element
            last = new node<T>;
            last->data = data;
            last->next = NULL;
            first->next = last;
        } else {
            // The list has more than one element
            auto* insdata = new node<T>;
            insdata->data = data;
            insdata->next = NULL;
            last->next = insdata;
            last = insdata;
        }
    }length++;
}

template<class T>
T LinkedList<T>::get(int index) {
    if(index == 0) {
        // Get the first element
        return this->first->data;
    } else {
        // Get the index'th element
        node<T>* curr = this->first;
        for(int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }
}

template<class T>
T LinkedList<T>::operator[](int index) {
    return get(index);
}


template<class T>
void LinkedList<T>::removeByName(int key) {
    if (isEmpty()) {
        cout << "The list is empty" << endl;
    } else if (first->data == key){
        node<T>* current = first;
        first = first->next;
        delete current;
        length--;
    }else{
        node<T>* previous = first;
        node<T>* current = first->next;
        while(current != last) {
            if(current->data == key) {
                break;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
        if (current == last) {
            if (current->data != key) {
                cout << "Can't remove list_value: no match found.\n";
                return;
            } else {
                first, last = NULL;
                delete current;
                this->length--;
            }
        } else{
            previous->next = current->next;
            delete current;
            this->length--;
        }
    }
}

template<class T>
void LinkedList<T>::print() {
    if (isEmpty()) {
        cout << "[]" << endl;
        return;
    }
    node<T> *curr = first;
    cout << "_List" << endl <<"[ ";
    for (int i = 0; i < length; ++i) {
        cout << curr->data << " ";
        curr = curr->next;
    }cout << "]" <<endl <<endl;
}