#include<stdio.h>

//顺序栈的表示 
typedef struct{
	Selemtype *top;
	Selemtype *base;
	int stacksize;
}Sqstack;

//init stack



//链栈的表示
typedef struct StackNode{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;

LinkStack S;

//初始化链栈
void InitStack(LinkStack S_s)
{
	S = NULL;
	return OK;
}

//判断链栈是否为空
Status StackEmpty(LinkStack S_s)
{
	if(S_s==NULL) return TRUE;
	else return FALSE;
}

//链栈的入栈
Status Push(LinkStack S_s, SElemType e)
{
	p = (LinkStack)malloc(sizeof(StackNode));
	p->data = e;
	p->next = S_s;
	S = p;
	return OK;
}

//链栈的出栈
Status Pop(LinkStack S_s,SElemType *e)//e是指向被删元素的指针，一般在调用函数之前声明好 
{
	if(S==NULL) return ERROR;
	*e = S->data;//save data reproduction
	p = S;
	S = S->next;
	free(p);
	return OK;
}

//取出栈顶元素
SElemType GetTop(LinkStack S_s)
{
	if(S_s==NULL) return ERROR;
	return S->data;
}

