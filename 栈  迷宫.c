#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define maxsize 100
typedef struct{
   int x;
   int y;	
   int  f;
}coordinate;
typedef struct
{
	coordinate data[maxsize];
	int top;
}Sqstack;

int m,n;
int a[20][20]={{0,0,1,0,1},
			   {0,0,0,0,0},
			   {0,1,1,1,1},
			   {0,0,0,0,0}};
int book[20][20];
Sqstack *InitStack()
{
  	Sqstack *s;
  	s=(Sqstack *)malloc(sizeof(Sqstack));
  	s->top=-1;
	return s;	
}

int Push(Sqstack *s,coordinate e)
{
	if(s->top==maxsize-1)  
	return 1;
	s->top++;
	s->data[s->top]=e;
	return 0;	
}

int Pop(Sqstack *s,coordinate *e)
{
	if(s->top==-1)  
		return 1;
	*e=s->data[s->top];
	s->top--;
	return 0;
}
Sqstack *s;
void Route(coordinate e)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//右下左上
	coordinate e1,e2;
	int k;
	e1=e;
	e1.f =0; 
	while(e2.x!=m-1||e2.y!=n-1)
	{
		for(k=e1.f;k<4;k++)
		{
			e2.x = e1.x + next[k][0];
			e2.y = e1.y + next[k][1];
			e1.f=k; 
			if(e2.x>=0&&e2.y>=0&&e2.x<m&&e2.y<n&&book[e2.x][e2.y]==0&&a[e2.x][e2.y]==0)
			{
				Push(s,e1);
				printf("进栈(%d,%d,%d)\n",e1.x,e1.y,e1.f); 
				//getchar();
				book[e1.x][e1.y]=1;
				e1=e2;//更新e1 
				e1.f=0; 
				break;	  
			} 
		} 
		if(k==4){
			Pop(s,&e1);//更新e1 
			printf("出栈(%d,%d,%d)\n",e1.x,e1.y,e1.f); 
			book[e1.x][e1.y]=0; 
			e1.f++; 
		} 
	}
	Push(s,e1);
	int i; 
	for(i=0;i<s->top+1;i++){
		printf("(%d,%d,%d)\n",s->data[i].x,s->data[i].y,s->data[i].f);
	} 
}
main()
{
	coordinate e;
	s=InitStack();
	e.x=0;
	e.y=0;
	e.f=0;
	book[0][0]=1;
	m=4,n=5;
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=0;i<n;i++){
		getchar();
		for(j=0;j<m;j++){
	    	scanf("%c",&a[i][j]);
		}
	}
	Route(e);	 
}

