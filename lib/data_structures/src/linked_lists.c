#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "linked_lists.h"
/**
 * Single linked lists api definition 
 */


void initialize_linked_list(single_linked_list_ptr_t handle){
    handle->head = NULL;
    handle->tail = NULL;
}

void release_linked_list(single_linked_list_ptr_t handle){
    sl_node_ptr_t curr = handle->head;
    sl_node_ptr_t next = NULL;
    int count = 0;

    while (curr != NULL)
    {
        count++;
        next = curr->next;
        free(curr);
        curr = next;
    }
    printf("Release fn: Deleted %d elements in the linked list\n", count);
    initialize_linked_list(handle);
}

void add_node_to_linked_list(single_linked_list_ptr_t handle, int data){
    sl_node_ptr_t node = malloc(sizeof(sl_node_t));

    node->data = data;
    node->next = NULL;
    if (handle->tail == NULL)
    {
        handle->head = node;
        handle->tail = node;
    }
    else
    {
        handle->tail->next = node;
        handle->tail = node;
    }
}
void delete_node_in_linked_list(single_linked_list_ptr_t handle, int data){
    sl_node_ptr_t curr = handle->head;
    sl_node_ptr_t prev = handle->head;

    if (handle->head == NULL)
    {
        printf("No items to delete in the lists\n");
        return;
    }

    while(curr != NULL && curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Didn't find the data %d to delete\n", data);
        return;
    }
    else if (curr == handle->head) handle->head = curr->next;
    else{
        prev->next = curr->next;
        if (prev->next == NULL) handle->tail = prev;
    }
    free(curr);
}

void print_linked_list(single_linked_list_ptr_t handle){
    sl_node_ptr_t curr = handle->head;

    while (curr != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


/**
 * To test the single linked lists
 */
void single_linked_list_test()
{
    single_linked_list_t ll;
    single_linked_list_ptr_t handle = &ll;

    initialize_linked_list(handle);
    for (int data = 0; data < 10; data++) add_node_to_linked_list(handle, data);
    print_linked_list(handle);
    delete_node_in_linked_list(handle, 0);
    delete_node_in_linked_list(handle, 9);
    delete_node_in_linked_list(handle, 18); //No data present
    print_linked_list(handle);
    release_linked_list(handle);
}

void main()
{
    single_linked_list_test();
}