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
	H->Element = malloc(sizeof(ElementType)*(MaxSize+1));
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
