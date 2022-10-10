#include <bits/stdc++.h>
using namespace std;
#include "Node.h"

#ifndef LINKED_LIST
#define LINKED_LIST

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    LinkedList(int array[], int size);
    ~LinkedList();
    void addFront(int newItem);
    void addEnd(int newItem);
    void addAtPosition(int position, int newItem);
    int search(int item);
    void deleteFront();
    void deleteEnd();
    void deletePosition(int position);
    int getItem(int position);
    void printItems();
};
#endif