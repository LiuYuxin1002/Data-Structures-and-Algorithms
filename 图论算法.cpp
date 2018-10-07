#include<stdio.h> 
#include<stdlib.h>

/**** 图的表示 ****/ 
//定义边 
typedef struct AdjVNode *PtrToAdjVNode;
typedef PtrToAdjVNode Position;
//typedef PtrToAdjVNode Edge;
typedef int Vertex; 
typedef int WeightType;
struct AdjVNode{
	Vertex AdjV;//邻接表节点下标 
	WeightType Weight;//边权重
	Position Next; 
};
//定义真正的边？？？
struct GEdge{
	Vertex V1;
	Vertex V2;
	WeightType Weight;
}; 
typedef struct GEdge *Edge;

//定义邻接表
#define MaxVertexNum 10
//typedef int DataType;
typedef struct VNode{
	PtrToAdjVNode FirstEdge;
//	DataType Data;
}AdjList[MaxVertexNum];

//定义图
typedef struct GNode *PtrToGNode;
typedef PtrToGNode LGraph;
struct GNode{
	int Ne;//边个数
	int Nv;//节点个数
	AdjList G;//邻接表 
};

/****为BFS建立一个队列****/
typedef struct Node *PtrToNode;
typedef Vertex ElementType;
struct Node{
	ElementType Data;
	PtrToNode Next;
};
typedef struct QNode *Queue;
struct QNode{
	PtrToNode Head;
	PtrToNode Rear;
}; 
void Enqueue(Queue Q,ElementType X);
ElementType Dequeue(Queue Q);
Queue MakeEmpty();
//实现
Queue MakeEmpty(){
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Head=NULL;
	Q->Rear=NULL;
} 
void Enqueue(Queue Q, ElementType X){
	PtrToNode New = (PtrToNode)malloc(sizeof(struct Node));
	New->Next=NULL;
	New->Data=X;
	if(Q->Head==NULL&&Q->Rear==NULL){//空队列 
		Q->Head=New;
		Q->Rear=New;
	} 
	else{
		Q->Rear->Next=New;
	} 
}
ElementType Dequeue(Queue Q){
	ElementType Del = Q->Head->Data;
	PtrToNode Temp = (PtrToNode)malloc(sizeof(struct Node));
	Temp=Q->Head;
	if(Q->Head==Q->Rear){//只有一个元素 
		Q->Head=Q->Rear=NULL;
	} 
	else{
		Q->Head=Q->Head->Next;
	} 
	free(Temp);
	return Del;
}

/****定义操作集****/
LGraph CreateGraph(int VertexNum);//初始化一个有VertexNum个顶点但没有边的图
void InsertEdge(LGraph Graph, Edge E); //向LGraph中插入边
void DFS(LGraph Graph);//深度优先搜索
void BFS(LGraph Gtaph);//广度优先搜索
/****操作集实现****/
LGraph CreateGraph(int VertexNum){
	Vertex V,W;
	LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Ne=0;
	Graph->Nv=VertexNum;
	for(V=0;V<Graph->Nv;V++){
		Graph->G[V].FirstEdge=NULL;
	}
	return Graph;
} 
void InsertEdge(LGraph Graph, Edge E){//E(V1,V2,Weight):把V2插入角标V1的链表头上 
	Graph->Ne++;
	Graph->Nv++;
	Position NewNode = (Position)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV=E->V2;
	NewNode->Weight=E->Weight;
	//插入
	NewNode->Next=Graph->G[E->V1].FirstEdge; 
	Graph->G[E->V1].FirstEdge=NewNode;
	/**无向图，插入<V2,V1>**/
	Position NewNode2 = (Position)malloc(sizeof(struct AdjVNode));
	NewNode2->AdjV=E->V1;
	NewNode2->Weight=E->Weight;
	//插入
	NewNode2->Next=Graph->G[E->V2].FirstEdge; 
	Graph->G[E->V2].FirstEdge=NewNode2;
}
int visit[MaxVertexNum]={0};
void DFS(LGraph Graph, Vertex V){//从V开始 ,递归解法,使用前初始化visit 
	visit[V]=1;
	Position Visitor = (Position)malloc(sizeof(struct AdjVNode));
	Visitor=Graph->G[V].FirstEdge;
	while(Visitor!=NULL){
		if(visit[Visitor->AdjV]==0){
			DFS(Graph,Visitor->AdjV);	
		}
		Visitor=Visitor->Next;
	}
}
void BFS(LGraph Graph,Vertex V){//从V开始，非递归解法，使用前初始化visit 
	visit[V]=1;
	Queue Q = MakeEmpty();
	Enqueue(Q,V);
	while(Q->Head!=NULL){//队列不为空 
		V=Dequeue(Q);
		Position W = Graph->G[V].FirstEdge;
		while(W!=NULL){
			if(visit[W->AdjV]==0){
				visit[W->AdjV]=1;
				Enqueue(Q, W->AdjV);
			}
			W=W->Next;
		}
	}
}

int main(){
	printf("图论算法 详见代码");
	return 1;
}







