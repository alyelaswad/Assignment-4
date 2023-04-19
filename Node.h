#ifndef Node_H
#define Node_H
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    Node *next; // the next node to point to.
    Node *back; // the previous node to point to.
    int count;
    bool displayed = false; // a means used to output numbers in the format 1(2) 2 0(3).
    T info;                 // carried integer or data.
    Node()                  // initializing the head and back to null.
    {
        next = nullptr;
        back = nullptr;
    }
};
#endif