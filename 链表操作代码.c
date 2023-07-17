#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define ElemType int

//定义了一个链表结点 储存整数 
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//定义初始化链表的函数
int InitList_L(LinkList* L_L)
{
	(*L_L) =(LinkList)malloc(sizeof(LNode));//分配空间 
	(*L_L)->next= NULL;
	return OK; 
}

/*定义销毁单链表L的函数*/
int DestroyList_L(LinkList* L_L)
{
	LNode* p;
	while(*L_L)
	{
		p = *L_L;
		(*L_L) = (*L_L)-> next;
		free(p);
	}
	return OK;
}

//定义清空单链表L的函数
int ClearList_L(LinkList *L_L)
{
	LinkList p,q;
	p = (*L_L)->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q; 
	}
	(*L_L)->next = NULL;
	return OK;	
}

//定义计算链表L长度的函数
int  ListLength_L(LinkList *L_L)
{
	LinkList p;
	int sum;
	p = (*L_L)->next;
	while(p)
	{
		sum++;
		p = p->next;
	}
	return OK;
}

//定义函数（取单链表中第i个函数的值）
int GetElem_L(LinkList *L_L,int i)//单链表L_L,取第i个结点的值
{
	LinkList p;
	int j = 1;//计数器j，j的值与p指向的结点序号相同，即j为1时p指向首元结点 
	p = (*L_L)->next;//p指向首元节点 
	while(p||j!=i)
	{
		j++;
		p = p->next;
	}
	if(!p||j>i)return ERROR;
	return p->data;
}

//定义函数（查找单链表中的数据元素并返回地址）
LNode* LocateList_L(LinkList *L_L,ElemType e)
{
	LinkList p;
	p = (*L_L)->next;
	while(p&&(p->data)!=e)
	{
		p = p->next;	
	}
	return p;	
}

//定义函数（查找单链表中的数据元素并返回逻辑序号）
int LocateElem_L(LinkList *L_L,ElemType e)
{
	LinkList p;
	int j = 1;//设定计数器j 
	p = (*L_L)->next;
	while(p&&(p->data)!=e)
	{
		j++;
		p = p->next;
	}
	if(p)return j;
	else return 0;
}

//定义函数（在第i个元素之前插入元素e）
int InsertList_L(LinkList *L_L,int i,ElemType e)
{
	LinkList p,s;
	int j=0;
	p = (*L_L);
	while(p&&j<i-1)
	{
		j++;
		p = p->next;
	}
	if(!p||j>i-1)return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//定义函数（将单链表L中第i个数据元素删除）
int DeleteList_L(LinkList *L_L,int i,ElemType *p_e)//*p_e是指向预删除元素e的指针 
{
	LinkList p,q;
	int j = 0;
	p = (*L_L)->next;
	while(p->next&&j<i-1)//删除第i个结点元素，则指针应指向第（即j的值）i-1个元素 
	{
		j++;
		p = p->next;
	}
	if(!(p->next)||j>i-1)return ERROR;
	q = p->next;
	p->next = p->next->next;
	*p_e = q->data;
	free(q);
	return OK;
}

//创建一个链表，头插法 
void CreateList_L(LinkList *L_L,int n)//首先传进来头指针，要创建的单链表有n个结点
{
	int i;
	for(i=n;i>0;i--)
	{
		LinkList p;
		scanf("%c",p->data);
		p->next = (*L_L)->next;
		(*L_L)->next = p;
	}
}

//创建一个链表，尾插法
void CreateList_R(LinkList *L_L,int n)
{
	LinkList r;
	int i;
	r = (*L_L);
	for(i=1;i<=n;i++)
	{
		LinkList p;
		scanf("c",p->data);
		p->next = r->next;//即p->next = NULL 
		r->next = p;
		r = p;
	}
}

//带尾指针循环链表的合并函数 
LinkList ConnectLink_L(LinkList *La,LinkList *Lb)//La,Lb都是尾指针 
{
	LinkList p;
	p = (*La)->next;
	(*La)->next = (*Lb)->next->next;
	free((*Lb)->next);
	(*Lb) = p;
	return (*Lb);
}

typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior,*next;
}DuLNode,*DuLinkList;

//双向链表的插入
int InsertList_DuL(DuLinkList *L_L,int i,ElemType e)//插入后新链表下标为i，头结点算第零个 
{
	DuLinkList p;
	if((p = GetElemP_DuL((*L_L),i))) return ERROR;//使指针p指向第i结点 
	DuLinkList s;
	s = (DuLinkList)malloc(sizeof(DuLNode));
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

//双向链表的删除
int DeleteList_DuL(DuLinkList *L_L,int i)
{
	DuLinkList p;
	if(!(p = GetElemP_DuL(*L_L),i)) return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}
 
 
//主函数 
int main()
{
	return 0;
}

