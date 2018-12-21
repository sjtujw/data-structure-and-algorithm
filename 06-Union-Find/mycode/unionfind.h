/****************************************
   >File Name:unionfind.h
   >Author:Ju Wei
   >Mail:949413827@qq.com
   >Created Time: Sat 15 Dec 2018 03:37:38 PM CST
****************************************/

#include <iostream>
#include <cassert>
using namespace std;
namespace UF1{

class unionfind{
	private:
		int *id;
		int count;
	public:
		unionfind(int n){
			count = n;
			id = new int[n];
			for(int i=0;i<n;i++)
				id[i] = i;
		}
		~unionfind(){
			delete [] id;
		}
		int find(int p){
			assert(p>=0 && p<count);
			return id[p];
		}
		bool isConnected(int p,int q){
			return find(p)==find(q);
		}
		void unionElem(int p,int q){
			int pID = find(p);
			int qID = find(q);
			if (pID == qID)
				return;
			for(int i=0;i<count;i++)
				if(id[i]==pID)
					id[i]=qID;
		}
};
}
