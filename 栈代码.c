#include<stdio.h>

//˳��ջ�ı�ʾ 
typedef struct{
	Selemtype *top;
	Selemtype *base;
	int stacksize;
}Sqstack;

//init stack



//��ջ�ı�ʾ
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;

LinkStack S;

//��ʼ����ջ
void InitStack(LinkStack S_s)
{
	S = NULL;
	return OK;
}

//�ж���ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S_s)
{
	if(S_s==NULL) return TRUE;
	else return FALSE;
}

//��ջ����ջ
Status Push(LinkStack S_s, SElemType e)
{
	p = (LinkStack)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S_s;
	S = p;
	return OK;
}

//��ջ�ĳ�ջ
Status Pop(LinkStack S_s,SElemType *e)//e��ָ��ɾԪ�ص�ָ�룬һ���ڵ��ú���֮ǰ������ 
{
	if(S==NULL) return ERROR;
	*e = S->data;//save data reproduction
	p = S;
	S = S->next;
	free(p);
	return OK;
}

//ȡ��ջ��Ԫ��
SElemType GetTop(LinkStack S_s)
{
	if(S_s==NULL) return ERROR;
	return S->data;
}

