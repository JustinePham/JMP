#ifndef NODE_H
#define NODE_H

#include <cstdlib>

class node
{
    public:
        node( double );
        void set_data();
        void set_link();

        virtual ~node();
    private:
        double value;
        node* link;

};

#endif // NODE_H
