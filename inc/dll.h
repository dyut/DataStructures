/* dll.h
Header file for dll.c which implement doubly linked list */

#ifndef __DLL_H__
#define __DLL_H__

typedef struct ndD *nodeDPtr;
typedef struct ndD{
	void * val;
	nodeDPtr next;
	nodeDPtr prev;
}nodeD;

nodeDPtr create_node_dll(void * v);
nodeDPtr insert_after_dll(nodeDPtr p, nodeDPtr a);
nodeDPtr insert_before_dll(nodeDPtr p, nodeDPtr a);
void * delete_node_dll(nodeDPtr p);
void * delete_head_dll(nodeDPtr *phead);
void * delete_dll(nodeDPtr *phead, void * v, int (*comVal)(void *, void *));
void print_list_dll(nodeDPtr head, void (*printVal)(void *));
void dispose_dll(nodeDPtr *phead, void (*delVal)(void *));
nodeDPtr find_after_dll(nodeDPtr head, void * v, int (*comVal)(void *, void *));
nodeDPtr find_before_dll(nodeDPtr head, void * v, int (*comVal)(void *, void *));

#endif
