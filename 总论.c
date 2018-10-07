#include<stdio.h>
/**** 链表 ****/
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
struct Node{
	ElementType Data;
	Position Next;
}; 
//操作集
List MakeEmpty();
int IsEmpty(List L);
void Insert(List L, ElementType X, Position P);
void Delete(List L, ElementType X);

/*** 堆栈***/
typedef struct Node *PtrToStackNode;
typedef PtrToStackNode Stack;
typedef PtrToStackNode Position;
typedef int ElementType;
//函数声明
Stack MakeEmpty();
int IsEmpty(Stack S);
void Pop(Stack S);
void Push(Stack S, ElementType K);

/*堆栈、队列 用链表表示时简单修改参数即可；
  实现函数的Insert()和Delete()分别变为：Pop Push 和 Enqueue Dequeue
  一般来讲：对于堆栈，链表表头做栈顶；对于队列，表头做队头，表尾做队尾
  原因 ：链表表头可删可增；链表表尾只可增不可删*/ 

/**** 二叉树 ****/
struct TreeNode{
	ElementType Data;
	Position LeftChild;
	Position RightChild;
}; 
typedef struct TreeNode *PtrToTreeNode;
typedef PtrToTreeNode BinTree;
typedef PtrToTreeNode Position;
typedef int ElementType;
//新建堆栈用于遍历
 
//操作集
BinTree CreatBinTree();
int IsEmptyTree(BinTree BT);
void PreOrderTraversal(BinTree BT);
void InOrderTraversal(BinTree BT);
void PostOrderTraversal(BinTree BT);
void LevelOrderTraversal(BinTree BT);











