#include <cstdlib>
#include "linked_list_cpp.h"

using namespace std;

int main()
{
    SingleLinkedList ll;

    for (int data = 0; data < 10; data++)
    {
        ll.add_node(data);
    }
    ll.print_list();
    ll.delete_node(0);
    ll.delete_node(9);
    ll.delete_node(18);
    ll.print_list();
    return 0;
}