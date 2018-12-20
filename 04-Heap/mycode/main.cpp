/****************************************
   >File Name:main.cpp
   >Author:Ju Wei
   >Mail:949413827@qq.com
   >Created Time: Thu 08 Nov 2018 07:44:37 PM CST
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
		int count;
		int capacity;

		void shiftUp(int k){
				while(k>1 && data[k/2] < data[k]){
						swap(data[k/2],data[k]);
						k /= 2;
				}
		}
		void shiftDown(int k){
				while(2*k <= count){
						int j =2*k;
						if(j+1 <= count && data[j+1] > data[j])
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
				this->capacity = capacity;
		}

		~MaxHeap(){
				delete [] data;
		}
		int size(){
				return count;
		}
		int isempty(){
				return count==0;
		}
		void insert(T item){
				assert(count+1 <= capacity);
				data[count+1] = item;
				count ++;
				shiftUp(count);
		}
		T extractMax(){
				assert(count>0);
				T ret =data[1];
				swap(data[1],data[count]);
				count --;
				shiftDown(1);
				return ret;
		}
		void printhelp(){
				for(int i=0;i<count;i++)
						cout<<data[i]<<"  ";
		}
};

int main(){
		MaxHeap<int> maxheap = MaxHeap<int>(100);
		srand(time(NULL));
		for(int i=0;i<50;i++){
				maxheap.insert( rand()%100 );
		}
		//cout<<maxheap.size()<<endl;
		while(!maxheap.isempty()){
				cout<<maxheap.extractMax()<<"  ";
		}
		//maxheap.printhelp();
		cout<<endl;
		return 0;
}

