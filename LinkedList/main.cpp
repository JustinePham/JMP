#include <iostream>
#include <string>
#include <cstdlib>

#include "include/linkedlist.h"

using namespace std;

int main()
{
    linkedlist LIST;

    for(int i = 0; i < 10; i++) {

        LIST.insert_head(i);
    }

    LIST.insert_tail(-10);

    LIST.print_list();
    cout << endl << LIST.get_head() << endl << LIST.get_tail();


    return 0;
}
