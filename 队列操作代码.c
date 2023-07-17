 #include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXQSIZE 100
#define QElemType int
#define Status int
#define OK 0
#define ERROR

//����һ��˳����� 
typedef struct A{
	QElemType *base;//ͨ��base��MAXQSIZE��̬���������ڴ� 
	int front;
	int rear;
}SqQueue;

//��ʼ��˳�����
Status InitSqQueue(SqQueue Q_q){
	Q_q.base = (QElemType*)malloc(sizeof(SqQueue));
	if(!Q_q.base)
		exit(OVERFLOW);
	Q_q.front = 0;
	Q_q.rear = 0;
	return OK;	
}

//��˳��ѭ�����г���
int QueueLength(SqQueue Q_q){
	return (Q_q.rear - Q_q.front + MAXQSIZE) % MAXQSIZE;	
}

//˳��ѭ���������
Status EnQueue(SqQueue Q_q,QElemType e){
	if((Q_q.rear+1)%MAXQSIZE==Q_q.front) return ERROR;
	Q_q.base[Q_q.rear] = e;
	Q_q.rear = (Q_q.rear+1)%MAXQSIZE;
	return OK;
 };
 
 //ѭ�����г���
 Status DeQueue(SqQueue Q_q, QElemType e){
	if(Q_q.rear == Q_q.front) return ERROR;
	e = Q_q.base[Q_q.front];
	Q_q.front = (Q_q.front+1)%MAXQSIZE;	
 	return OK;
 } ;
 
 //˳��ѭ�����з���ͷָ��Ԫ��
 QElemType GetHead(SqQueue Q_q){
 	if(Q_q.rear != Q_q.front)
 		return Q_q.base[Q_q.front];
 }

//����һ����ʽ���нڵ�
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

//����ָ����ʽ���н���ͷָ���βָ��
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;//һ�����Q

//��ʼ����ʽ����
Status InitQueue(LinkQueue Q_q){
	Q_q.front = Q_q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q_q.front) exit(OVERFLOW);
	Q_q.front->next = NULL;
	return OK;
}

//������ʽ����
Status DestroyQueue(LinkQueue Q_q){
	while(Q_q.front){
		Q_q.rear = Q_q.front->next;
		free(Q_q.front);
		Q_q.front = Q_q.rear;
	}
	return OK;
} 

//����ʽ����ĩβ����һ����Ԫ��
Status EnLinkQueue(LinkQueue Q_q, QElemType e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e; p->next = NULL;
	Q_q.rear->next = NULL;
	Q_q.rear = p;
	return OK;
}

//��ʽ����ɾ��һ��Ԫ��
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

//����ʽ���ж�ͷ��Ԫ��
Status GetheadLinkQueue(LinkQueue Q_q, QElemType *e){
	if(Q_q.rear = Q_q.front) return ERROR;
	*e = Q_q.front->next->data;
	return OK;
} 
















int main()
{
	return 0;
}
