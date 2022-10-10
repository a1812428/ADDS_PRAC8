#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->head = NULL;
}

LinkedList::LinkedList(int array[], int size)
{
    this->head = NULL;
    for (int i = 0; i < size; i++)
        addEnd(array[i]);
}

LinkedList::~LinkedList()
{
    Node *helper = this->head;
    while (helper != NULL)
    {
        Node *node = helper;
        helper = helper->getNext();
        delete (node);
    }
    this->head = NULL;
}

void LinkedList::addFront(int newItem)
{
    Node *temp = new Node(newItem);
    temp->setNext(this->head);
    this->head = temp;
}

void LinkedList::addEnd(int newItem)
{
    if (this->head == NULL)
    {
        addFront(newItem);
        return;
    }
    Node *temp = new Node(newItem);
    temp->setNext(NULL);
    Node *helper = this->head;
    while (helper->getNext() != NULL)
    {
        helper = helper->getNext();
    }
    helper->setNext(temp);
}

void LinkedList::addAtPosition(int position, int newItem)
{
    Node *helper;
    Node *n = new Node(newItem);
    int pos = 1;
    if (position < 1 || position == 1)
    {
        addFront(newItem);
        return;
    }
    for (helper = this->head; helper != NULL; helper = helper->getNext())
    {
        if ((pos + 1) == position)
        {
            n->setNext(helper->getNext());
            helper->setNext(n);
            return;
        }
        pos++;
    }
    addEnd(newItem);
}

int LinkedList::search(int item)
{
    int i = 1;
    for (Node *helper = this->head; helper != NULL; helper = helper->getNext())
    {
        if (item == helper->getData())
            cout << i << " " << endl;
        i++;
    }
    cout << "0 ";
    return 0;
}

void LinkedList::deleteFront()
{
    Node *helper = this->head;
    this->head = helper->getNext();
    delete (helper);
}

void LinkedList::deleteEnd()
{

    if(this->head==NULL)
        return;
    if (this->head->getNext() == NULL)
    {
        delete (head);
        this->head = NULL;
    }
    Node *helper = this->head;
    while(helper->getNext()!=NULL && helper->getNext()->getNext() != NULL){
        helper = helper->getNext();
    }
    delete (helper->getNext());
    helper->setNext(NULL);
}

void LinkedList::deletePosition(int position)
{
    if (position < 1)
    {
        cout << "outside range";
        return;
    }

    if (position == 1)
    {
        Node *helper = this->head;
        this->head = this->head->getNext();
        delete (helper);
        return;
    }
    int index = 1;
    for (Node *helper = this->head; helper != NULL; helper = helper->getNext())
    {
        if (index + 1 == position)
        {
            Node *node = helper->getNext();
            if (node == NULL)
            {
                cout << "outside range";
                return;
            }
            helper->setNext(node->getNext());
            delete (node);
            return;
        }
        index++;
    }
}

int LinkedList::getItem(int position)
{
    int index = 1;
    Node *helper;
    for (helper = head; helper != NULL; helper = helper->getNext())
    {
        if (index == position)
        {
            cout << helper->getData() << " ";
            return helper->getData();
        }
        index++;
    }
    return 0;
}

void LinkedList::printItems()
{
    for (Node *helper = this->head; helper != NULL; helper = helper->getNext())
        cout << helper->getData() << " ";
}