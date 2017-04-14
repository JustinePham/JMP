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
        ~linkedlist();

        void insert_head(int );
        void insert_tail(int );
        int get_tail();
        int get_head();
        void print_list();
        int search_list(int);


};


#endif // LINKEDLIST_H
