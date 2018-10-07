#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct HeapStruct *MaxHeap;
typedef int ElementType;
struct HeapStruct{
	ElementType *Element;
	int HeapSize;//��ǰ���� 
	int Capacity;//������� 
}; 

MaxHeap Create(int MaxSize);
void Insert(MaxHeap H, ElementType X);
ElementType DeleteMax(MaxHeap H);

MaxHeap Create(int MaxSize){
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
	H->Element = (int*)malloc(sizeof(ElementType)*(MaxSize+1));
	H->HeapSize = 0;
	H->Capacity = MaxSize;
	H->Element[0] = -1;//С�ڶ�������Ԫ�ص�ֵ
	return H; 
}

void Insert(MaxHeap H, ElementType X){
	int i;
	if(H->Capacity == H->HeapSize){
		cout<<"���������޷�����"<<endl;
		return;
	}
	i = ++H->HeapSize;//size������ֵ��i
	for(;X>H->Element[i/2];i/=2){
		H->Element[i] = H->Element[i/2];//���¹���
	} 
	H->Element[i] = X;//��X���� 
}

ElementType Delete(MaxHeap H){
	/*˼·��1.ɾ����������ڵ㣬�����һλ�ᵽ���ڵ�λ�ã�
	2.���ڵ������Ҷ��ӱȽϣ��ͽϴ���ӽ��н�����
	3.ѭ�������ܽ����������ڵ㸳ֵ����λ��*/
	if(H->HeapSize==0){
		cout<<"���ǿյ�"<<endl;
		return -1; 
	}
	int max = H->Element[1];/*�������ֵ*/
	int temp = H->Element[H->HeapSize--];/*������һλ����С��size*//*1*/
	int parent, child;
	for(parent = 1;parent*2<=H->HeapSize;parent=child){/*���������ӽڵ�*/ 
		child = parent*2;
		if(child<=H->HeapSize && H->Element[child]<H->Element[child+1]) child++;/*���������ӽڵ������ӽڵ����*/
		if(H->Element[child]<=temp) break;/*������ӽڵ�С�����һλ�ڵ�Ļ����˳�*/
		else H->Element[parent]=H->Element[child]; /*������ӽڵ�������һλ�ڵ�Ļ�������*//*2*/ 
	} 
	H->Element[parent]=temp;//��������н�����ʵ���Ǹ�ֵ�������3�������ĵ����� /*3*/
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
