#include<stdio.h>
#include<stdlib.h>

typedef struct Node *PtrToNode;
typedef PtrToNode SearchTree;
typedef PtrToNode Position;
typedef int ElementType;
struct Node{
	ElementType Data;
	SearchTree LeftChild;
	SearchTree RightChild; 
}; 

Position Find(SearchTree ST, ElementType X);
SearchTree MakeEmpty(SearchTree ST);
Position FindMin(SearchTree ST);
Position FindMax(SearchTree ST);
SearchTree Insert(SearchTree ST, ElementType X);
SearchTree Delete(SearchTree ST, ElementType X);

SearchTree MakeEmpty(SearchTree ST){
	if(ST!=NULL){
		MakeEmpty(ST->LeftChild);
		MakeEmpty(ST->RightChild);
		free(ST);
	}
	return NULL;
}
Position Find(SearchTree ST, ElementType X){//��С�Ҵ� 
	if(ST==NULL){
		return NULL;
	}
	SearchTree T = ST;
	while(X!=T->Data){
		if(X<T->Data){
			T=T->LeftChild;
		}
		else{
			T=T->RightChild;
		}
		if(T==NULL){
			return NULL;
		}
	}
	return T;
}
Position FindMin(SearchTree ST){
	SearchTree T = ST;
	if(T==NULL){
		return NULL;
	}
	while(T->LeftChild!=NULL){
		T=T->LeftChild;
	}
	return T;
}
Position FindMax(SearchTree ST){
	SearchTree T = ST;
	if(T==NULL){
		return T;
	}
	while(T->RightChild!=NULL){
		T=T->RightChild;
	}
	return T;
}
SearchTree Insert(SearchTree ST, ElementType X){
	SearchTree T = ST;
	SearchTree InsertTree = (SearchTree)malloc(sizeof(struct Node));
	InsertTree->Data=X;
	InsertTree->LeftChild=InsertTree->RightChild=NULL;
	if(T==NULL){
		T=InsertTree;
	} 
	while(X!=T->Data){
		if(X<T->Data){
			if(T->LeftChild==NULL){
				T->LeftChild=InsertTree;
			}
			T=T->LeftChild;
		}
		else if(X>T->Data){
			if(T->RightChild==NULL){
				T->RightChild=InsertTree;
			}
			T=T->RightChild;
		}
		else{
			printf("������ͬԪ��");
			return NULL;
		}
	}
	return T;
}
SearchTree Delete(SearchTree ST, ElementType X){
	Position P = Find(ST,X);
	SearchTree Temp = P;
	if(P->LeftChild==NULL&&P->RightChild==NULL){//û�ж��� 
		free(Temp);
	} 
	else if(P->LeftChild!=NULL&&P->RightChild!=NULL){//�������� ������ȡ������ȡС 
		Temp=FindMax(Temp->LeftChild);//����ȡ��
		P->Data=Temp->Data;
		Delete(P->LeftChild,Temp->Data);//���˵ݹ飬û�취������
		/*����ȡСͬ��*/ 
	}
	else{//һ������ 
		if(P->LeftChild!=NULL){//������� 
			P->Data=P->LeftChild->Data;	
			Temp=P->LeftChild;		
		} 
		else{//���Ҷ��� 
			P->Data=P->RightChild->Data;
			Temp=P->RightChild;
		}
		free(Temp); 
	}
}




