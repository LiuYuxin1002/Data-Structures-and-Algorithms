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
		printf("��Ϊ��");
	}
	while(T->Left!=NULL){
		T=T->Left;
	}
	return T;
}
Position FindMax(AvlTree AT){
	Position T = AT;
	if(T==NULL){
		printf("��Ϊ��");
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
static Position SingleRotateWithLeft(Position P){//������ת ����P�������ڵ�λ�� 
	//����ṹ���� 
	Position P1 = P->Left;
	P->Left=P1->Right;
	P1->Right=P; 
	//���½ڵ�߶�Height
	P->Height=Max(Height(P->Left),Height(P->Right))+1;//���Ҷ��ӵ����ֵ+1 
	P1->Height=Max(Height(P1->Left),Height(P1->Right))+1;
	return P1;
}
static Position SingleRotateWithRight(Position P){//������ת 
	//����ṹ���� 
	Position P1 = P->Right;
	P->Right=P1->Left;
	P1->Left=P; 
	//���½ڵ�߶�Height
	P->Height=Max(Height(P->Left),Height(P->Right))+1;//���Ҷ��ӵ����ֵ+1 
	P1->Height=Max(Height(P1->Left),Height(P1->Right))+1;
	return P1;
}
static Position DoubleRotateWithLeft(Position P){//������ת ����P�Ǹ��ڵ�λ�� �ǵݹ� 
	//����ṹ����
	Position P1=P->Left;//P1�������� 
	Position P2=P->Right;// P2��������
		//�ṹ�仯 
	P->Left=P2->Right;
	P1->Right=P2->Left;
	P2->Left=P1;
	P2->Right=P;
	//���½ڵ�߶�
	P->Height=Max(Height(P->Left),Height(P->Right))+1;
	P1->Height=Max(Height(P1->Left),Height(P1->Right))+1;
	P2->Height=Max(Height(P2->Left),Height(P2->Right))+1;
}
static Position DoubleRotateWithLeft2(Position P){//�ݹ����� 
	/*�Ƚ�������������ת������ת��Ϊ������תģ��*/
	P->Left=SingleRotateWithRight(P->Left);
	/*�ٽ���������ת������Ϊƽ��״̬*/ 
	return SingleRotateWithLeft(P);
} 
static Position DoubleRotateWithRight(Position P){//������ת �ݹ�����
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










