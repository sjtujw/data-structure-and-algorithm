/****************************************
   >File Name:unionfind2.h
   >Author:Ju Wei
   >Mail:949413827@qq.com
   >Created Time: Sat 15 Dec 2018 04:28:42 PM CST
****************************************/

#include <iostream>
#include <cassert>
using namespace std;

namespace UF2{
	class unionfind2(){
		private:
			int* parent;
			int count;
		public:
			unionfind(int count){
				parent = new int[count];
				this->count = count;
				for(int i =0; i<count;i++)
					parent[i] = i;
			}
			~unionfind(){
				delete [] parent;
			}
			int find(int p){
				assert(p>=0 && p<count);
				while(p != parent[p])
					p = parent[p];
				return p;
			}
			bool isConnected(int p,int q){
				return find(p)==find(q);
			}
			void unionEle(int p,int q){
				int pRoot = find(p);
				int qRoot = find(q);
				if(pRoot==qRoot)
					return;
				parent[pRoot]=qRoot;
			}
	};
}
