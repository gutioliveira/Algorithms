/**
 *  Academic purpose only!
 *  author: Gustavo Cavalcante - University of Brasilia
 */

 #include <stdio.h>
 #include <stdlib.h>

typedef struct node node;

// Struct which represents a node of a FIFO
 struct node{

    int data;
    struct node *next;

 };

typedef struct fifo fifo;

// Contains two pointers which points to the beggining and the end of a FIFO.
struct fifo{

    struct node *beggining;
    struct node *end;

};

/**
 * Creates a new struct containing pointers to the beggining and end of a fifo.
 * @return returns the pointer created if it was successfully alocated.
 */
fifo *create_fifo(){

    fifo *pointer_to_fifo = (fifo*) malloc ( sizeof(fifo) );

    if ( pointer_to_fifo != NULL ){

        pointer_to_fifo->beggining = NULL;
        pointer_to_fifo->end = NULL;

    }else{

        return -1;
    }

    return pointer_to_fifo;
}

/**
 * Deletes every node of the fifo from the memory.
 * @param pointer_to_fifo is a struct that marks the beggining and ending of the fifo.
 */
void delete_fifo(fifo *pointer_to_fifo){

    // verifies if the fifo is vallid.
    if ( pointer_to_fifo->beggining != NULL ){

        // goes throught every node of the FIFO deallocating the mememory of that node
        while ( pointer_to_fifo->beggining != NULL ){

            node *Aux = pointer_to_fifo->beggining;
            pointer_to_fifo->beggining = pointer_to_fifo->beggining->next;

            free( Aux );
        }

        free( pointer_to_fifo );
    }else{

        printf("Couldn't delete the fifo because there is no fifo.\n");
    }

}

/**
 * Add a node to the end of the FIFO structure.
 * @param pointer_to_fifo is a pointer who points to the nodes of the fifo.
 * @param value_on_node is the value to be stored on the node recently created.
 */
void add_node_to_fifo( fifo *pointer_to_fifo , int value_on_node ){

    node *new_node = (node*) malloc (sizeof(node));

    // verifies if the pointer_to_fifo exists on memory
    if ( pointer_to_fifo != NULL ){

        // changes the pointer to beggining when there are no nodes on it.
        if ( pointer_to_fifo->beggining == NULL ){

            pointer_to_fifo->beggining = new_node;
            pointer_to_fifo->end = new_node;
        }else{

            // Nothing to do.
        }

        new_node->next = NULL;
        new_node->data = value_on_node;
        pointer_to_fifo->end->next = new_node;
        pointer_to_fifo->end = new_node;
    }else{

        printf("Fifo is not valid!\n");
    }

}
/**
 * Removes the first node of the fifo structure.
 * @param pointer_to_fifo is a pointer who points to the nodes of the fifo.
 */
void remove_node(fifo *pointer_to_fifo){

    // Checks if the pointer_to_fifo is correctly allocated.
    if ( pointer_to_fifo != NULL ){

        node *aux = pointer_to_fifo->beggining; // auxiliar pointer to the beggning of the fifo

        // Checks if the beggining is not empty
        if ( pointer_to_fifo->beggining != NULL ){

            pointer_to_fifo->beggining = pointer_to_fifo->beggining->next;
            free(aux);

            // If there is only one element on the FIFO , changes end pointer to NULL
            if ( pointer_to_fifo->beggining == NULL ){

                pointer_to_fifo->end = NULL;
            }else{

                // Nothing to do
            }

        }else{

            printf("FIFO is empty!\n");
        }

    }else{

        printf("Fifo is not valid!\n");
    }
}


main(){

    fifo *fifo_structure = create_fifo();

    add_node_to_fifo(fifo_structure , 3);

    printf("node = %d\n", fifo_structure->beggining->data );

    printf("node = %d\n", fifo_structure->end->data );

    add_node_to_fifo(fifo_structure , 4);

    add_node_to_fifo(fifo_structure , 5);

    printf("node = %d\n", fifo_structure->end->data );

    remove_node(fifo_structure);

    printf("node = %d\n", fifo_structure->beggining->data );

    printf("node = %d\n", fifo_structure->end->data );

}
