#include <stdio.h>
#include <stdlib.h>

#define MAX 10


/****************   Static Array    **********************************/
void insert_element_into_static_array(int *arr, int index, int element)
{
    for (int i = (MAX-1); i > index; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = element;
}

void delete_element_in_static_array(int *arr, int index)
{
    int i = index;
    for (i; i < (MAX-1); i++)
    {
        arr[i] = arr[i+1];
    }
    arr[i] = 0;
}

int lookup_index_in_static_array(int *arr, int index)
{
    return arr[index];
}

void print_array(int *arr, int size)
{
    int i = 0;
    while(i < size)
    {
        printf("%d\t", arr[i]);
        i++;
    }
    printf("\n");
}

/************** Dynamic Array ***************************************************/
void insert_element_into_dynamic_array(int **arr, int index, int element)
{
    if (index >= MAX)
    {
        *arr = realloc(*arr, (index+1) * sizeof(**arr));
    }
    else{
        for (int i = (MAX-1); i > index; i--)
        {
            *arr[i] = *arr[i-1];
        }
    }

    (*arr)[index] = element;
}

/**
 * @brief Demonstrating the following with arrays
 *  1. Static size of arrays
 *      a. Implement
 *      b. Insert
 *      c. Delete
 *      d. Lookup
 *  2. Dynamc arrays
 *      a. Implement
 *      b. Insert
 *      c. Delete
 *      d. Lookup
 */

void main()
{
    int index = 0;
    int value = 0;

    // 1.a Implement a static array of size MAX and initializing with 0
    int static_arr[MAX] = {1,2,3,4,5,6};

    // Replace
    value = 10;
    if (index < MAX) {
        static_arr[index] = value;
        print_array(static_arr, MAX);
    }

    // 1.b Insert; Not actually real insert, it is just shifting right untill it touches the max range of index to place it
    // sometimes loosing the elements from the last index, because we cannot overflow in the static array
    index = 4;
    if (index < MAX) {
        insert_element_into_static_array(static_arr, index, 8);
        print_array(static_arr, MAX);
    }

    // 1.c Delete; Not actually real delete, it is just shifting left by one element to replace given index.
    if (index < MAX) {
        delete_element_in_static_array(static_arr, index);
        print_array(static_arr, MAX);
    }

    // 1.d Lookup; Lookup with index takes O(1) time complexity; lookup for a value in array is a "search".
    // Search can be done through better algorithms to reduce time complexity. A Brute force search would take O(n).
    if(index < MAX) {
        printf("%d\n", lookup_index_in_static_array(static_arr, index));
    }



    //Implement a dynamic array
    int *dynamic_arr = malloc(sizeof *dynamic_arr *MAX);
    print_array(dynamic_arr, MAX);
    insert_element_into_dynamic_array(&dynamic_arr, MAX+1, 10);
    print_array(dynamic_arr, MAX+2);
    // Release the array before exiting
    free(dynamic_arr);
}