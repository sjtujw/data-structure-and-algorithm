/*************************************************************************
    > File Name: Heap.h
    > Author: Ju Wei
    > Mail: 949413827@qq.com 
    > Created Time: Wed 14 Nov 2018 10:44:35 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

template<typename T>
class MaxHeap{
	private:
		T* data;
		int count;
		int capacity;

		void shiftup(int k){
			while(k>1 && data[k/2]<data[k]){
				swap(data[k/2],data[k]);
				k/=2;
			}
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
		int size(){
			return count;
		}
		bool isEmpty(){
			return count==0;
		}
		void insert(T item){
			assert(count+1 < capacity);
			data[count+1] = item;
			count+=1;
			shiftup(count);
		}
};

