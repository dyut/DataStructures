#ifndef __RED_BLACK_TREE_H
#define __RED_BLACK_TREE_H

enum color {
	RED,
	BLACK
};

typedef struct rb_node {
	enum color color;
	int key;
	struct rb_node *left;
	struct rb_node *right;
	struct rb_node *parent;
} rb_node_t;

rb_node_t *create_rb_node(int);
void left_rotate(rb_node_t **root, rb_node_t *x);
void right_rotate(rb_node_t **root, rb_node_t *x);
void insert(rb_node_t **root, rb_node_t *z);
void insert_fixup(rb_node_t **root, rb_node_t *z);
void inorder(rb_node_t *root);
void preorder(rb_node_t *root);
void postorder(rb_node_t *root);
rb_node_t *find_node(rb_node_t *root, int key);
rb_node_t *find_min(rb_node_t *root);
rb_node_t *find_max(rb_node_t *root);
void delete(rb_node_t **root, rb_node_t *z);
void delete_fixup(rb_node_t **root, rb_node_t *x);

#endif
