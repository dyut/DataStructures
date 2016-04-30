/* stack.c
This file implements stack DS with single linked list */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/stack.h"

/* create stack */
stackPtr create_stack()
{
	stackPtr st=(stackPtr)malloc(sizeof(stack));
	if(st)
	{
		st->size=0;
		st->top=NULL;
 	}
	return st;
}

/*push v into stack st */
void push(stackPtr st, void * v)
{	
	nodePtr temp=create_node_sll(v);
	if(temp)
	{
		insert_front_sll(&(st->top),temp);
		(st->size)++;
	}
}

/* pop the top from the stack st and return the poped value */
void * pop(stackPtr st)
{
	if(st->size)
	{
		(st->size)--;
		return delete_front_sll(&(st->top));
	}else{
		perror("Empty stack");
		exit(1);
	}
}

/* return the top value from the stack st */
void * top(stackPtr st)
{
	if(st->size)
		return st->top->val;
	else{
		perror("Empty stack");
		exit(1);
	}
}

/* return size of the stack st */
int size_stack(stackPtr st)
{
	return st->size;
}

/* return nonzero if st is empty; otherwise return zero */
int is_empty_stack(stackPtr st)
{
	return 0==st->size;
}

/* print the stack st top to down */
void print_stack(stackPtr st, void (*printVal)(void *))
{
	print_list_sll(st->top,printVal);
}

/* dispose stack */
void dispose_stack(stackPtr st, void (*delVal)(void *))
{
	dispose_sll(&(st->top),delVal);
}
