#include<stdio.h> 
#include<stdlib.h>

/**** ͼ�ı�ʾ ****/ 
//����� 
typedef struct AdjVNode *PtrToAdjVNode;
typedef PtrToAdjVNode Position;
//typedef PtrToAdjVNode Edge;
typedef int Vertex; 
typedef int WeightType;
struct AdjVNode{
	Vertex AdjV;//�ڽӱ�ڵ��±� 
	WeightType Weight;//��Ȩ��
	Position Next; 
};
//���������ıߣ�����
struct GEdge{
	Vertex V1;
	Vertex V2;
	WeightType Weight;
}; 
typedef struct GEdge *Edge;

//�����ڽӱ�
#define MaxVertexNum 10
//typedef int DataType;
typedef struct VNode{
	PtrToAdjVNode FirstEdge;
//	DataType Data;
}AdjList[MaxVertexNum];

//����ͼ
typedef struct GNode *PtrToGNode;
typedef PtrToGNode LGraph;
struct GNode{
	int Ne;//�߸���
	int Nv;//�ڵ����
	AdjList G;//�ڽӱ� 
};

/****ΪBFS����һ������****/
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
//ʵ��
Queue MakeEmpty(){
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Head=NULL;
	Q->Rear=NULL;
} 
void Enqueue(Queue Q, ElementType X){
	PtrToNode New = (PtrToNode)malloc(sizeof(struct Node));
	New->Next=NULL;
	New->Data=X;
	if(Q->Head==NULL&&Q->Rear==NULL){//�ն��� 
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
	if(Q->Head==Q->Rear){//ֻ��һ��Ԫ�� 
		Q->Head=Q->Rear=NULL;
	} 
	else{
		Q->Head=Q->Head->Next;
	} 
	free(Temp);
	return Del;
}

/****���������****/
LGraph CreateGraph(int VertexNum);//��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
void InsertEdge(LGraph Graph, Edge E); //��LGraph�в����
void DFS(LGraph Graph);//�����������
void BFS(LGraph Gtaph);//�����������
/****������ʵ��****/
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
void InsertEdge(LGraph Graph, Edge E){//E(V1,V2,Weight):��V2����Ǳ�V1������ͷ�� 
	Graph->Ne++;
	Graph->Nv++;
	Position NewNode = (Position)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV=E->V2;
	NewNode->Weight=E->Weight;
	//����
	NewNode->Next=Graph->G[E->V1].FirstEdge; 
	Graph->G[E->V1].FirstEdge=NewNode;
	/**����ͼ������<V2,V1>**/
	Position NewNode2 = (Position)malloc(sizeof(struct AdjVNode));
	NewNode2->AdjV=E->V1;
	NewNode2->Weight=E->Weight;
	//����
	NewNode2->Next=Graph->G[E->V2].FirstEdge; 
	Graph->G[E->V2].FirstEdge=NewNode2;
}
int visit[MaxVertexNum]={0};
void DFS(LGraph Graph, Vertex V){//��V��ʼ ,�ݹ�ⷨ,ʹ��ǰ��ʼ��visit 
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
void BFS(LGraph Graph,Vertex V){//��V��ʼ���ǵݹ�ⷨ��ʹ��ǰ��ʼ��visit 
	visit[V]=1;
	Queue Q = MakeEmpty();
	Enqueue(Q,V);
	while(Q->Head!=NULL){//���в�Ϊ�� 
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
	printf("ͼ���㷨 �������");
	return 1;
}







