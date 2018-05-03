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
struct s_elem
{
	// TODO: One element of a stack consists of a name, an integer index and a pointer to the element under this one (predecessor)
};

Stack* stack_new()
{
	//TODO
	return NULL;
}

s_elem* s_elem_new(char* name)
{
	//TODO
	return NULL;
}

void stack_free(Stack *stack)
{
	//TODO
	return;
}

char* stack_push(Stack *stack, s_elem* newElem)
{
  //TODO
	return NULL;
}

char* stack_peek(Stack *stack)
{
	//TODO
	return NULL;
}

void stack_pop(Stack *stack, char **name)
{
	//TODO
	return;
}

int stack_size(Stack *stack){
	//TODO
  return stack->size;
}

void stack_print(Stack *stack)
{
 	//TODO
  return;
}
/* End of assignment -------------------------------------------------------------------------- */
