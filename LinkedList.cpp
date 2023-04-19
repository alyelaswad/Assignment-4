#include <iostream>
using namespace std;
template <class T>
Node<T> *LinkedList<T>::get_head()
{
    return head;
}
template <class T>
Node<T> *LinkedList<T>::get_tail()
{
    return tail;
}
template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}
template <class T>
LinkedList<T>::~LinkedList()
{
    head = NULL;
    tail = NULL;
}
template <class T>
void LinkedList<T>::add(T info_p, int count) // this is similar to the append function done in a previous lab.
{
    Node<T> *temp = new Node<T>;
    temp->info = info_p;
    if (head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {

        temp->back = tail;
        tail->next = temp;
        temp->next = NULL;
        tail = tail->next;
    }
    temp->count = count;
}
template <class T>
void LinkedList<T>::pop(T inf)
{
    Node<T> *current = head;
    Node<T> *previous = nullptr;

    while (current != nullptr)
    {
        if (current->info == inf)
        {
            if (current->count > 1) // if the node is repeated the node is not popped, one occurrence of it is ejected.
            {
                current->count--;
            }
            else if (current->count == 1)
            {
                if (previous == nullptr)
                { // deleting the head node
                    head = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                if (current->next == nullptr)
                { // deleting the tail node
                    tail = previous;
                }
                else
                {
                    current->next->back = previous;
                }
                Node<T> *nextNode = current->next;
                delete current;
                current = nextNode;
                while (current != nullptr && current->info == inf)
                {
                    current->count--;
                    Node<T> *nodeToDelete = current;
                    current = current->next;
                    delete nodeToDelete;
                }
                return;
            }
        }
        previous = current;
        current = current->next;
        return;
    }

    cout << "The node with info " << inf << " could not be found." << endl; // if the function has not returned by now then inf doesn't exsist in the list.
}
template <class T>
void LinkedList<T>::display()
{
    Node<T> *mirror = head;
    if (head == NULL)
    {
        cout << "List is empty.";
    }

    while (mirror != NULL)
    {
        int count = mirror->count;
        Node<T> *follow = mirror->next;
        while (follow != NULL)
        {
            if (mirror->info == follow->info)
            {
                follow->displayed = true;
            }

            follow = follow->next;
        }

        if (count > 1 && mirror->displayed == false)
        {
            cout << mirror->info << "(" << count << ") ";
        }
        else
        {
            if (mirror->displayed == false)
            {
                cout << mirror->info << " ";
            }
        }

        mirror = mirror->next;
    }
    cout << endl;
    mirror = head;
    while (mirror != NULL) // this helps in case we want to display again.
    {
        mirror->displayed = false;
        mirror = mirror->next;
    }
}
template <class T>
T LinkedList<T>::sum() // traversing the list and getting the sum.
{
    T sum = 0;
    Node<T> *mirror = head;
    if (head == NULL)
    {
        cout << "List is empty.";
    }

    while (mirror != NULL)
    {
        sum += mirror->info;
        mirror = mirror->next;
    }
    return sum;
}
