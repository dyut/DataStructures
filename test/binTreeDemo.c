#include <stdio.h>
#include <stdlib.h>
#include <binTree.h>

typedef struct c{
	double real;
	double comp;
}complx;

typedef complx *complxPtr;
void delVal(void * v)
{
	free(v);
}

void printVal(void *v)
{
	printf("%g + i%g\n",((complxPtr)v)->real,((complxPtr)v)->comp);
}

int compVal(void *v1, void *v2)
{
	if(((complxPtr)v1)->real - ((complxPtr)v2)->real)
		return ((complxPtr)v1)->real - ((complxPtr)v2)->real;
	return ((complxPtr)v1)->comp - ((complxPtr)v2)->comp;
}

complxPtr create_complx(double r, double c)
{
	complxPtr cn = (complxPtr)malloc(sizeof(complx));
	if(!cn){
		perror("Memory allocation error!\n");
		exit(1);
	}
	cn->real=r;
	cn->comp=c;
	return cn;
}

int main (int argc, char *argv[])
{
	int i;
	if(argc<2)
		exit(0);
		
	binTreePtr temp,root = create_node_bt((void *)create_complx(atof(argv[1]),atof(argv[2])));
	for(i=3;i+1<argc;i+=2)
		insert_bt(root,(void *)create_complx(atof(argv[i]),atof(argv[i+1])),compVal);

	preorder_bt(root,printVal);	putchar('\n'); inorder_bt(root,printVal);	putchar('\n');
	printf("Height = %d\n",height_bt(root));
	printf("Size = %d\n",size_bt(root));
	temp = search_bt(root,(void *)create_complx(3,5),compVal);	delVal(delete_bt(&root,temp));	
	preorder_bt(root,printVal);	putchar('\n'); inorder_bt(root,printVal);	putchar('\n');
	printf("Height = %d\n",height_bt(root));
	printf("Size = %d\n",size_bt(root));
	printVal(getMin_bt(root)->val);putchar('\n');
	mirror_bt(root); 
	preorder_bt(root,printVal); putchar('\n'); inorder_bt(root,printVal);	putchar('\n');
	dispose_bt(&root,delVal);	preorder_bt(root,printVal); putchar('\n'); inorder_bt(root,printVal);	putchar('\n');

	return 0;
}
