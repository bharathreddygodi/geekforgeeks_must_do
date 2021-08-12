
class SingleLinkedList{
    // Keep data and type private
    private:
        typedef struct node{
            int data;
            node *next;
        } sl_node_list_t;
        typedef sl_node_list_t* sl_node_list_ptr_t;

        // declaring private variables
        sl_node_list_ptr_t head;
        sl_node_list_ptr_t tail;
        sl_node_list_ptr_t temp;
        sl_node_list_ptr_t curr;

    // Declaration of API's to make use of list
    public:
        //constructor
        SingleLinkedList();
        // Add element
        void add_node(int data);
        // delete element
        void delete_node(int data);
        // print element
        void print_list();
        // destructor
        ~SingleLinkedList();
};
