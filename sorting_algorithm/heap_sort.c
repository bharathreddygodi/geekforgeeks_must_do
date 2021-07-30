#include "sorting.h"

static void heapify(int* a, int size, int root);

static void heapify(int* a, int size, int root)
{
    int left = 2*root + 1;
    int right = 2*root + 2;
    int largest = root;
    int temp = 0;

    if (left < size && a[left]>a[largest])
    {
        largest = left;
    }

    if (right < size  && a[right]>a[largest])
    {
        largest = right;
    }

    if(largest != root)
    {
        temp = a[largest];
        a[largest] = a[root];
        a[root] = temp;
        heapify(a, size, largest);
    }
}

void heap_sort(int* a, int numsSize)
{
    int temp = 0;
    //Build heap
    for( int i = (numsSize/2)-1; i >=0; i--) heapify(a, numsSize, i);
    // Get max element
    for(int i = numsSize-1; i > 0; i--)
    {
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapify(a, i, 0);
    }
}

void print_all(int* a, int numsSize)
{
    for(int i = 0; i < numsSize; i++)
    {
        printf("%d\n", a[i]);
    }
    printf("\n");
}

void main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    print_all(arr, n);
    heap_sort(arr, n);
    print_all(arr, n);
}