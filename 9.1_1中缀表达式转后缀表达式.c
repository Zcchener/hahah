#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 40
#define TRUE 1
#define FALSE 0 
typedef struct
{
	char string[10]; 
} Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE]; 
	int top; 
}SeqStack; 

//�½�һ����ջ
SeqStack *InitStack (){
	 
	SeqStack *S;
	S=malloc(sizeof(SeqStack));
	 
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
	if(S->top==MAXSIZE-1) 
		return FALSE;
	
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//��ջ������ 
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1) 
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 

	    
//ȡ��ջ��Ԫ�� 
int GetTop (SeqStack *S,Elemtype *e){
	if(S->top == -1) 
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 
SeqStack *result;
int Convert(char str[]) {
	Elemtype e1,e2;
	int i,count=0;
	printf("%s\n",str); 
	for(i=0;str[i];i++){
		
		if(str[i]>='0'&&str[i]<='9'){ //���������
			e1.string[count]=str[i];
			count++;
		} 
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
			e1.string[count]=0;
			Push(result,e1);//��ջ����
			
			e2.string[0]=str[i];
			e2.string[1]=0;
			Push(result,e2);//��ջ���� 
			
			
		 	count=0;//���ֵļ��������� 
		}

	}
	//����ʱ
	e1.string[count]=0;
	Push(result,e1);//��ջ���� 
	
	for(i=0;i<result->top+1;i++){
		printf("%s\n",result->data[i].string);
	}
}
int main(void){
	result=InitStack();//����ջ
	char str[100]="123+123-345*12/12";
	//scanf("%s",str); 
	Convert(str);
}