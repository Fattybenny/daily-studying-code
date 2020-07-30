#include<stdio.h>
#include<stdlib.h> 
#define  stacksize  10

typedef int elemtype;
 typedef  struct  sqstack //车场，便道栈 
    {
     int  data[stacksize];
     int  top;
    } SqStackTp;
    
typedef struct  linked_queue// 候车队列 
    {
     int  data;
     struct  linked_queue  * next;
    }LqueueTp;
typedef  struct 
    {  
     LqueueTp  *front ,  *rear ;
    } QueptrTp;


void Print(SqStackTp *&S1)//打印停车场 
{
	for(int i=0;i<stacksize;i++)
	{
		if(S1->data[i]!=0)
		printf("%d ",S1->data[i]);
	}
	
 } 
 
void InitStack(SqStackTp *&s)//初始化栈 
{
	s=(SqStackTp*)malloc(sizeof(SqStackTp));
	s->top=-1;
}

bool StackFull(SqStackTp *s)//判断栈是否为满 
{
	return(s->top==stacksize-1);
}

bool Stackempty(SqStackTp *s)//判断 栈是否为空 
{
	return (s->top==-1);
}

bool Push(SqStackTp *&s,elemtype e) //进栈 
{
	if(s->top==stacksize-1)
	return false;
	s->top++;
	s->data [s->top]=e;
	return true;
 } 

bool Pop(SqStackTp *&s,elemtype &e)//出栈 
{
	if(s->top==-1)
	return false;
	e=s->data[s->top];
	s->data[s->top]=0;
	s->top--;
	return true;
}

void InitQueue(QueptrTp *&q)//初始化队列 
{
	q=(QueptrTp*)malloc(sizeof(QueptrTp));
	q->front=q->rear=NULL;
}

bool QueueEmpty(QueptrTp *q)//判断队列为空 
{
	return (q->rear==NULL);
 } 

void enQueue(QueptrTp *&q, elemtype e)//进队 
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

bool deQueue(QueptrTp *&q, elemtype &e) //出队列 
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

void InitPark(SqStackTp *&S1,elemtype e,QueptrTp *&q)//进入停车场 
{
	elemtype E;
	if(StackFull(S1)) 
	{
		printf("停车场已满，请等候");
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

void parkoff(SqStackTp *&S1,SqStackTp *&S2,elemtype t) //退车 
{
	elemtype e1,e2,flag=1;
	if(Stackempty(S1)) 
	{
	printf("停车场已空，无需出车"); return; 
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
	printf("请输入停车场中已经存在的车牌号,以-1结束:\n");
	int a=1;
	while(a!=-1)
	{
		scanf("%d",&a);
		if(a!=-1) 
		Push(S1,a);
	}
	getchar();
	printf("请输入操作编号,A代表车辆进入停车场，B代表车辆退出停车场：\n");
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
	       printf("请输入即将停车号码：");
		   scanf("%d",&e);
		   getchar();
		   InitQueue(q);
	       InitPark(S1,e,q);
	       break;
	case 'B':
		   printf("\n");
		   printf("请输入即将出车号码：");
		   scanf("%d",&e);
		   getchar();
		   InitStack(S2);
		   parkoff(S1,S2,e);
		   break;
	default: g=0; break;
    }
    	printf("请继续输入操作编号：\n");
    }
}
















