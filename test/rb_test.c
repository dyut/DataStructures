#include <stdlib.h>
#include <stdio.h>
#include <red_black_tree.h>

int main(int argc, char *argv[])
{
	int i;
	rb_node_t *root = NULL, *temp;
	if (argc < 2)
		perror ("not enough parameters!\n");
	for (i=1; i < argc; i++)
		insert(&root, create_rb_node(atoi(argv[i])));
	printf("Preorder:\n");
	preorder(root);
	printf("\nInorder:\n");
	inorder(root);
	printf("\n");

	do {
		printf("Enter the value to be deleted : ");
		scanf("%d", &i);
		temp = find_node(root, i);
		if (!temp)
			break;
		delete(&root, temp);
		printf("Preorder:\n");
		preorder(root);
		printf("\nInorder:\n");
		inorder(root);
		printf("\n");
	} while (root);
	return 0;
}
