#include<iostream>
#include "../include/linkedlist.h"


/*************************************
    Singly linked list
    Adds to the front of the list
**************************************/
linkedlist::linkedlist()
{
    // initialize pointers
    // head points to null
    // current starts at the head
    head = NULL;
    tail = NULL;
}


/**********************************************
    Precondition: has int value passed to
                  insert_node function

    Postcondition: head->next point to the
                   previous node.
        e.g.
        head -> 3 -> 2 -> 1 -> NULL
          |
        current

**********************************************/
void linkedlist::insert_node(int value) {

    // initialize a new node
    // store the data and set the next to point to null

     node * current = new node;
     current->value = value;    //set value of current node
     current->next = head;      // point current to the head

     // set head node pointer to the front of the list
     head = current;


}

void linkedlist::print_list() {

    node * n = new node;
    n = head;
    while (n != NULL)
    {
        cout << "Data: " << n->value << endl;

        // interate by setting n to the next node pointed.
        n = n->next;
    }
}

linkedlist::~linkedlist()
{
    //dtor
}
