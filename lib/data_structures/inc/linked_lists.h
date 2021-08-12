
/**
 * Single linked list node declaration
 */
typedef struct node sl_node_t;
struct node{
    int data;
    sl_node_t *next;
};

typedef struct node* sl_node_ptr_t;


typedef struct sl_linked_list{
    sl_node_ptr_t head;
    sl_node_ptr_t tail;
} single_linked_list_t;

typedef single_linked_list_t* single_linked_list_ptr_t;

/**
 * Single linked list API's
 */

void initialize_linked_list(single_linked_list_ptr_t handle);
void release_linked_list(single_linked_list_ptr_t handle);
void add_node_to_linked_list(single_linked_list_ptr_t handle, int data);
void delete_node_in_linked_list(single_linked_list_ptr_t handle, int data);
void print_linked_list(single_linked_list_ptr_t handle);