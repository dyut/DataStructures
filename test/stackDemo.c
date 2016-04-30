#include<stdio.h>
#include<stdlib.h>
#include<stack.h>

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
	stackPtr st=create_stack();
	int i;
	if(argc < 2)
		return 0;
	for(i=1;i+1<argc;i+=2)
		push(st,(void *)create_complx(atof(argv[i]),atof(argv[i+1])));
	print_stack(st,printVal);
	printf("Pop : ");	printVal(pop(st)); printf("Size : %d\n",size_stack(st));
	print_stack(st,printVal);
	printf("Top : ");	printVal(top(st)); printf("Size : %d\n",size_stack(st));
	print_stack(st,printVal);
	dispose_stack(st,delVal);
	print_stack(st,printVal);
	return 0;
}
