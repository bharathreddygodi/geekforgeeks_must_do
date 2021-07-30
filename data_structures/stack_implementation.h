#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct stackStruct
{
    int sp;
    int totalSize;
    bool empty;
    int *buffer;
}stack_t;

// Stack init
stack_t* stack_init(int size);
// Stack free
int stack_free(stack_t* handle);
// Stack reset
void stack_reset(stack_t* handle);
// return element that is on top of the element
int stack_peak_top(stack_t* handle);
// return if stack is empty
bool stack_empty(stack_t* handle);
//return if stack is full
bool stack_full(stack_t* handle);
// Stack push
int stack_push(stack_t* handle, int element);
// Stack pop
int stack_pop(stack_t* handle);

