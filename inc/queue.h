/* queue.h
Header file for queue.c which implements queue data qtructure */

#include"sll.h"

#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct q{
	int size;
	nodePtr head;
	nodePtr tail;
}queue;
typedef queue *queuePtr;

queuePtr create_queue();
void enqueue(queuePtr qt, void * v);
void * dequeue(queuePtr qt);
void * last(queuePtr qt);
void * first(queuePtr qt);
int size_queue(queuePtr qt);
int is_empty_queue(queuePtr qt);
void print_queue(queuePtr qt, void (*printVal)(void *));
void dispose_queue(queuePtr qt, void (*delVal)(void *));

#endif
