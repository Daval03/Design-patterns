#ifndef DATOS_2___2_0_NODE_H
#define DATOS_2___2_0_NODE_H

template <class T>
class Node{
    T data;
    Node *next;

public:
    //constructor
    explicit Node(T data){
        this->data = data;
    };

    //methods
    T getData();
    void setData(T data);
    Node<T> getNext();
    void setNext(Node *next);
};



#endif //DATOS_2___2_0_NODE_H
