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
void linkedlist::insert_head(int value) {

    // initialize a new node
    // store the data and set the next to point to null

     node * current = new node;
     current->value = value;    //set value of current node
     current->next = head;      // head of linkedlist is at the top

    // if head = NULL then the list is empty. Set tail = current
    if (head == NULL) {
        tail = current;
    }
     // set head node pointer to the front of the list
     head = current;
}

void linkedlist::insert_tail(int value) {

    node * current = new node;
    current->value = value;
    current->next = NULL;
    tail->next = current;
    tail = current;

}

int linkedlist::get_head() {

    return head->value;
}

int linkedlist::get_tail() {

    return tail->value;
}


void linkedlist::print_list() {

    node * n = new node;
    n = head;

    cout << " | ";
    while (n != NULL)
    {
        cout << n->value << " | ";

        // interate by setting n to the next node pointed.
        n = n->next;
    }
}

linkedlist::~linkedlist()
{
    //dtor
}
