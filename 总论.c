#include<stdio.h>
/**** ���� ****/
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
struct Node{
	ElementType Data;
	Position Next;
}; 
//������
List MakeEmpty();
int IsEmpty(List L);
void Insert(List L, ElementType X, Position P);
void Delete(List L, ElementType X);

/*** ��ջ***/
typedef struct Node *PtrToStackNode;
typedef PtrToStackNode Stack;
typedef PtrToStackNode Position;
typedef int ElementType;
//��������
Stack MakeEmpty();
int IsEmpty(Stack S);
void Pop(Stack S);
void Push(Stack S, ElementType K);

/*��ջ������ �������ʾʱ���޸Ĳ������ɣ�
  ʵ�ֺ�����Insert()��Delete()�ֱ��Ϊ��Pop Push �� Enqueue Dequeue
  һ�����������ڶ�ջ�������ͷ��ջ�������ڶ��У���ͷ����ͷ����β����β
  ԭ�� �������ͷ��ɾ�����������βֻ��������ɾ*/ 

/**** ������ ****/
struct TreeNode{
	ElementType Data;
	Position LeftChild;
	Position RightChild;
}; 
typedef struct TreeNode *PtrToTreeNode;
typedef PtrToTreeNode BinTree;
typedef PtrToTreeNode Position;
typedef int ElementType;
//�½���ջ���ڱ���
 
//������
BinTree CreatBinTree();
int IsEmptyTree(BinTree BT);
void PreOrderTraversal(BinTree BT);
void InOrderTraversal(BinTree BT);
void PostOrderTraversal(BinTree BT);
void LevelOrderTraversal(BinTree BT);











