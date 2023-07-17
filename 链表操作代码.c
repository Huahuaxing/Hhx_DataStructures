#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define ElemType int

//������һ�������� �������� 
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//�����ʼ������ĺ���
int InitList_L(LinkList* L_L)
{
	(*L_L) =(LinkList)malloc(sizeof(LNode));//����ռ� 
	(*L_L)->next= NULL;
	return OK; 
}

/*�������ٵ�����L�ĺ���*/
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

//������յ�����L�ĺ���
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

//�����������L���ȵĺ���
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

//���庯����ȡ�������е�i��������ֵ��
int GetElem_L(LinkList *L_L,int i)//������L_L,ȡ��i������ֵ
{
	LinkList p;
	int j = 1;//������j��j��ֵ��pָ��Ľ�������ͬ����jΪ1ʱpָ����Ԫ��� 
	p = (*L_L)->next;//pָ����Ԫ�ڵ� 
	while(p||j!=i)
	{
		j++;
		p = p->next;
	}
	if(!p||j>i)return ERROR;
	return p->data;
}

//���庯�������ҵ������е�����Ԫ�ز����ص�ַ��
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

//���庯�������ҵ������е�����Ԫ�ز������߼���ţ�
int LocateElem_L(LinkList *L_L,ElemType e)
{
	LinkList p;
	int j = 1;//�趨������j 
	p = (*L_L)->next;
	while(p&&(p->data)!=e)
	{
		j++;
		p = p->next;
	}
	if(p)return j;
	else return 0;
}

//���庯�����ڵ�i��Ԫ��֮ǰ����Ԫ��e��
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

//���庯������������L�е�i������Ԫ��ɾ����
int DeleteList_L(LinkList *L_L,int i,ElemType *p_e)//*p_e��ָ��Ԥɾ��Ԫ��e��ָ�� 
{
	LinkList p,q;
	int j = 0;
	p = (*L_L)->next;
	while(p->next&&j<i-1)//ɾ����i�����Ԫ�أ���ָ��Ӧָ��ڣ���j��ֵ��i-1��Ԫ�� 
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

//����һ������ͷ�巨 
void CreateList_L(LinkList *L_L,int n)//���ȴ�����ͷָ�룬Ҫ�����ĵ�������n�����
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

//����һ������β�巨
void CreateList_R(LinkList *L_L,int n)
{
	LinkList r;
	int i;
	r = (*L_L);
	for(i=1;i<=n;i++)
	{
		LinkList p;
		scanf("c",p->data);
		p->next = r->next;//��p->next = NULL 
		r->next = p;
		r = p;
	}
}

//��βָ��ѭ������ĺϲ����� 
LinkList ConnectLink_L(LinkList *La,LinkList *Lb)//La,Lb����βָ�� 
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

//˫������Ĳ���
int InsertList_DuL(DuLinkList *L_L,int i,ElemType e)//������������±�Ϊi��ͷ��������� 
{
	DuLinkList p;
	if((p = GetElemP_DuL((*L_L),i))) return ERROR;//ʹָ��pָ���i��� 
	DuLinkList s;
	s = (DuLinkList)malloc(sizeof(DuLNode));
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

//˫�������ɾ��
int DeleteList_DuL(DuLinkList *L_L,int i)
{
	DuLinkList p;
	if(!(p = GetElemP_DuL(*L_L),i)) return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}
 
 
//������ 
int main()
{
	return 0;
}

