/****************************************
   >File Name:heap.h
   >Author:Ju Wei
   >Mail:949413827@qq.com
   >Created Time: Tue 13 Nov 2018 03:33:23 PM CST
****************************************/

#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

template<typename T>
class MaxHeap{
	private:
		T* data;
		int *index;
		int count;
		int capacity;

		void shiftUp(int k){
				while(k>1 && data[index[k/2]] < data[index[k]]){
						swap(index[k/2],index[k]);
						k /= 2;
				}
		}
		void shiftDown(int k){
				while(2*k <= count){
						int j =2*k;
						if(j+1 <= count && data[index[j+1]] > data[index[j]])
								j+=1;
						if(data[k]>=data[j])
								break;
						swap(data[k],data[j]);
						k=j;
				}
		}
	public:
		MaxHeap(int capacity){
				data = new T[capacity+1];
				count = 0;
				index = new int[capacity+1];
				this->capacity = capacity;
		}
		MaxHeap(T arr[],int n){
			data = new T[n+1];
			capacity = n;
			for(int i=0;i<n;i++)
				data[i+1] = arr[i];
			count = n;
			for(int i=count/2;i>0;i--)
				shiftDown(i);
		}

		~MaxHeap(){
				delete [] data;
				delete [] index;
		}
		int size(){
				return count;
		}
		int isempty(){
				return count==0;
		}
		void insert(int i,T item){
			assert(i+1>=1 && i+1 <=capacity);
			i+=1;
			data[i] = item;
			index[count+1] = i;

			count+=1;
			shiftUp(count);
		}
		T extract(){
			assert(count>0);
			T ret = data[index[1]];
			swap(index[1],index[count]);
			count--;
			shiftDown(1);
			return ret;

		}
		T extractindex(){
			assert(count>0);
			int ret = index[1]-1;
			swap(index[1],index[count]);
			count--;
			shiftDown(1);
			return ret;
		}
		void change(int i,T newItem){
			i+=1;
			data[i] = newItem;

			for(int j =1;j<=count;j++){
				if(index[j]==i){
					shiftUp(j);
					shiftDown(j);
					return;
				}
			}
		}
};

