#include<stdio.h>
#include<stdlib.h>
/****树的表示****/ 
typedef struct TreeNode *PtrToTreeNode;
typedef PtrToTreeNode BinTree;
typedef PtrToTreeNode TreePosition;
struct TreeNode{
	int Data;
	TreePosition LeftChild;
	TreePosition RightChild;
	int IsFirstTraversal; 
}; 
//树的操作集
BinTree CreatBinTree();
int IsEmptyTree(BinTree BT);
void PreOrderTraversal(BinTree BT);
void InOrderTraversal(BinTree BT);
void PostOrderTraversal(BinTree BT);
void LevelOrderTraversal(BinTree BT);
//新建堆栈用于遍历
 /*** 堆栈***/
typedef struct Node *PtrToStackNode;
typedef PtrToStackNode Stack;
typedef PtrToStackNode Position;
typedef BinTree ElementType;
struct Node{
	ElementType Data;
	Position Next;
};
//栈的操作集 
Stack MakeEmpty();
int IsEmpty(Stack S);
ElementType Pop(Stack S);
void Push(Stack S, ElementType K);
//新建队列用于遍历
/*** 队列 ***/
typedef struct QueueNode *Queue;
typedef struct QListNode *PtrToQListNode;
typedef PtrToQListNode QNode;
struct QueueNode{
	QNode Head;
	QNode Rear;
};
struct QListNode{//队列头尾对应链表头尾 ,此链表一般   *不带头结点* 
	ElementType Data;
	QNode Next;
};
//队列操作集
void EnQueue(Queue Q, ElementType K);
ElementType DeQueue(Queue Q);
int IsEmptyQ(Queue Q); 
//队列操作集实现
int IsEmptyQ(Queue Q){
	if(Q->Head==Q->Rear&&Q->Head==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void EnQueue(Queue Q, ElementType K){//增加在尾巴 
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
ElementType DeQueue(Queue Q){//删除头 
	if(IsEmptyQ(Q)){
		printf("队列为空，无法删除！");
		return NULL;
	}
	ElementType TNode = Q->Head->Data;
	QNode Temp = Q->Head;
	if(Q->Head==Q->Rear){//只有一个元素 
		Q->Head=Q->Rear=NULL;
	} 
	else{
		Q->Head=Q->Head->Next;
	}
	free(Temp);
	return TNode;
} 
//堆栈操作集实现 
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
//二叉树操作集实现 
BinTree CreatBinTree(){
//	BinTree BT = (BinTree)malloc(sizeof(struct TreeNode));
//	return BT;
	return NULL;
}
void PreOrderTraversal(BinTree BT){//先序遍历，循环实现 
	BinTree T = BT;
	Stack S = MakeEmpty();
	while(T||!IsEmpty(S)){//树不空或者堆栈S不空 
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
void InOrderTraversal(BinTree BT){//中序遍历，区别在于printf位置 
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
/*后序遍历关键点有二：增加标志位；第二次出现在栈顶才输出，这是本质*/ 
void PastOrderTraversal(BinTree BT){//后序遍历，树结构增加标志位IsFirst默认为 1； 
	BinTree T = BT;
	Stack S = MakeEmpty();
	while(T||!IsEmpty(S)){
		while(T){
			Push(S,T);
			T=T->LeftChild;
		}
		if(!IsEmpty(S)){
			T=Pop(S);
			if(T->IsFirstTraversal==1){//第一次出现在栈顶 
				T->IsFirstTraversal==0;
				Push(S,T);
				T=T->RightChild;
			}
			else{//第二次出现在栈顶 
				printf("%5d",T->Data);
			}
		}
	}
} 
void LevelOrderTraversal(BinTree BT){//层序遍历 
	Queue Q = (Queue)malloc(sizeof(struct QueueNode));//不用管链表 
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




