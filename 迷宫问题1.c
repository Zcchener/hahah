#include <stdio.h>
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
		if(step<min)//��������ȵ�ǰ��СֵС������
			min=step;
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
			book[tx][ty]=1;//���
			printf("��(%d,%d)%d %d\n",tx,ty,k,step);
			dfs(tx,ty,step+1);//����һ���ڵ�
			book[tx][ty]=0;//���ýڵ��˳�(����)ʱ��ȡ�����
			printf("��(%d,%d)%d\n",tx,ty,k); 
		} 
	}
	return;
	 
}
int main(void)
{
	book[0][0]=1;//�����ʼ��
	dfs(0,0,0);//��һ����������ʼ���x���꣬�ڶ�����������ʼ���y���꣬�����������ǲ��� 
	printf("%d\n",min);
}