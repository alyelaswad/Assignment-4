#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.h"
#include "Node.h"
#include "LinkedList.cpp"
using namespace std;
void insertAfter(vector<int> &v, int firstValue, int secondValue) // this function adds a number after every occurence of another
// number in the vector by looping through the vector and stopping when the firstnumber is met.
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == firstValue)
        {
            v.resize(v.size() + 1);
            for (int j = v.size(); j > i; j--)
            {
                v[j + 1] = v[j];
            }
            v[i + 1] = secondValue;
        }
    }
}
template <typename T>
LinkedList<T> createList(vector<T> &v) // this number creates a list6 based on a given vector
{
    LinkedList<T> list;
    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        int a = v[i];
        for (int j = 0; j < v.size(); j++) // this is done to know how many occurence that number has in the linked list.
        {
            if (v[j] == a)
            {
                count++;
            }
        }
        list.add(v[i], count);
    }
    return list;
}
int main()
{
    int n, firstValue, secondValue;
    cout << "Enter number of integers to be taken: "; // vector data.
    cin >> n;
    vector<int> v(n);
    cout << "Enter your integers: "
         << "(" << n << " integers)\n";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Enter the first number: (The one to insert after)\n";
    cin >> firstValue;
    cout << "Enter the number to be inserted: \n";
    cin >> secondValue;
    insertAfter(v, firstValue, secondValue);
    v.shrink_to_fit();
    cout << "Vector Contents before Linked List implementation.\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    LinkedList<int> l = createList(v);

    cout << "\nLinked list contents: \n";
    l.display();

    cout << "The sum of the list is " << l.sum();
    cout << endl;
    string ans;
    int d;
    do // test for pop functions.
    {
        cout << "Do you want to delete any nodes? ";
        cin >> ans;
        if (ans == "yes" || ans == "Yes")
        {
            cout << "What number do you want to delete?\n";
            cin >> d;
            l.pop(d);
            cout << "List after deletion:\n";
            l.display();
        }

        if (!(ans == "no" || ans == "No" || ans == "yes" || ans == "Yes"))
        {
            cout << "No valid answer was given...";
        }

    } while (ans == "yes" || ans == "Yes"); // validation for yes or no.
    cout << "\nEnd of program:)\n";
    return 0;
}