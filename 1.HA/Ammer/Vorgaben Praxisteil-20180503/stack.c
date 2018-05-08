#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int size;
	s_elem *head;
};
/* Beginning of assignment -------------------------------------------------------------------------- */


// Structure to create a new element with following specifications:
// 1) name (Array of char's).
// 2) index (int).
// 3) s_elem *pre_elem (pointer to the predecessor from the same type).
struct s_elem
{
    char *name;
    int index;
    s_elem *pre_elem;
};


// stack_new Function to create a new empty stack with following specifications: (Returns a new stack)
// 1) Created using the structure Stack which is listed above and through using malloc to allocate memory for the new stack.
// 2) Size which is initialized with 0 because the stack is empty at the beginning.
// 3) The head pointer points to NULL because the stack is empty at the beginning.
Stack* stack_new()
{
    struct Stack *astack = malloc(sizeof(struct Stack));
    astack->size = 0;
    astack->head = NULL;
	return astack;
}


// s_elem_new Function to create a new element which will be added to the stack later on that have following specifications: (Returns a new element)
// 1) Created using the structure s_elem which is listed above and through using malloc to allocate memory for the new stack.
// 2) name which is passed as input to the function.
// 3) index which is initialized with 0 at the beginning because the element is not pushed into the stack yet.
// 4) predecessor pointer which is initialized with NULL because the element is not pushed into the stack yet.
s_elem* s_elem_new(char* name)
{
    struct s_elem *new_elem = malloc(sizeof(struct s_elem));
    new_elem->name = name;
    new_elem->index = 0;
    new_elem->pre_elem = NULL;
    return new_elem;
}


void stack_free(Stack *stack)
{
    struct s_elem *current = stack->head;
    struct s_elem *prev;

    while(current != NULL){
        prev = current;
        current = current->pre_elem;
        free(prev);
    }
    free(stack);
}


// stack_push Function which takes a Stack and an element and pushes the given element to the top of the stack according to the FILO concept.
char* stack_push(Stack *stack, s_elem* newElem)
{
    // if the element is NULL return NULL to avoid a segmentation fault.
    if(newElem == NULL){
        return NULL;
    }
    // if the stack is empty add the element to the top (index 0) and point the head pointer onto it
    // + increment the size of the stack.
    if(stack->size == 0){
        newElem->pre_elem = NULL;
        newElem->index = 0;
        stack->head = newElem;
        stack->size = stack->size + 1;
        return newElem->name;
    // if the stack is not empty push the new element to the top and point the head pointer onto it
    // + adjust the pre_elem pointer of the previous element to the new element
    // + increment the size of the stack
    }else{
        newElem->index = stack->head->index + 1;
        newElem->pre_elem = stack->head;
        stack->head = newElem;
        //stack->head->pre_elem = newElem;
        stack->size = stack->size + 1;
        return newElem->name;
    }
}


// stack_peek Function which returns the name of the top element in the stack.
char* stack_peek(Stack *stack)
{
	if(stack->size == 0){
        return NULL;
	}else{
	    return stack->head->name;
	}
}


void stack_pop(Stack *stack, char **name)
{

	return;
}

int stack_size(Stack *stack){
  return stack->size;
}

void stack_print(Stack *stack)
{
    struct s_elem *elem = stack->head;

    while(elem != NULL){
        printf("Name: %s \t Index: %d\n", elem->name, elem->index);
        elem = elem->pre_elem;
    }
}
/* End of assignment -------------------------------------------------------------------------- s_elem *elem = stack->head->pre_elem;
    while(elem != NULL){
        printf("Name: %s \t Index: %d", elem->name, elem->index);
        elem = elem->pre_elem;
    }*/