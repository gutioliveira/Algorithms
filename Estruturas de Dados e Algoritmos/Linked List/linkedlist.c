/**
 *  Academic purpose only!
 *  author: Gustavo Cavalcante - University of Brasilia
 */

#include <stdio.h>

typedef struct list *list; // pointer to struct list type

struct list{

    int data; // data part of the struct , could be any type.
    list next;

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
 * Create a new node and make the last node point to it
 * @param head is the list itself
 * @param value is what the data of the node will receive
 * @return returns the head with a new node on the end.
 */
list add_node_tale( list *head , int value ){

    list new_node = (list*) malloc ( sizeof(list) );

    // auxiliar variables
    list aux = head;
    list before = aux;

    // if the list is empty, a node will be added on the beggining.
    if ( aux == NULL ){

        new_node->next = NULL;
        new_node->data = value;

        head = new_node;

    }else{

        // goes through the list until finds the last node.
        while ( aux != NULL ){

            before = aux;
            aux = aux->next;

        }

        before->next = new_node;
        new_node->next = NULL;
        new_node->data = value;

    }

    return head;

}
/**
 * Create a new node and makes the head point to it.
 * @param head is the list itself
 * @param value is what the data of the node will receive
 * @return returns the head with a new node on it.
 */
list add_node_head(list *head , int value){

    list new_node = (list*) malloc ( sizeof(list) );

    // checks if the list is empty;
    if ( head == NULL ){

        new_node->next = NULL;
        new_node->data = value;

        head = new_node;

    }else{

        list *aux = head;

        new_node->next = aux;
        new_node->data = value;

        head = new_node;

    }

    return head;

}

/**
 * Print the values of the data from each node of the list
 */
void print_list(list *head){

    // auxiliar pointer to not change the tree permanently
    list aux = head;

    // goes through every node of the list printing the value on it.
    while ( aux != NULL ){

        printf("Value = %d\n", aux->data);

        aux = (aux)->next;
    }

}
/**
 * Removes a node from the list who matches a key
 * @param head is the head of the list, and key is the value to be found on it.
 * @return returns null if the list is empty or returns the list without a node if the key was found.
 */
list remove_by_key(list *head ,const int key){

    // auxiliars variables
    list aux = head;
    list before = aux;
    int counter = 0;

    // if is passed a empty list, don't execute the rest of the funciton
    if ( head == NULL )
        return NULL;

    // goes through the list and stops if the key is found or the list's end.
    while ( aux->next != NULL ){

        if ( aux->data == key ){

            break;
        }else{

            counter++;
            before = aux;
            aux = aux->next;
        }
    }

    // if the key is on the first node , it is necessary to change where the head is pointing
    if ( counter == 0 ){

        free(aux);
        head = aux->next;
    }else if ( aux->data == key ){

        before->next = aux->next; //changes the pointer to next one
        free(aux);
    }else{

        printf("key not found!\n");
    }

    return head;

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

        }while ( aux != NULL );

    }else{

        // Nothing to do
    }

    return number_of_nodes;

}

main(){

    list *head = create_list();

    head = add_node_head(head , 5);

    head = add_node_head(head , 3);

    head = add_node_head(head , 2);

    head = add_node_tale(head , 9);

    head = add_node_tale(head , 10);

    head = add_node_head(head , 6);

    head = add_node_tale(head , 11);

    head = add_node_tale(head , 11);

    head = add_node_tale(head , 12);

    head = remove_by_key(head, 12);

    head = add_node_tale(head , 12);

    list aux = (list*) malloc ( sizeof(list) );

    aux = head;

    print_list(head);

}
