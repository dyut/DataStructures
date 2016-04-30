#include<stdio.h>
#include<stdlib.h>
#include<dll.h>

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

int main(int argc, char* argv[])
{
	nodeDPtr head=NULL,temp;
	int i;
	complxPtr cn;
	if(argc < 3)
		return 0;
	head=create_node_dll((void *)create_complx(atof(argv[1]), atof(argv[2])));
	temp=head;
	for(i=3;i+1<argc;i+=2)
		temp=insert_after_dll(temp,create_node_dll((void *)create_complx(atof(argv[i]), atof(argv[i+1]))));
	print_list_dll(head,printVal);
	head=insert_before_dll(head,create_node_dll((void *)create_complx(19,2)));
	print_list_dll(head,printVal);
	cn = create_complx(19,2);
	delVal(delete_dll(&head,(void *)cn,compVal));
	free(cn);
	print_list_dll(head,printVal);
	cn = create_complx(4,0);
	delVal(delete_dll(&head,(void *)cn,compVal));
	print_list_dll(head,printVal);
	insert_before_dll(head->next->next,create_node_dll((void *)cn));
	print_list_dll(head,printVal);
	dispose_dll(&head,delVal);
	print_list_dll(head,printVal);
	return 0;
}
