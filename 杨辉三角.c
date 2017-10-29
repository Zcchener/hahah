#include<stdio.h> 
#include<malloc.h>
#define maxsize  1000
typedef int Qelemtype;
typedef struct{
	Qelemtype data[maxsize];
	int front;
	int rear;
}Squeue;
Squeue *Initqueue()
{
	Squeue *Q;
	Q=(Squeue*)malloc(sizeof(Squeue));
	Q->front=0;
	Q->rear=0;
	return Q;	
}
EnQueue(Squeue*Q,int e)
{
	if((Q->rear+1)%maxsize==Q->front)
	return 1;
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%maxsize;
	return 0;
}
int Outqueue(Squeue *Q,int *e)
{   
	if(Q->front==Q->rear)
	return 1;
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%maxsize;
	return e;
}
Print_triangle(int n)
{   
    Squeue  *Q;
    int  i,j,k;
    int e;
    Q=Initqueue();
	EnQueue(Q,0);
	EnQueue(Q,1);
	printf("1\n");
	for(i=2;i<=n;i++)
	{
		EnQueue(Q,0);
		for(j=1;j<=i;j++)
		{
		Outqueue(Q,&e);
		e+=(Q->data[Q->front]);	
		EnQueue(Q,e);	
		printf("%d ",e);			
		}	
	printf("\n");
	}	
}
main()
{
	int n;
	scanf("%d",&n);
	Print_triangle(n);
	return 0;
}


