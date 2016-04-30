/* binTree.c
implements binary search tree*/

#include <stdlib.h>
#include <stdio.h>
#include "../inc/binTree.h"

/* create a node with value v */
binTreePtr create_node_bt(void * v)
{
	binTreePtr temp = (binTreePtr)malloc(sizeof(binTreeNode));
	if(temp)
	{
		temp->val=v;
		temp->left = temp->right = temp->parent = NULL;
	}
	return temp;
}

/* insert a node with value v in the bst rooted with root */
void insert_bt(binTreePtr root, void * v, int (*comVal)(void *,void *))
{
	if(!root){
		root = create_node_bt(v);
		return;
	}
	if(comVal(v,root->val) < 0)
	{
		if(root->left)
			insert_bt(root->left,v,comVal);
		else{
			root->left = create_node_bt(v);
			root->left->parent = root;
		}
	}else{
		if(root->right)
			insert_bt(root->right,v,comVal);
		else{
			root->right = create_node_bt(v);
			root->right->parent = root;
		}
	}
}

/* get the node in the bst rooted with root with minimum value */
binTreePtr getMin_bt(binTreePtr root)
{
	if(!root)
		return NULL;
	while(root->left)
		root = root->left;
	return root;
}

/* get the node in the bst rooted with root with maximum value */
binTreePtr getMax_bt(binTreePtr root)
{
	if(!root)
		return NULL;
	while(root->right)
		root = root->right;
	return root;
}

/* get the successor node of the node root */
binTreePtr getSuccessor_bt(binTreePtr root)
{
	binTreePtr temp;
	if(!root)
		return NULL;
	if(root->right)
		return getMin_bt(root->right);
		
	temp=root->parent;
	while(temp && temp->right==root)
	{
		root = temp;
		temp = root->parent;
	}
	return temp;
}

/* get the predecessor node of the node root */
binTreePtr getPredecessor_bt(binTreePtr root)
{
	binTreePtr temp;
	if(!root)
		return NULL;
	if(root->left)
		return getMax_bt(root->left);
	
	temp=root->parent;
	while(temp && temp->left==root)
	{
		root = temp;
		temp = root->parent;
	}
	return temp;
}

/* print node value in inorder sequence of the bst rooted with tree */
void inorder_bt(binTreePtr root, void (*printVal)(void *))
{
	if(root)
	{
		inorder_bt(root->left,printVal);
		printVal(root->val);
		inorder_bt(root->right,printVal);
	}
}

/* print node preorder value in sequence of the bst rooted with tree */
void preorder_bt(binTreePtr root, void (*printVal)(void *))
{
	if(root)
	{
		printVal(root->val);
		preorder_bt(root->left,printVal);
		preorder_bt(root->right,printVal);
	}
}

/* print node value in postorder sequence of the bst rooted with tree */
void postorder_bt(binTreePtr root, void (*printVal)(void *))
{
	if(root)
	{
		postorder_bt(root->left,printVal);
		postorder_bt(root->right,printVal);
		printVal(root->val);
	}
}

/* search the node with value v in the bst rooted with tree */
binTreePtr search_bt(binTreePtr root, void * key, int (*comVal)(void *,void *))
{
	while(1)
	{
		if(root && comVal(key,root->val) < 0)
			root = root->left;
		else if(root && comVal(key,root->val) > 0)
			root = root->right;
		else
			return root;
	}
}

/* delete the node x from bst rooted with *proot */ 
void * delete_bt(binTreePtr *proot, binTreePtr x)
{
	binTreePtr temp,y;
	void * v = NULL;
	/* if x has both the child keep the successor of x, which can't have
		left child, in temp; otherwise put x itself in temp which actually 
		will be  deleted */
	if(!x)
		return v;
	if(x->left && x->right)
		temp = getSuccessor_bt(x);
	else
		temp = x;
	
	/* temp has at most one child, keep the non NULL child in y, if it exists;
		otherwise, y is NULL */
	if(temp->left)
		y=temp->left;
	else
		y=temp->right;
	
	if(y)	/* if temp has one child, make the child's parent to parent of temp's parent */
		y->parent=temp->parent;
	if(!temp->parent)	/* if temp is root, i.e. temp's parent is NULL make y the root of the bst */
		*proot = y;
	else if(y->parent->left == temp) /* make y as the child of y's parent */
		y->parent->left = y;
	else
		y->parent->right = y;
		
	if(temp != x) /* if temp is different from x, exchange their data */
	{
		v = x->val;
		x->val=temp->val;
	}else
		v = x->val;
		
	free(temp);
	return v;
}

/*-----------------------------------------------------*/

/* return height of the bst rooted with root */
int height_bt(binTreePtr root)
{
	if(root)
	{
		int leftheight = height_bt(root->left), rightheight = height_bt(root->right);
		return 1 + ((leftheight>rightheight) ? leftheight : rightheight);
	}
	return 0;
}

/* return size of the bst rooted with root */
int size_bt(binTreePtr root)
{
	if(root)
	{
		return 1 + size_bt(root->left) + size_bt(root->right);
	}
	return 0;
}

/* dispose the bst rooted with root */
void dispose_bt(binTreePtr *proot, void (*delVal)(void *))
{
	if(!(*proot))
		return;
	dispose_bt(&((*proot)->left),delVal);
	dispose_bt(&((*proot)->right),delVal);
	delVal((*proot)->val);
	free(*proot);
	*proot = NULL;
}

/* make the bst rooted with root mirror reflected */
void mirror_bt(binTreePtr root)
{
	if(root)
	{
		binTreePtr temp;
		mirror_bt(root->left); mirror_bt(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}
