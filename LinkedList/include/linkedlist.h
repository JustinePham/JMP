#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

struct node
{
    int value;
    node * next;
};

class linkedlist
{
    public:
        node * head;
        node * tail;
        node * current;
        linkedlist();
        void insert_node(int );
        void print_list();

        ~linkedlist();

};

#endif // LINKEDLIST_H
