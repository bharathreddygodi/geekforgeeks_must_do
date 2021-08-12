#include <cstdlib>
#include <iostream>
#include "linked_list_cpp.h"

using namespace std;

SingleLinkedList::SingleLinkedList(){
    head = nullptr;
    tail = nullptr;
    temp = nullptr;
    curr = nullptr;
}

void SingleLinkedList::add_node(int data){
    curr = new sl_node_list_t;

    curr->data = data;
    curr->next = nullptr;
    if (tail == nullptr)
    {
        tail = curr;
        head = curr;
    }
    else
    {
        tail->next = curr;
        tail = curr;
    }
}

void SingleLinkedList::delete_node(int data){
    curr = head;
    if (head == NULL)
    {
        cout << "No element to delete in the list" << endl;
        return;
    }

    while (curr != nullptr && curr->data != data)
    {
        temp = curr;
        curr = curr->next;
    }
    if (head == curr) head = curr->next;
    else if (curr == nullptr){
        cout << "data " << data << " is not available in the list to delete" << endl;
        return;
    }
    else{
        temp->next = curr->next;
        if (temp->next == nullptr) tail = temp;
    }
    delete curr;
}

void SingleLinkedList::print_list(){
    curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << "\t";
        curr = curr->next;
    }
    cout << "\n" << endl;
}

SingleLinkedList::~SingleLinkedList(){
    curr = head;
    int count = 0;
    while(curr != nullptr)
    {
        count++;
        temp = curr;
        curr = curr->next;
        delete temp;
    }
    cout << "Deleted " << count << " element in the linked list as part of destructor" << endl;
}