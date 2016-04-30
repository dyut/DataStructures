/* binTree.h
Header file for binTree.c which implements binary search tree */

#ifndef __BINTREE_H__
#define __BINTREE_H__

typedef struct bt *binTreePtr;
typedef struct bt{
	void * val;
	binTreePtr left;
	binTreePtr right;
	binTreePtr parent;
}binTreeNode;

binTreePtr create_node_bt(void * val);
void insert_bt(binTreePtr root, void * val, int (*comVal)(void *,void *));
binTreePtr getMin_bt(binTreePtr root);
binTreePtr getMax_bt(binTreePtr root);
binTreePtr getSuccessor_bt(binTreePtr root);
binTreePtr getPredecessor_bt(binTreePtr root);
void inorder_bt(binTreePtr root, void (*printVal)(void *));
void preorder_bt(binTreePtr root, void (*printVal)(void *));
void postorder_bt(binTreePtr root, void (*printVal)(void *));
binTreePtr search_bt(binTreePtr root, void * key, int (*comVal)(void *,void *));
void * delete_bt(binTreePtr *proot, binTreePtr x);
int height_bt(binTreePtr root);
int size_bt(binTreePtr root);
void dispose_bt(binTreePtr *proot, void (*delVal)(void *));
void mirror_bt(binTreePtr root);

#endif
