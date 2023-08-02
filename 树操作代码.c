 #include<stdio.h>

#define MAXTSIZE 100
#define MAX_TREE_SIZE 100
#define Status int
#define TElemType int

#define OK 0

//˳��洢�ṹ 
typedef TElemType SqBiNode[MAXTSIZE];

//��ʽ�洢�ṹ 
typedef struct BTNode{
	TElemType data;
	struct BTNode *lChild, *rChild;  //���Һ���ָ�� 
}BTNode, *BiTree;

//������ʽ�洢
typedef struct TirTNode{
	TElemType data;
	struct TirTNode *lChild, *parent, *rChild;
}TirTNode, *TirTree; 

//��������������㷨
void Visit(BiTree T){
	printf("%d\n", T->data);
}

Status PreOrderTraverse(BiTree T){
	if(!T) return OK;
	Visit(T);  //���ʸ����
	PreOrderTraverse(T->lChild);
	PreOrderTraverse(T->rChild); 
}

//��������������㷨
Status InOrderTraverse(BiTree T){
	if(!T) return OK;
	InOrderTraverse(T->lChild);
	Visit(T);
	InOrderTraverse(T->rChild);
} 

//��������������㷨
Status PostOrderTraverse(BiTree T){
	if(!T) return OK;
	PostOrderTraverse(T->lChild);
	PostOrderTraverse(T->rChild);
	Visit(T);
} 

//��������ǵݹ��㷨, ��ջʵ�� 
typedef struct QStack{
	BTree data;
	struct QStack *next;
}Qstack;




Status InOrderTraverse2(BiTree T){
	BiTree p, q;
	QStack S;
	InitStack(S);
	while(p || !StackEmpty(S)){
		if(!p){
			Push(S, p), p = p->lChild;
		}else{
			Pop(S, q);
			printf("%d\n", q->data);
			p = q->rChild;
		}

	}
	return OK;
}

//�������Ĳ�α������ö���ʵ��
typedef struct{
	BTNode data[MAXSIZE];
	int front, rear;
}SqQueue;

Status LevelOeder(BiTree T){
	BiTree q;
	SqQueue *Q;
	InitQueue(Q);
	EnQueue(Q, T);
	while(!QueueEmpty(Q)){
		DeQueue(Q, q);
		visit(q);
		if(q->lChild)
			EnQueue(Q, q->lChild);
		if(q->rChild)
			EnQueue(Q, q->rChild);
	}
}

//����˫�ױ�ʾ����������ṹ
	//��� 
typedef struct PTNode{
	TElemType data;
	int parent;
}PTNode; 

typedef struct{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;  //�����λ�úͽ����� 
}PTree;

//��������
	//���ӽ�� 
typedef struct CTNode{
	int child;  //���ӽ���±��λ�� 
	struct CTNode *next;
}CTNode, *CTPtr;

	//˫�׽��
typedef struct{
	TElemType data;
	CTPtr firstchild;
}CTBox;

	//���ṹ
typedef struct{
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;  //������λ�úͽ���� 
}CTree; 
 



int main(){
	
	return 0;
}
