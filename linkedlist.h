/*********************
* Name: Ian Olsen
* Assignment: Linked Lists
* Create a proper doubly
* linked list and test
*********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include "testdata.h"
#include "iostream"

class LinkedList {

public:
    LinkedList(); //Constructor
    ~LinkedList(); //Destructor
    int getCount();
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    bool clearList();
    bool exists(int);\
    void printList(bool = false);
    
private:
    Node *head;
    bool addHead(Node*, Node*);
    void assignNode(int, string *, Node *);
};

#endif //LINKEDLIST_H
