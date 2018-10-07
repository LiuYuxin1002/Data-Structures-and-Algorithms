#include<stdio.h>
#include<stdlib.h> 

typedef struct AvlNode *Position;
typedef Position AvlTree;
typedef int ElementType; 
struct AvlNode{
	ElementType Data;
	Position Left;
	Position Right;
	int Height;
}; 

AvlTree MakeEmpty();
Position Find(AvlTree AT, ElementType X);
Position FindMin(AvlTree AT);
Position FindMax(AvlTree AT);
AvlTree Insert(AvlTree AT);
AvlTree Delete(AvlTree AT);
static Position SingleRotateWithLeft(Position P);
static Position SingleRotateWithRight(Position P);
static Position DoubleRotateWithLeft(Position P);
static Position DoubleRotateWithRight(Position P);
static int Height(Position P);

AvlTree MakeEmpty(){
	return NULL; 
}
Position Find(AvlTree AT, ElementType X){
	if(AT==NULL){
		return NULL;
	}
	Position T = AT;
	while(T->Data!=X){
		if(X<T->Data){
			T=T->Left;
		}
		else{
			T=T->Right;
		}
		if(T==NULL){
			break;
		}
	}
	return T;
}
Position FindMin(AvlTree AT){
	Position T = AT;
	if(T==NULL){
		printf("树为空");
	}
	while(T->Left!=NULL){
		T=T->Left;
	}
	return T;
}
Position FindMax(AvlTree AT){
	Position T = AT;
	if(T==NULL){
		printf("树为空");
	}
	while(T->Right!=NULL){
		T=T->Right;
	}
	return T;
}
AvlTree Insert(AvlTree AT, ElementType X){
	
} 
AvlTree Delete(AvlTree AT){
	
}
static Position SingleRotateWithLeft(Position P){//左左旋转 其中P是主根节点位置 
	//解决结构问题 
	Position P1 = P->Left;
	P->Left=P1->Right;
	P1->Right=P; 
	//更新节点高度Height
	P->Height=Max(Height(P->Left),Height(P->Right))+1;//左右儿子的最大值+1 
	P1->Height=Max(Height(P1->Left),Height(P1->Right))+1;
	return P1;
}
static Position SingleRotateWithRight(Position P){//右右旋转 
	//解决结构问题 
	Position P1 = P->Right;
	P->Right=P1->Left;
	P1->Left=P; 
	//更新节点高度Height
	P->Height=Max(Height(P->Left),Height(P->Right))+1;//左右儿子的最大值+1 
	P1->Height=Max(Height(P1->Left),Height(P1->Right))+1;
	return P1;
}
static Position DoubleRotateWithLeft(Position P){//左右旋转 其中P是根节点位置 非递归 
	//解决结构问题
	Position P1=P->Left;//P1是左子树 
	Position P2=P->Right;// P2是右子树
		//结构变化 
	P->Left=P2->Right;
	P1->Right=P2->Left;
	P2->Left=P1;
	P2->Right=P;
	//更新节点高度
	P->Height=Max(Height(P->Left),Height(P->Right))+1;
	P1->Height=Max(Height(P1->Left),Height(P1->Right))+1;
	P2->Height=Max(Height(P2->Left),Height(P2->Right))+1;
}
static Position DoubleRotateWithLeft2(Position P){//递归做法 
	/*先将左子树右右旋转，整体转化为左左旋转模型*/
	P->Left=SingleRotateWithRight(P->Left);
	/*再进行左左旋转，调整为平衡状态*/ 
	return SingleRotateWithLeft(P);
} 
static Position DoubleRotateWithRight(Position P){//右左旋转 递归做法
	P->Right=SingleRotateWithLeft(P->Left);
	return SingleRotateWithRight(P); 
}
static int Height(Position P){
	if(P==NULL){
		return -1;
	}
	else{
		return P->Height;
	}
}










