/****************************************
   >File Name:heap.cpp
   >Author:Ju Wei
   >Mail:949413827@qq.com
   >Created Time: Sat 10 Nov 2018 04:34:58 PM CST
****************************************/

#include <iostream>
#include <algorithm>
#include "heap.h"
#include "SortTestHelper.h"


using namespace std;

template<typename T>
void __shiftDown(T arr[],int n,int k){
	while(2*k+1<n){
		int j=2*k+1;
		if(j+1 < n && arr[j] < arr[j+1])
			j+=1;
		if(arr[k]>=arr[j])
			break;
		swap(arr[k],arr[j]);
		k=j;
	}
}

template<typename T>
void heapSort1(T arr[],int n){
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for(int i=0;i<n;i++)
		maxheap.insert(arr[i]);
	for(int i=n-1;i>=0;i--)
		arr[i] = maxheap.extract();
}
template<typename T>
void heapSort2(T arr[],int n){
	MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
	for(int i=n-1;i>=0;i--)
		arr[i] = maxheap.extract();
}

template<typename T>
void selfheapSort(T arr[],int n){
	for(int i=(n-1)/2;i>=0;i--)
		__shiftDown(arr,n,i);
	for(int i=n-1;i>0;i--){
		swap(arr[0],arr[i]);
		__shiftDown(arr,i,0);
	}
}

int main(){
	int n=10000;

	int* arr = SortTestHelper::generateRandomArray(n,0,n);
	int* arr2 = SortTestHelper::copyIntArray(arr,n);
	int* arr3 = SortTestHelper::copyIntArray(arr,n);

	SortTestHelper::testSort("Heap Sort 1",heapSort1,arr,n);
	SortTestHelper::testSort("Heap Sort 2",heapSort2,arr2,n);
	SortTestHelper::testSort("Self Heap Sort",selfheapSort,arr3,n);
//	SortTestHelper::printArray(arr,n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	cout<<endl;
	return 0;

}

