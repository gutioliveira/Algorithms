#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define TOP (lifo_structure->top - 1)

typedef struct lifo lifo;

struct lifo{

    int top;
    int data[MAX];

};

/**
 * Creates a new LIFO structure and returns it.
 */
lifo *create_lifo(){

    lifo *new_lifo = (lifo*) malloc (sizeof(lifo));

    // checks if the lifo was successfully alocated
    if (new_lifo != NULL){

        new_lifo->top = 0;
    }else{

        return NULL;
    }

    return new_lifo;
}

/**
 * Verifies if a static lifo is full or not.
 * @param lifo_structure is the lifo itself.
 * @return returns 1 if it is full or 0 if not.
 */
int is_lifo_full(lifo *lifo_structure){

    if ( lifo_structure->top == MAX ){

        return 1;
    }else{

        return 0;
    }
}

/**
 * Verifies if a static lifo is empty or not.
 * @param lifo_structure is the lifo itself.
 * @return returns 1 if it is empty or 0 if not.
 */
int is_lifo_empty(lifo *lifo_structure){

    if ( lifo_structure->top == 0 ){

        return 1;
    }else{

        return 0;
    }

}

/**
 * Consult the top of the lifo structure
 * @param lifo_structure is the lifo itself.
 * @return returns the value of the node on the top , or -1 if the structure is not valid.
 */
int consult_lifo(lifo *lifo_structure){

    if ( lifo_structure != NULL && !is_lifo_empty(lifo_structure) ){

        return lifo_structure->data[TOP];
    }else{

        return -1;
    }

}

/**
 * Removes the node on top of the lifo.
 * @param lifo_structure is the lifo itself.
 */
void remove_node_lifo(lifo *lifo_structure){

    if ( lifo_structure != NULL && lifo_structure->top != 0 ){

        printf("Lifo is not valid!\n");
    }else{

        lifo_structure->top = lifo_structure->top - 1;
    }

}
/**
 * Add an information to the node on the top of a lifo structure.
 * @param lifo_structure is the lifo itself , value is the information to be stored.
 */
void add_node_lifo(lifo *lifo_structure , int value){

    if ( lifo_structure != NULL && !is_lifo_full(lifo_structure) ){

        lifo_structure->data[lifo_structure->top] = value;
        lifo_structure->top = lifo_structure->top + 1;
    }else{

        printf("Lifo is not valid or lifo is full!\n");
    }

}

main(){

    lifo *li = create_lifo();

    add_node_lifo(li, 1);

    add_node_lifo(li, 2);

    add_node_lifo(li, 3);

    add_node_lifo(li, 4);

    add_node_lifo(li, 5);

    add_node_lifo(li, 6);

    add_node_lifo(li, 7);

    add_node_lifo(li, 8);

    add_node_lifo(li, 9);

    add_node_lifo(li, 0);

    add_node_lifo(li, 0);

}
