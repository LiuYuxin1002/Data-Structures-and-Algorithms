#include<stdio.h>
#include<stdlib.h>
/****���ı�ʾ****/ 
typedef struct TreeNode *PtrToTreeNode;
typedef PtrToTreeNode BinTree;
typedef PtrToTreeNode TreePosition;
struct TreeNode{
	int Data;
	TreePosition LeftChild;
	TreePosition RightChild;
	int IsFirstTraversal; 
}; 
//���Ĳ�����
BinTree CreatBinTree();
int IsEmptyTree(BinTree BT);
void PreOrderTraversal(BinTree BT);
void InOrderTraversal(BinTree BT);
void PostOrderTraversal(BinTree BT);
void LevelOrderTraversal(BinTree BT);
//�½���ջ���ڱ���
 /*** ��ջ***/
typedef struct Node *PtrToStackNode;
typedef PtrToStackNode Stack;
typedef PtrToStackNode Position;
typedef BinTree ElementType;
struct Node{
	ElementType Data;
	Position Next;
};
//ջ�Ĳ����� 
Stack MakeEmpty();
int IsEmpty(Stack S);
ElementType Pop(Stack S);
void Push(Stack S, ElementType K);
//�½��������ڱ���
/*** ���� ***/
typedef struct QueueNode *Queue;
typedef struct QListNode *PtrToQListNode;
typedef PtrToQListNode QNode;
struct QueueNode{
	QNode Head;
	QNode Rear;
};
struct QListNode{//����ͷβ��Ӧ����ͷβ ,������һ��   *����ͷ���* 
	ElementType Data;
	QNode Next;
};
//���в�����
void EnQueue(Queue Q, ElementType K);
ElementType DeQueue(Queue Q);
int IsEmptyQ(Queue Q); 
//���в�����ʵ��
int IsEmptyQ(Queue Q){
	if(Q->Head==Q->Rear&&Q->Head==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void EnQueue(Queue Q, ElementType K){//������β�� 
	QNode TempQ = (QNode)malloc(sizeof(struct QListNode));
	TempQ->Data=K;
	TempQ->Next=NULL;
	if(!IsEmptyQ(Q)){
		Q->Rear=TempQ;
	} 
	else{
		Q->Head=TempQ;
		Q->Rear=TempQ;
	}
}
ElementType DeQueue(Queue Q){//ɾ��ͷ 
	if(IsEmptyQ(Q)){
		printf("����Ϊ�գ��޷�ɾ����");
		return NULL;
	}
	ElementType TNode = Q->Head->Data;
	QNode Temp = Q->Head;
	if(Q->Head==Q->Rear){//ֻ��һ��Ԫ�� 
		Q->Head=Q->Rear=NULL;
	} 
	else{
		Q->Head=Q->Head->Next;
	}
	free(Temp);
	return TNode;
} 
//��ջ������ʵ�� 
int IsEmpty(Stack S){
	return (S->Next==NULL);
}
Stack MakeEmpty(){
	Stack S = (Stack)malloc(sizeof(struct Node));
	S->Next = NULL;
	return S;
}
ElementType Pop(Stack S){
	ElementType BT;
	Position TopStack;
	if(IsEmpty(S)){
		BT = NULL;
	}
	else{
		TopStack=S->Next;
		BT=TopStack->Data;
		S->Next=TopStack->Next;
		free(TopStack); 
	}
	return BT;
}
void Push(Stack S, ElementType K){
	Position TopCell = (Position)malloc(sizeof(struct Node));
	TopCell->Data=K;
	TopCell->Next=S->Next;
	S->Next=TopCell;
}
//������������ʵ�� 
BinTree CreatBinTree(){
//	BinTree BT = (BinTree)malloc(sizeof(struct TreeNode));
//	return BT;
	return NULL;
}
void PreOrderTraversal(BinTree BT){//���������ѭ��ʵ�� 
	BinTree T = BT;
	Stack S = MakeEmpty();
	while(T||!IsEmpty(S)){//�����ջ��߶�ջS���� 
		while(T){
			Push(S,T);
			printf("%5d",T->Data);
			T=T->LeftChild;
		}
		if(!IsEmpty(S)){
			T=Pop(S);
			T=T->RightChild;
		}
	}
}
void InOrderTraversal(BinTree BT){//�����������������printfλ�� 
	BinTree T = BT;
	Stack S = MakeEmpty();
	while(T||!IsEmpty(S)){
		while(T){
			Push(S,T);
			T=T->LeftChild;
		}
		if(!IsEmpty(S)){
			T=Pop(S);
			printf("%5d",T->Data);
			T=T->RightChild;
		}
	}
}
/*��������ؼ����ж������ӱ�־λ���ڶ��γ�����ջ������������Ǳ���*/ 
void PastOrderTraversal(BinTree BT){//������������ṹ���ӱ�־λIsFirstĬ��Ϊ 1�� 
	BinTree T = BT;
	Stack S = MakeEmpty();
	while(T||!IsEmpty(S)){
		while(T){
			Push(S,T);
			T=T->LeftChild;
		}
		if(!IsEmpty(S)){
			T=Pop(S);
			if(T->IsFirstTraversal==1){//��һ�γ�����ջ�� 
				T->IsFirstTraversal==0;
				Push(S,T);
				T=T->RightChild;
			}
			else{//�ڶ��γ�����ջ�� 
				printf("%5d",T->Data);
			}
		}
	}
} 
void LevelOrderTraversal(BinTree BT){//������� 
	Queue Q = (Queue)malloc(sizeof(struct QueueNode));//���ù����� 
	BinTree T = BT;
	if(!BT) return;
	EnQueue(Q,T);
	while(!IsEmptyQ(Q)){
		T=DeQueue(Q);
		printf("%5d",T->Data);
		if(T->LeftChild){
			EnQueue(Q,T->LeftChild);
		}
		if(T->RightChild){
			EnQueue(Q,T->RightChild);
		}
	}
}




