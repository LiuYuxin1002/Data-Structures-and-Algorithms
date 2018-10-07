#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct HeapStruct *MaxHeap;
typedef int ElementType;
struct HeapStruct{
	ElementType *Element;
	int HeapSize;//当前个数 
	int Capacity;//最大容量 
}; 

MaxHeap Create(int MaxSize);
void Insert(MaxHeap H, ElementType X);
ElementType DeleteMax(MaxHeap H);

MaxHeap Create(int MaxSize){
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->Element = (int*)malloc(sizeof(ElementType)*(MaxSize+1));
	H->HeapSize = 0;
	H->Capacity = MaxSize;
	H->Element[0] = -1;//小于堆中所有元素的值
	return H; 
}

void Insert(MaxHeap H, ElementType X){
	int i;
	if(H->Capacity == H->HeapSize){
		cout<<"堆已满，无法插入"<<endl;
		return;
	}
	i = ++H->HeapSize;//size自增后赋值给i
	for(;X>H->Element[i/2];i/=2){
		H->Element[i] = H->Element[i/2];//向下过滤
	} 
	H->Element[i] = X;//将X插入 
}

ElementType Delete(MaxHeap H){
	/*思路：1.删除并保存根节点，把最后一位提到根节点位置；
	2.根节点与左右儿子比较，和较大儿子进行交换；
	3.循环至不能交换，将根节点赋值给该位置*/
	if(H->HeapSize==0){
		cout<<"堆是空的"<<endl;
		return -1; 
	}
	int max = H->Element[1];/*保存最大值*/
	int temp = H->Element[H->HeapSize--];/*存好最后一位并减小堆size*//*1*/
	int parent, child;
	for(parent = 1;parent*2<=H->HeapSize;parent=child){/*条件：有子节点*/ 
		child = parent*2;
		if(child<=H->HeapSize && H->Element[child]<H->Element[child+1]) child++;/*条件：有子节点且右子节点更大*/
		if(H->Element[child]<=temp) break;/*更大的子节点小于最后一位节点的话，退出*/
		else H->Element[parent]=H->Element[child]; /*更大的子节点大于最后一位节点的话，交换*//*2*/ 
	} 
	H->Element[parent]=temp;//上面的所有交换其实都是赋值，最后是3步交换的第三步 /*3*/
	return max;
} 

int main(){
	vector<int> vi{6, 1, 2, 5, 3, 4};
	for(int i : vi){
		printf("%d ",i);
	}
	cout<<endl;
	make_heap(vi.begin(), vi.end());
	for(int i : vi){
		printf("%d ",i);
	}
	
	return 0;
}
