#include<stdio.h>
#include<stdlib.h> 
#define  stacksize  10

typedef int elemtype;
 typedef  struct  sqstack //���������ջ 
    {
     int  data[stacksize];
     int  top;
    } SqStackTp;
    
typedef struct  linked_queue// �򳵶��� 
    {
     int  data;
     struct  linked_queue  * next;
    }LqueueTp;
typedef  struct 
    {  
     LqueueTp  *front ,  *rear ;
    } QueptrTp;


void Print(SqStackTp *&S1)//��ӡͣ���� 
{
	for(int i=0;i<stacksize;i++)
	{
		if(S1->data[i]!=0)
		printf("%d ",S1->data[i]);
	}
	
 } 
 
void InitStack(SqStackTp *&s)//��ʼ��ջ 
{
	s=(SqStackTp*)malloc(sizeof(SqStackTp));
	s->top=-1;
}

bool StackFull(SqStackTp *s)//�ж�ջ�Ƿ�Ϊ�� 
{
	return(s->top==stacksize-1);
}

bool Stackempty(SqStackTp *s)//�ж� ջ�Ƿ�Ϊ�� 
{
	return (s->top==-1);
}

bool Push(SqStackTp *&s,elemtype e) //��ջ 
{
	if(s->top==stacksize-1)
	return false;
	s->top++;
	s->data [s->top]=e;
	return true;
 } 

bool Pop(SqStackTp *&s,elemtype &e)//��ջ 
{
	if(s->top==-1)
	return false;
	e=s->data[s->top];
	s->data[s->top]=0;
	s->top--;
	return true;
}

void InitQueue(QueptrTp *&q)//��ʼ������ 
{
	q=(QueptrTp*)malloc(sizeof(QueptrTp));
	q->front=q->rear=NULL;
}

bool QueueEmpty(QueptrTp *q)//�ж϶���Ϊ�� 
{
	return (q->rear==NULL);
 } 

void enQueue(QueptrTp *&q, elemtype e)//���� 
{
	LqueueTp *p;
	p=(LqueueTp*)malloc(sizeof(LqueueTp));
	p->data=e;
	p->next=NULL;
	if(q->rear==NULL)
	   q->front=q->rear=p;
	else
	{
		q->rear->next=p;
		q->rear=p;
		
	 } 
 } 

bool deQueue(QueptrTp *&q, elemtype &e) //������ 
{
	LqueueTp *t;
	if(q->rear==NULL)
	return false;
	t=q->front;
	if(q->front==q->rear)
    	q->front=q->rear=NULL;
	else
	    q->front=q->front->next;
	  e=t->data;
	  free(t);
	  return true;
}

void InitPark(SqStackTp *&S1,elemtype e,QueptrTp *&q)//����ͣ���� 
{
	elemtype E;
	if(StackFull(S1)) 
	{
		printf("ͣ������������Ⱥ�");
		 enQueue(q, e);
		 return ;
	}
	else 
	{
		enQueue(q, e);
		deQueue(q, E);
		Push(S1,E);
		Print(S1);	printf("\n");
	}
}

void parkoff(SqStackTp *&S1,SqStackTp *&S2,elemtype t) //�˳� 
{
	elemtype e1,e2,flag=1;
	if(Stackempty(S1)) 
	{
	printf("ͣ�����ѿգ��������"); return; 
    } 
     while(flag)    
         {
        	Pop(S1,e1) ;
        	if(t==e1) flag=0;
	        else
	         {
              Push(S2,e1);
	         }
        }
     while(!Stackempty(S2))
     {
     	Pop(S2,e2);
     	Push(S1,e2);
	 }
	 Print(S1);	printf("\n");
}

int main()
{
	SqStackTp *S1, *S2;QueptrTp *q; int i;
		InitStack(S1);
	for(i=0;i<stacksize;i++)
	     S1->data[i]=0;
	printf("������ͣ�������Ѿ����ڵĳ��ƺ�,��-1����:\n");
	int a=1;
	while(a!=-1)
	{
		scanf("%d",&a);
		if(a!=-1) 
		Push(S1,a);
	}
	getchar();
	printf("������������,A����������ͣ������B�������˳�ͣ������\n");
	char b; int g=1;
	while(g)
	{
    elemtype e;
	scanf("%c",&b);
	getchar();
	switch(b)
	{
	case 'A':  
	       printf("\n");
	       printf("�����뼴��ͣ�����룺");
		   scanf("%d",&e);
		   getchar();
		   InitQueue(q);
	       InitPark(S1,e,q);
	       break;
	case 'B':
		   printf("\n");
		   printf("�����뼴���������룺");
		   scanf("%d",&e);
		   getchar();
		   InitStack(S2);
		   parkoff(S1,S2,e);
		   break;
	default: g=0; break;
    }
    	printf("��������������ţ�\n");
    }
}
















