#include <stdio.h>
#include <stdlib.h>

#include "../inc/red_black_tree.h"

rb_node_t *create_rb_node(int key)
{
	rb_node_t *root;
	root = (rb_node_t *)malloc(sizeof(rb_node_t));
	root->color = RED;
	root->key = key;
	root->left = NULL;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	return root;
}

void left_rotate(rb_node_t **root, rb_node_t *x)
{
	rb_node_t *y = x->right;
	x->right = y->left;
	y->parent = x->parent;
	if (x->parent == NULL)
		*root = y;
	else if (x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;
		
	y->left = x;
	x->parent = y;
}

void right_rotate(rb_node_t **root, rb_node_t *x)
{
	rb_node_t *y = x->left;
	x->left = y->right;
	y->parent = x->parent;
	if (x->parent == NULL)
		*root = y;
	else if (x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;
		
	y->right = x;
	x->parent = y;
}

void insert(rb_node_t **root, rb_node_t *z)
{
	rb_node_t *x, *y;
	y = NULL;
	x = *root;
	while (x != NULL) {
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (!y)
		*root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

	insert_fixup(root, z);
}

void insert_fixup(rb_node_t **root, rb_node_t *z)
{
	rb_node_t *y;
	while (z->parent && z->parent->color == RED) {
		if (z->parent->parent->left == z->parent) {
			y = z->parent->parent->right;
			if (y && y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else {
				if (z->parent->right == z) {
					z = z->parent;
					left_rotate(root, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(root, z->parent->parent);
			}
		} else {
			y = z->parent->parent->left;
			if (y && y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else {
				if (z->parent->left == z) {
					z = z->parent;
					right_rotate(root, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(root, z->parent->parent);
			}
		}
	}
	(*root)->color = BLACK;
}

void inorder(rb_node_t *root)
{
	if (!root)
		return;
	inorder(root->left);
	printf("%d%s ", root->key, (root->color == RED ? "R" : "B"));
	inorder(root->right);
}

void preorder(rb_node_t *root)
{
	if (!root)
		return;
	printf("%d%s ", root->key, (root->color == RED ? "R" : "B"));
	preorder(root->left);
	preorder(root->right);
}

void postorder(rb_node_t *root)
{
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d%s ", root->key, (root->color == RED ? "R" : "B"));
}

rb_node_t *find_node(rb_node_t *root, int key)
{
	if (!root)
		return NULL;
	if (root->key == key)
		return root;
	if (key < root->key)
		return find_node(root->left, key);
	else
		return find_node(root->right, key);
}

rb_node_t *find_min(rb_node_t *root)
{
	if (!root)
		return NULL;
	while (root->left)
		root = root->left;
	return root;
}

rb_node_t *find_max(rb_node_t *root)
{
	if (!root)
		return NULL;
	while (root->right)
		root = root->right;
	return root;
}

void delete(rb_node_t **root, rb_node_t *z)
{	
	rb_node_t *y, *x;
	if (!z)
		return;
	if (!z->left || !z->right)
		y = z;
	else
		y = find_min(z->right);

	if (y->left)
		x = y->left;
	else
		x = y->right;

	if (x)
		x->parent = y->parent;
	if (!y->parent)
		*root = x;
	else if (y->parent->left == y)
		y->parent->left = x;
	else
		y->parent->right = x;
	
	if (y != z)
		z->key = y->key;
	if (x && y->color == BLACK)
		delete_fixup(root, x);
	free(y);
}

void delete_fixup(rb_node_t **root, rb_node_t *x)
{
	rb_node_t *w;
	while (x != *root && x->color == BLACK) {
		if (x == x->parent->left) {
			w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				left_rotate(root, x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->left->color == RED) {
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(root, w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				left_rotate(root, x->parent);
				x = *root;
			}
		} else {
			w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				right_rotate(root, x->parent);
				w = x->parent->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->right->color == RED) {
					w->right->color = BLACK;
					w->color = RED;
					left_rotate(root, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				right_rotate(root, x->parent);
				x = *root;
			}
		}
	}
	x->color = BLACK;
}

