 #include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXQSIZE 100
#define QElemType int
#define Status int
#define OK 0
#define ERROR

//定义一个顺序队列 
typedef struct A{
	QElemType *base;//通过base和MAXQSIZE动态分配数组内存 
	int front;
	int rear;
}SqQueue;

//初始化顺序队列
Status InitSqQueue(SqQueue Q_q){
	Q_q.base = (QElemType*)malloc(sizeof(SqQueue));
	if(!Q_q.base)
		exit(OVERFLOW);
	Q_q.front = 0;
	Q_q.rear = 0;
	return OK;	
}

//求顺序循环队列长度
int QueueLength(SqQueue Q_q){
	return (Q_q.rear - Q_q.front + MAXQSIZE) % MAXQSIZE;	
}

//顺序循环队列入队
Status EnQueue(SqQueue Q_q,QElemType e){
	if((Q_q.rear+1)%MAXQSIZE==Q_q.front) return ERROR;
	Q_q.base[Q_q.rear] = e;
	Q_q.rear = (Q_q.rear+1)%MAXQSIZE;
	return OK;
 };
 
 //循环队列出队
 Status DeQueue(SqQueue Q_q, QElemType e){
	if(Q_q.rear == Q_q.front) return ERROR;
	e = Q_q.base[Q_q.front];
	Q_q.front = (Q_q.front+1)%MAXQSIZE;	
 	return OK;
 } ;
 
 //顺序循环队列返回头指针元素
 QElemType GetHead(SqQueue Q_q){
 	if(Q_q.rear != Q_q.front)
 		return Q_q.base[Q_q.front];
 }

//定义一个链式队列节点
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

//定义指向链式队列结点的头指针和尾指针
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;//一般叫做Q

//初始化链式队列
Status InitQueue(LinkQueue Q_q){
	Q_q.front = Q_q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q_q.front) exit(OVERFLOW);
	Q_q.front->next = NULL;
	return OK;
}

//销毁链式队列
Status DestroyQueue(LinkQueue Q_q){
	while(Q_q.front){
		Q_q.rear = Q_q.front->next;
		free(Q_q.front);
		Q_q.front = Q_q.rear;
	}
	return OK;
} 

//在链式队列末尾插入一个新元素
Status EnLinkQueue(LinkQueue Q_q, QElemType e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e; p->next = NULL;
	Q_q.rear->next = NULL;
	Q_q.rear = p;
	return OK;
}

//链式队列删除一个元素
Status DeLinkQueue(LinkQueue Q_q, QElemType *e){
	if(Q_q.front == Q_q.rear) return ERROR;
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = Q_q.front->next;
	*e = p->data;
	Q_q.front->next = p->next;
	if(Q_q.rear == p) Q_q.rear=Q_q.front;
	free(p);
	return OK;
};

//求链式队列队头的元素
Status GetheadLinkQueue(LinkQueue Q_q, QElemType *e){
	if(Q_q.rear = Q_q.front) return ERROR;
	*e = Q_q.front->next->data;
	return OK;
} 
















int main()
{
	return 0;
}
