/**
 *  Academic purpose only!
 *  author: Gustavo Cavalcante - University of Brasilia
 */
#include <stdio.h>

typedef struct list *list; // define list as a pointer to struct list

// struct that represents each node of a list
struct list{

    int data; // generic data , could be any data type
    list next;
    list previous;

};

/**
 * Creates a pointer to pointer to be the head of the list
 * @return returns the head pointing to NULL
 */
list* create_list(){

    list *new_list = (list*) malloc ( sizeof(list) );

    new_list = NULL;

    return new_list;
}

/**
 * Create a new node and makes the head point to it.
 * @param head is the list itself
 * @param value is what the data of the node will receive
 * @return returns the head with a new node on it.
 */
list add_node_head(list *head, int value){

    list new_node = (list*) malloc ( sizeof(list) );

    // checks if the list is empty
    if ( head == NULL ){

        head = new_node;
        new_node->next = new_node;
        new_node->previous = new_node;
        new_node->data = value;

        printf("Value added successfully, value = %d\n", new_node->data);
    }else{

        new_node->data = value;
        new_node->next = head; // points it to the first element on the list

        list aux = head; // auxiliar pointer that points where the head was pointing

        /*
         * If the list has only one node , it is necessary to create the
         * basic structure of the circular doubly linked list
         */
        if ( count_nodes(head) == 1 ){

            aux->next = new_node;
            aux->previous = new_node;

            new_node->previous = aux;

            head = new_node;
        }else{

            aux->previous = new_node; // makes the first element to point to a new node

            // takes the last node of the list
            while ( aux->next != head ){

                aux = aux->next;

            }

            new_node->previous = aux;
            aux->next = new_node;
            head = new_node;

        }

        printf("Value added successfully, value = %d\n", new_node->data);

    }

    return head;

}
/**
 * Create a new node and make the last node point to it
 * @param head is the list itself
 * @param value is what the data of the node will receive
 * @return returns the head with a new node on the end.
 */
list add_node_tale(list *head, int value ){

    list new_node = (list*) malloc ( sizeof(list) );

    // checks if the list is empty
    if ( head == NULL ){

        // add a new node to beggining of the list
        head = new_node;
        new_node->next = new_node;
        new_node->previous = new_node;
        new_node->data = value;

    }else{

        list aux = head; // auxiliar pointer that points where the head was pointing

        /*
         * If the list has only one node , it is necessary to create the
         * basic structure of the circular doubly linked list
         */
        if ( count_nodes(head) == 1 ){

            aux->next = new_node;
            aux->previous = new_node;

            new_node->previous = aux;
            new_node->next = aux;
            new_node->data = value;
        }else{

            aux->previous = new_node; //makes the first node point to the new node

            // takes the last node of the list
            while( aux->next != head ){

                aux = aux->next;
            }

            aux->next = new_node;
            new_node->previous = aux;
            new_node->next = head;
            new_node->data = value;
        }

    }

    return head;
}

/**
 * Print the values of the data from each node of the list
 */
void print_list(list *head){

    list aux = head;
    list aux2 = head;
    if ( aux == NULL ){

        printf("empty list\n");

    }else{

        // print the value of the current and previous node and goes to the next one
        do{

            printf("Value = %d \n", aux->data);
            printf("Value = %d previous\n", aux->previous->data);

            aux = aux->next;

        }while( aux != head );

    }
}

/**
 * Count the number of nodes in a list
 * @param head is the list itself
 * @return number of nodes on the list
 */
int count_nodes(list *head){

    int number_of_nodes = 0;
    list aux = head; // auxiliar pointer

    // checks if the list is empty
    if ( head != NULL ){

        // goes through each node and add one to the counter variable
        do{

            aux = aux->next;
            number_of_nodes = number_of_nodes + 1;

        }while ( aux != head );

    }else{

        // Nothing to do
    }

    return number_of_nodes;

}

main(){

    list *head = create_list();

    print_list(head);

    //head = add_node_tale(head, 7);

    //head = add_node_head(head, 2);

    //head = add_node_tale(head, 7);

    //head = add_node_head(head, 3);

    //head = add_node_head(head, 4);

    //head = add_node_head(head, 5);

    //head = add_node_head(head, 6);

    head = add_node_tale(head, 8);

    head = add_node_tale(head, 9);

    head = add_node_tale(head, 1);

    int number_of_nodes = count_nodes(head);

    print_list(head);

    printf("Number of nodes = %d", number_of_nodes);

    //head = add_head(head, 4);

}
