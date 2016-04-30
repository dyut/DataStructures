/* sll.c
This file implements single linked list data structure */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/sll.h"

/* function to create a node with value v
return - the pointer of the created node on success and NULL on failure */
nodePtr create_node_sll(void * v)
{
	nodePtr p = (nodePtr)malloc(sizeof(node));
	if(p!=NULL){
		p->val = v;
		p->next = NULL;
	}
	return p;
}

/* function to insert a node with value v after p
return pointer to the inserted node, NULL on failure to create node */
nodePtr insert_sll(nodePtr p, void * v)
{
	nodePtr a = create_node_sll(v);
	if(!p)
		return a;
	if(a)
	{
		a->next=p->next;
		p->next=a;
	}
	return a;
}

/* function to find a node with value v in the linked list starting from head
return - pointer to the node if found, NULL otherwise */
nodePtr find_sll(nodePtr head, void * v, int (*comVal)(void *, void *))
{
	nodePtr temp;
	for(temp=head;temp && comVal(temp->val,v); temp=temp->next) ;
	return temp;
}

/* function to delete the node after p */
void * delete_after_sll(nodePtr p)
{
	nodePtr temp;
	void * v = NULL;
	if(!p)
		return v;
	if(p->next)
	{
		temp = p->next;
		p->next=p->next->next;
		v = temp->val;
		free(temp);
	}
	return v;
}

/* delete the first node in the lined list starting with head, with value v */
void * delete_sll(nodePtr *phead, void * v , int (*comVal)(void *, void *))
{
	nodePtr temp;
	void * v1 = NULL;
	if(!*phead)
		return v1;
	temp=*phead;
	if(!comVal((*phead)->val,v))
	{
		*phead=(*phead)->next;
		v1 = temp->val;
		free(temp);
		return v1;
	}
	while(temp->next && comVal(temp->next->val,v))
		temp = temp->next;
	return delete_after_sll(temp);		
}

/* delete the first node in the lined list */
void * delete_front_sll(nodePtr *phead)
{
	nodePtr temp=*phead;
	void * v = NULL;
	if(!*phead)
		return v;
	*phead=(*phead)->next;
	v = temp->val;
	free(temp);
	return v;
}

/* insert p in front of the first node in the lined list */
void insert_front_sll(nodePtr *phead, nodePtr p)
{
	nodePtr temp=*phead;
	if(p)
	{
		*phead=p;
		p->next=temp;
	}
}

/* function to print the linked list */
void print_list_sll(nodePtr head,void (*printVal)(void *))
{
	while(head)
	{
		printVal(head->val);
		head = head->next;
	}
	printf("\n");
}

/* function(recursive) to delete the linked list starting with head
This is an internal function called by dispose_sll(nodePtr *phead) */
static void disp_sll(nodePtr head,void (*delVal)(void *))
{
	if(!head)
		return;
	if(head->next)
		disp_sll(head->next,delVal);
	delVal(head->val);
	free(head);
}

/* function to delete the linked list starting with head */
void dispose_sll(nodePtr *phead,void (*delVal)(void *))
{
	disp_sll(*phead,delVal);
	*phead = NULL;
}

/* function(recursive) to reverse the linked list */
static nodePtr rev_sll(nodePtr temp, nodePtr *phead)
{
	if(temp->next == NULL)
	{
		*phead = temp;
		return temp;
	}
	rev_sll(temp->next,phead)->next = temp;
	temp->next = NULL;
	return temp;
}

/* function to reverse linked list */
void reverse_sll(nodePtr *phead)
{
	if(*phead == NULL)
		return;
	rev_sll(*phead,phead);
}

/* function to reverse linked list(non-recursive) */
void reverse_nonrecursive_sll(nodePtr *phead)
{
	nodePtr temp1,temp2=NULL;
	if(*phead == NULL)
		return;
	temp1=NULL;
	if(*phead)
		temp2=(*phead)->next;
	while(temp2)
	{
		(*phead)->next=temp1;
		temp1=*phead;
		*phead=temp2;
		temp2=temp2->next;
	}
	(*phead)->next=temp1;
}

