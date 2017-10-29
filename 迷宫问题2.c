#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0 
typedef struct{
	int x;
	int y;
	int direction;
} Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE];//ջ,���͸���������� 
	int top;//ָ��ջ�� 
}SeqStack; 

//�½�һ����ջ
SeqStack *InitStack (){
	//����ռ� 
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack));
	//ջ����ʼ�� 
	S->top =-1; 
	return S;
}


//�ж��Ƿ�Ϊ��ջ 
int StackEmpty (SeqStack *S){
	if(S->top==-1)
		return TRUE;
	else 
		return FALSE; 
} 

//��ջ
int Push (SeqStack *S,Elemtype e){
	if(S->top==MAXSIZE-1)//ջ���������ʧ�� 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//��ջ������ 
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//��ջ����ջʧ��
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 

	    
//ȡ��ջ��Ԫ�� 
int GetTop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//��ջ����ջʧ��
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 
SeqStack *SS;
int n,m,p=4,q=3,min=9999999,book[10][10];
int a[5][4]={{0,0,1,0},
             {0,0,0,0},
             {0,0,1,0},
			 {0,1,0,0},
			 {0,0,0,1}};
			   
void dfs(int x,int y,int step)
{
	int next[4][2]={{0,1},//�� 
	                {1,0},//�� 
			        {0,-1},//�� 
	                {-1,0}};//��
					
	if(x==3&&y==3)
	{
		printf("����\n"); 
		if(step<min)//��������ȵ�ǰ��СֵС��
			min=step;
		for(int i=0;i<SS->top+1;i++){
			printf("����(%d,%d)%d\n",SS->data[i].x,SS->data[i].y,SS->data[i].direction); 
		}
		return;//������һ�� 
	} 
	int tx,ty,k;
	for(k=0;k<4;k++)//ö�������߷� 
	{
		tx=x+next[k][0];//��һ�� 
		ty=y+next[k][1];
		
		if(tx<0||ty<0||ty>=4||tx>=5)//�ж��Ƿ�Խ�� 
			continue;
			
		if(a[tx][ty]!=1&&book[tx][ty]==0)//�ж���һ���Ƿ��߹����Ƿ����ϰ���
		{
			Elemtype e;
			e.x=tx;
			e.y=ty;
			e.direction=k;
			book[tx][ty]=1;//���
			Push(SS,e);
			printf("��(%d,%d)%d %d\n",e.x,e.y,e.direction,step);
			dfs(tx,ty,step+1);//����һ���ڵ�
			book[tx][ty]=0;//���ýڵ��˳�(����)ʱ��ȡ�����
			printf("��(%d,%d)%d\n",e.x,e.y,e.direction); 
			Pop(SS,&e);
		} 
	}
	return;
	 
}
int main(void)
{
	Elemtype e;
	SS=InitStack();
	e.x=0;
	e.y=0;
	e.direction=0;
	Push(SS,e);
	book[0][0]=1;//�����ʼ��
	dfs(0,0,0);//��һ����������ʼ���x���꣬�ڶ�����������ʼ���y���꣬�����������ǲ��� 
	printf("%d\n",min);
}


