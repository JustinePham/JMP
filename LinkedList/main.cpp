#include <iostream>
#include <string>
#include <cstdlib>

#include "include/linkedlist.h"

using namespace std;

int main()
{
    linkedlist LIST;

    for(int i = 0; i < 10; i++) {

        LIST.insert_node(i);
    }

    LIST.print_list();

    return 0;
}
