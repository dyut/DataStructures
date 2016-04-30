/* dll.c
This file implements double linked list data structure */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/dll.h"

/* create a node with value v */
nodeDPtr create_node_dll(void * v)
{
	nodeDPtr p = (nodeDPtr)malloc(sizeof(nodeD));
	if(p!=NULL)
	{
		p->val = v;
		p->next = NULL;
		p->prev = NULL;
	}
	return p;
}

/* insert a node with value v after p and return the pointer of the inserted node */ 
nodeDPtr insert_after_dll(nodeDPtr p, nodeDPtr a)
{
	if(!p)
		return a;
	if(a)
	{
		a->next=p->next;
		p->next=a;
		a->prev=p;
		if(a->next)
			a->next->prev=a;
	}
	return a;
}

/* insert a node with value v before p and return the pointer of the inserted node */ 
nodeDPtr insert_before_dll(nodeDPtr p, nodeDPtr a)
{
	if(!p)
		return a;
	if(a)
	{
		a->prev=p->prev;
		p->prev=a;
		a->next=p;
		if(a->prev)
			a->prev->next=a;
	}
	return a;
}

/* find a node with value v from head onwards */ 
nodeDPtr find_after_dll(nodeDPtr head, void * v, int (*comVal)(void *, void *))
{
	nodeDPtr temp;
	for(temp=head;temp && comVal(temp->val,v); temp=temp->next) ;
	return temp;
}

/* find a node with value v from head backwards */ 
nodeDPtr find_before_dll(nodeDPtr head, void * v, int (*comVal)(void *, void *))
{
	nodeDPtr temp;
	for(temp=head;temp && comVal(temp->val,v); temp=temp->prev) ;
	return temp;
}

/* delete the node p */
void * delete_node_dll(nodeDPtr p)
{
	void * v = NULL;
	if(!p)
		return v;
	if(p->prev)
		p->prev->next = p->next;
	if(p->next)
		p->next->prev = p->prev;
	v = p->val;
	free(p);
	return v;
}

/* delete the head node of the list */
void * delete_head_dll(nodeDPtr *phead)
{
	void * v = NULL;
	nodeDPtr temp = *phead;
	if(*phead){
		*phead=(*phead)->next;
		(*phead)->prev=NULL;
		v = temp->val;
	}
	free(temp);
	return v;
}

/* delete the first node after head with value v */
void * delete_dll(nodeDPtr *phead, void * v, int (*comVal)(void *, void *))
{
	nodeDPtr temp;
	if(!(*phead))
		return NULL;
	temp = find_after_dll(*phead,v,comVal);
	if(temp == *phead)
		return delete_head_dll(phead);
	else
		return delete_node_dll(temp);
}

/* print the list */
void print_list_dll(nodeDPtr head, void (*printVal)(void *))
{
	while(head)
	{
		printVal(head->val);
		head = head->next;
	}
	printf("\n");
}

/* dispose the list recursively, internally called by dispose_dll */
static void disp_dll(nodeDPtr head, void (*delVal)(void *))
{
	if(!head)
		return;
	if(head->next)
		disp_dll(head->next,delVal);
	delVal(head->val);
	free(head);
}

/* dispose the list */
void dispose_dll(nodeDPtr *phead, void (*delVal)(void *))
{
	disp_dll(*phead,delVal);
	*phead = NULL;
}
