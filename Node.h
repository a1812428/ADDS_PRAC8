#include <bits/stdc++.h>
using namespace std;
#ifndef NODE
#define NODE

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data);
    int getData();
    Node *getNext();
    void setData(int data);
    void setNext(Node *next);
};
#endif