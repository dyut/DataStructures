/* stack.h
Header file for stack.c which implements stack data structure */

#include"sll.h"

#ifndef __STACK_H__
#define __STACK_H__

typedef struct s{
	int size;
	nodePtr top;
}stack;
typedef stack *stackPtr;

stackPtr create_stack();
void push(stackPtr st, void * v);
void * pop(stackPtr st);
void * top(stackPtr st);
int size_stack(stackPtr st);
int is_empty_stack(stackPtr st);
void print_stack(stackPtr st, void (*printVal)(void *));
void dispose_stack(stackPtr st, void (*delVal)(void *));

#endif
