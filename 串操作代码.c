#include<stdio.h>


#define MAXLEN 255
#define CHUNKSIZE 80 //һ������洢80���ַ� 

//����һ��˳���ַ��� �ַ�����	���� 
typedef struct{
	char ch[MAXLEN + 1];
	int length;
}SString;

//����һ��������ʽ�洢�ڵ�-��	�ַ����飬 ָ�� 
typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk *next;
}Chunk;

//����������ͷβָ��	����ָ�룬 ���� 
typedef struct{
	Chunk *head,*tail;
	int curlen;    //���ĵ�ǰ���� 
}LString;

//�ַ�����ģʽƥ�䣬 BF�㷨
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
