/* sll.h
Header file for sll.h*/

#ifndef __SLL_H__
#define __SLL_H__ 


typedef struct nd *nodePtr;
typedef struct nd{
	void * val;
	nodePtr next;
}node;

nodePtr create_node_sll(void * v);
nodePtr insert_sll(nodePtr p, void * v);
void * delete_after_sll(nodePtr p);
void * delete_sll(nodePtr *phead, void * v, int (*comVal)(void *, void *));
void * delete_front_sll(nodePtr *phead);
void dispose_sll(nodePtr *phead,void (*delVal)(void *));
void print_list_sll(nodePtr head,void (*printVal)(void *));
nodePtr find_sll(nodePtr head, void * v, int (*comVal)(void *, void *));
void reverse_sll(nodePtr *phead);
void insert_front_sll(nodePtr *phead, nodePtr p);
void reverse_nonrecursive_sll(nodePtr *phead);

#endif
