#include<stdio.h>


#define MAXLEN 255
#define CHUNKSIZE 80 //一个块里存储80个字符 

//定义一个顺序字符串 字符数组	长度 
typedef struct{
	char ch[MAXLEN + 1];
	int length;
}SString;

//定义一个串的链式存储节点-块	字符数组， 指针 
typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk *next;
}Chunk;

//定义链串的头尾指针	两个指针， 长度 
typedef struct{
	Chunk *head,*tail;
	int curlen;    //串的当前长度 
}LString;

//字符串的模式匹配， BF算法
int index_BF(SString S, SString T){
	int i = 0, j = 0;
	while(i < S.length && j < T.length){
		if(S.ch[i] == T.ch[j]){
			i++;
			j++;
		}
		else if(S.ch[i] != T.ch[j]){
			i = i - j + 1;
			j = 0;
		}
	}
	printf("i = %d, j = %d \n", i, j);
	if(j == (T.length)) return i - j;
	return -1;
	
} 

int main()
{
	SString S = {"aaabcc", 6};
	SString T = {"abc", 3};
	printf("%d", index_BF(S, T));
	return 0;
}
