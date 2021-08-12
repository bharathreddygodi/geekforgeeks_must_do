#include "circular_buffer.h"

circular_buf_handle_t cir_buff_init(int size, int* buffer)
{
    assert((size !=0) && buffer);
    circular_buf_handle_t circular_buf = (circular_buf_handle_t)malloc(sizeof(circular_buf_t));
    circular_buf->buffer = buffer;
    circular_buf->max = size;
    cir_buff_reset(circular_buf);
    return circular_buf;
}

void cir_buff_destroy(circular_buf_handle_t handle)
{
    assert(handle);
    free(handle->buffer);
}

void cir_buff_reset(circular_buf_handle_t handle)
{
    assert(handle);
    handle->head = 0;
    handle->tail = 0;
    handle->full = 0;
}

int cir_buff_max_size(circular_buf_handle_t handle)
{
    assert(handle);
    return handle->max;
}

int cir_buff_numb_elements(circular_buf_handle_t handle)
{
    assert(handle);
}

bool cir_buff_empty(circular_buf_handle_t handle)
{
    bool ret = false;
    if (!handle->full && (handle->head == handle->tail))
    {
        ret = true;
    }
    return ret;
}

bool cir_buffer_full(circular_buf_handle_t handle)
{
    return handle->full;
}

static void incrementer_pointers(circular_buf_handle_t handle)
{
    if (handle->full)
    {
        handle->tail = (handle->tail + 1) % handle->max;
    }
    handle->head = (handle->head + 1) % handle->max;
    handle->full = (handle->head == handle->tail);
}

/*Replace old element in buffer if it overflows*/
void cir_buffer_add_element(circular_buf_handle_t handle, int element)
{
    handle->buffer[handle->head] = element;
    incrementer_pointers(handle);
}

/*Return -1 if overflow and don't replace old element else return 0 for successfully adding element*/
int cir_buffer_add_element2(circular_buf_handle_t handle, int element)
{
    int ret = -1;
    if (!cir_buff_full(handle))
    {
        handle->buffer[handle->head] = element;
        incrementer_pointers(handle);
        ret = 0;
    }
    return ret;
}


static void decrement_pointers(circular_buf_handle_t handle)
{
    handle->full = false;
    handle->tail = (handle->tail + 1) % handle->max;
}

/*Return 0 if returned successfully else return -1 if empty*/
int cir_buff_next_element(circular_buf_handle_t handle, int* element)
{
    int ret = -1;
    if (!cir_buff_empty(handle))
    {
        *element = handle->buffer[handle->tail];
        decrement_pointers(handle);
        ret = 0;
    }
    return ret;
}

void main()
{
    return;
}