/* queue.c
This file implements queue DS with single linked liqt */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/queue.h"

/* create queue */
queuePtr create_queue()
{
	queuePtr qt=(queuePtr)malloc(sizeof(queue));
	if(qt)
	{
		qt->size=0;
		qt->head=NULL;
		qt->tail=NULL;
 	}
	return qt;
}

/*enqueue v at the end of queue qt */
void enqueue(queuePtr qt, void * v)
{	
	nodePtr temp=insert_sll(qt->tail,v);
	if(temp)
	{
		qt->tail=temp;
		if(!qt->size) /* if queue was empty earlier, 
					now it has 1 element, so, head=tail */
			qt->head=qt->tail;
		(qt->size)++;
	}
}

/*  dequeue the first element from the queue qt */
void * dequeue(queuePtr qt)
{
	if(qt->size)
	{
		(qt->size)--;
		return delete_front_sll(&(qt->head));
	}else{
		perror("Empty queue");
		exit(1);
	}
}

/* return the first element from the queue qt */
void * first(queuePtr qt)
{
	if(qt->size)
		return qt->head->val;
	else{
		perror("Empty queue");
		exit(1);
	}
}

/* return the first element from the queue qt */
void * last(queuePtr qt)
{
	if(qt->size)
		return qt->tail->val;
	else{
		perror("Empty queue");
		exit(1);
	}
}

/* return size of the queue qt */
int size_queue(queuePtr qt)
{
	return qt->size;
}

/* return nonzero if qt is empty; otherwise return zero */
int is_empty_queue(queuePtr qt)
{
	return 0==qt->size;
}

/* print the queue qt top to down */
void print_queue(queuePtr qt, void (*printVal)(void *))
{
	print_list_sll(qt->head, printVal);
}

/* dispose queue */
void dispose_queue(queuePtr qt, void (*delVal)(void *))
{
	dispose_sll(&(qt->head), delVal);
}
