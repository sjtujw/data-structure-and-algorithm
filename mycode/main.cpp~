/*************************************************************************
    > File Name: main.cpp
    > Author: Ju Wei
    > Mail: 949413827@qq.com 
    > Created Time: Fri 09 Nov 2018 06:50:24 AM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template<typename T>
class MaxHeap{
	private:
		T* data;
		int count;
		int capacity;

		void shiftUp(int k){
			while(k>1 && data[k]>data[k/2])
				swap(data[k],data[k/2]);
				k /= 2;
		}

	public:
		MaxHeap(int capacity){
			data = new T[capacity+1];
			count = 0;
			this->capacity = capacity;
		}
		~MaxHeap(){
			delete [] data;
		}
		bool isEmpty(){
			return count==0;
		}
		int size(){
			return count;
		}
		void insertHeap(T item){
			assert(count+1 <= capacity);
			data[count+1] = item;
			count+=1;
			shiftUp(count);
		}
};

int main(){
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout<<maxheap.size()<<endl;

	srand(time(NULL));
	for(int i=0;i<20;i++)
		maxheap.insertHeap(rand()%100);
	return 0;
}
