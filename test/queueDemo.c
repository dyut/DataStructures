#include<stdio.h>
#include<stdlib.h>
#include<queue.h>

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
	queuePtr qt=create_queue();
	int i;
	if(argc < 2)
		return 0;
	for(i=1;i+1<argc;i+=2)
		enqueue(qt,(void *)create_complx(atof(argv[i]),atof(argv[i+1])));
	print_queue(qt,printVal);
	printf("Dequeue : \n"); printVal(dequeue(qt)); printf("Size : %d\n",size_queue(qt));
	print_queue(qt,printVal);
	printf("Dequeue : \n"); printVal(first(qt)); printf("Size : %d\n",size_queue(qt));
	print_queue(qt,printVal);
	printf("Dequeue : \n"); printVal(last(qt)); printf("Size : %d\n",size_queue(qt));
	print_queue(qt,printVal);
	dispose_queue(qt,delVal);
	print_queue(qt,printVal);
	return 0;
}
