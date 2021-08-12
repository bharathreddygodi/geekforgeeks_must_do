#include "assert.h"
#include "stack_implementation.h"

// Stack init
stack_t* stack_init(int size)
{
    stack_t* stack = malloc(sizeof(stack_t));
    assert(stack!=NULL);
    stack->totalSize = size;
    stack->empty = true;
    stack->sp = 0;
    stack->buffer = malloc(sizeof(int)*size);
    assert(stack->buffer != NULL);
    return stack;
}

// Stack free
int stack_free(stack_t* handle)
{
    free(handle->buffer);
    handle->buffer = NULL;
    free(handle);
}

// Stack reset
void stack_reset(stack_t* handle)
{
    handle->empty = true;
    handle->sp = 0;
}

// stack_peek
int stack_peak_top(stack_t* handle)
{
    return handle->buffer[handle->sp];
}

// return if stack is empty
bool stack_empty(stack_t* handle)
{
    return handle->empty;
}

//return if stack is full
bool stack_full(stack_t* handle)
{
    return (handle->sp == handle->totalSize);
}

// Stack push
int stack_push(stack_t* handle, int element)
{
    int ret = -1;
    if(!stack_full(handle))
    {
        handle->buffer[handle->sp] = element;
        handle->sp++;
        ret = 0;
        handle->empty = false;
    }
    return ret;
}

// Stack pop
int stack_pop(stack_t* handle)
{
    int ret = -1;
    if (!stack_empty(handle))
    {
        handle->sp--;
        if (handle->sp == 0) handle->empty = true;
        ret = 0;
    }
    return ret;
}

int stack_total_size(stack_t* handle)
{
    return handle->totalSize;
}

static void print_stack_elements(stack_t* handle)
{
    int sp = handle->sp;
    for (int i = 0; i < handle->sp; i++)
    {
        printf("%d\n", handle->buffer[sp-1-i]);
    }
}

void main()
{
    stack_t* handle;
    handle = stack_init(10);
    for(int i = 0; i < 10; i++) stack_push(handle, i);
    print_stack_elements(handle);
    for(int i = 0; i < 5; i++) stack_pop(handle);
    printf("after popping\n");
    print_stack_elements(handle);
    stack_free(handle);
}