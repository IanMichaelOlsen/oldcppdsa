/*********************
* Name: Ian Olsen
* Assignment: Linked Lists
* Create a proper doubly
* linked list and test
*********************/

#include "linkedlist.h"

//Constructor that sets head to NULL.
LinkedList::LinkedList() {
    head = NULL;
}

//exists Method
bool LinkedList::exists(int id) {
    bool doesExist = false;
    //If head not null, initialize and while current is not null and if current data is equal to id, exists is true
    if (head != NULL) {
        Node *current = head;
        while (current != NULL) {
            //check that placeholder data is equal to our id
            if (current->data.id == id) {
                doesExist = true;
            }
            current = current->next;
        }
    }
    //return our bool
    return doesExist;
}

//getNode method
bool LinkedList::getNode(int id, Data* data) {
    bool gotNode = false;
    //If head not null, initialize and while current is not null and if current data is equal to id, exists is true
    if (head != NULL) {
        Node *current = head;
        while (current != NULL) {
            if (current->data.id == id) {
                data->id = current->data.id;
                data->data = current->data.data;
                gotNode = true;
            }
            current = current->next;
        }
    }
    //return our bool
    return gotNode;
}

//deleteNode method
bool LinkedList::deleteNode(int id) {
    bool wasDeleted = false;
    //delete data when given a successful id to delete
    Node* current = head;
    if (current != NULL) {
        while (current && current->next && current->data.id != id) {
            current = current->next;
        }
        //delete at the head.
        if (current->prev == NULL && current->data.id == id) {
            head = current->next;
            current->next = NULL;
            delete current;
            wasDeleted = true;
        }//delete at the middle
        else if (current->prev && current->next) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            wasDeleted = true;
        }//delete at the tail
        else if (current->next == NULL && current->data.id == id) {
            current->prev->next = NULL;
            delete current;
            wasDeleted = true;
        }
    }
    return wasDeleted;
}

//Get count of all items in node head
int LinkedList::getCount() {
    int count = 0;
    Node *current = head;
//While current node is not null increase count
    while(current != NULL) {
        count++;
        current = current->next;
    }
//Return count
    return count;
}

//printList method
void LinkedList::printList(bool backwards) {

    Node *current = head;
    int index = 0;
    //Prints forward when bool is false
    if(!backwards){
       while (current != NULL) {
           std::cout << index << ": " << current->data.id << ": " << current->data.data << std::endl;
           current = current->next;
           index++;
       }
    }
    //Prints backwards when bool is true
    if(backwards){
        index = this->getCount()-1;
        while(current->next){
            current=current->next;
        }
        while(current){
            std::cout << index << ": " << current->data.id << ": " << current->data.data << std::endl;
            index--;
            current=current->prev;
        }
    }
}

//createNode
void LinkedList::assignNode(int id, string* data, Node* newNode) {
    Data *newData = new Data{id, *data};
    newNode->data = *newData;
}

//addHead method
bool LinkedList::addHead(Node* current, Node* newNode) {
    bool addSuccess = false;

    //ensure that our current id is not the same as our node id.
    if (current->data.id == newNode->data.id) {
        addSuccess = false;
    }
    //else if current data id is less than Node id, add nodes to list at head
    else if (current->data.id > newNode->data.id){
        if(!current->prev) {
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = NULL;
            head = newNode;
            addSuccess = true;
        }
        //Add nodes to list
        else {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
            addSuccess = true;
        }
    }
    //else if current is not at tail, call addHead recursively until list is filled.
    else if (current->next){
        addSuccess = addHead(current->next, newNode);
    }
    else {
        newNode->next = NULL;
        newNode->prev = current;
        current->next = newNode;
        addSuccess = true;
    }
    return addSuccess;
}

//addNode Method
bool LinkedList::addNode(int id, std::string *data) {
    bool addSuccess = false;

    //validate that input is good
    if(id > 0 && *data != "") {

        if(!head) {
            //Create new node and point to data's id and string, then assign.
            Node *newNode = new Node;
            assignNode(id, data, newNode);
            head = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
            addSuccess = true;
        }
        else {
            //Create new node and point to data's id and string, then assign.
            Node *newNode = new Node;
            //create a node and assign data.
            assignNode(id, data, newNode);
            //pass test data to addHead for insertion to list.
            addSuccess = addHead(head, newNode);
        }
    }
    return addSuccess;
}

//clearList method
bool LinkedList::clearList() {
    bool listCleared = false;
    //if head is not null
    if(head != NULL){
        Node *current = head;
        //while current is not null
        while (current != NULL) {
            //if moving forward in the list is not null
            if (current->next != NULL){
                head = current->next;
            }
            current->prev = NULL;
            Node *temp = current->next;
            //deallocate
            delete current;
            current = temp;
        }
    }
    //ensure list has been cleared
    head = NULL;
    listCleared = true;
    return listCleared;
}

//Destructor
LinkedList::~LinkedList() {
    clearList();
}
