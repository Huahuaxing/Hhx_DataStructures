 #include<stdio.h>

#define MAXTSIZE 100
#define MAX_TREE_SIZE 100
#define Status int
#define TElemType int

#define OK 0

//顺序存储结构 
typedef TElemType SqBiNode[MAXTSIZE];

//链式存储结构 
typedef struct BTNode{
	TElemType data;
	struct BTNode *lChild, *rChild;  //左右孩子指针 
}BTNode, *BiTree;

//三叉链式存储
typedef struct TirTNode{
	TElemType data;
	struct TirTNode *lChild, *parent, *rChild;
}TirTNode, *TirTree; 

//二叉树先序遍历算法
void Visit(BiTree T){
	printf("%d\n", T->data);
}

Status PreOrderTraverse(BiTree T){
	if(!T) return OK;
	Visit(T);  //访问根结点
	PreOrderTraverse(T->lChild);
	PreOrderTraverse(T->rChild); 
}

//二叉树中序遍历算法
Status InOrderTraverse(BiTree T){
	if(!T) return OK;
	InOrderTraverse(T->lChild);
	Visit(T);
	InOrderTraverse(T->rChild);
} 

//二叉树后序遍历算法
Status PostOrderTraverse(BiTree T){
	if(!T) return OK;
	PostOrderTraverse(T->lChild);
	PostOrderTraverse(T->rChild);
	Visit(T);
} 

//中序遍历非递归算法, 用栈实现 
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

//二叉树的层次遍历，用队列实现
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

//树的双亲表示法，定义结点结构
	//结点 
typedef struct PTNode{
	TElemType data;
	int parent;
}PTNode; 

typedef struct{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;  //根结点位置和结点个数 
}PTree;

//孩子链表
	//孩子结点 
typedef struct CTNode{
	int child;  //孩子结点下标的位置 
	struct CTNode *next;
}CTNode, *CTPtr;

	//双亲结点
typedef struct{
	TElemType data;
	CTPtr firstchild;
}CTBox;

	//树结构
typedef struct{
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;  //根结点的位置和结点数 
}CTree; 
 



int main(){
	
	return 0;
}
