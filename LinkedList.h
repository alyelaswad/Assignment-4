#ifndef LinkedList_H
#define LinkedList_H
#include "Node.h"
template <class T>
class LinkedList
{
private:
    Node<T> *head, *tail;

public:
    Node<T> *get_head(); // getter for head and tail.
    Node<T> *get_tail();

    LinkedList();
    ~LinkedList();

    void add(T info_p, int count); // adds a number and its occurences in the list.
    void pop(T inf);               // pops a certain int,double ,etc from the list.
    void display();                // display lists contents.

    T sum();
};
#endif