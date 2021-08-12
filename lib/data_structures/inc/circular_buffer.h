#include <stdbool.h>

typedef struct circular_buffer_tag circular_buf_t;

struct circular_buffer_tag{
    int *buffer;
    int head;
    int tail;
    int max;
    bool full;
};

/*Creating a handler to this circular buffer
* To abstract the access to the pointer of the circular buffer
*/
typedef circular_buf_t* circular_buf_handle_t;

/**
 * The other way to encapsulate the access of cir buffer through pointer is uintptr_t or void*
 */


/**
 * API's to access the circular buffer
 * 1. To Initialize the cir buffer
 * 2. To Destroy the cir buf
 * 3. To Reset Buffer
 * 4. To return max size of cir buffer
 * 5. To return number of elements in cir cuffer
 * 6. To return if the buffer is empty()
 * 7. To return if the cir buffer is full()
 * 8. To be able to add element to the cir buffer
 * 9. To get access to the next element in the cir buffer
 */

circular_buf_handle_t cir_buff_init(int size, int* buffer);
void cir_buff_destroy(circular_buf_handle_t handle);
void cir_buff_reset(circular_buf_handle_t handle);
int cir_buff_max_size(circular_buf_handle_t handle);
int cir_buff_numb_elements(circular_buf_handle_t handle);
bool cir_buff_empty(circular_buf_handle_t handle);
bool cir_buffer_full(circular_buf_handle_t handle);
/*Replace old element in buffer if it overflows*/
void cir_buffer_add_element(circular_buf_handle_t handle, int element);
/*Return -1 if overflow and don't replace old element else return 0 for successfully adding element*/
int cir_buffer_add_element2(circular_buf_handle_t handle, int element);
/*Return 0 if returned successfully else return -1 if empty*/
int cir_buff_next_element(circular_buf_handle_t handle, int* element);
