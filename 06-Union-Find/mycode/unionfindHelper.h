/****************************************
   >File Name:unionfindHelper.h
   >Author:Ju Wei
   >Mail:949413827@qq.com
   >Created Time: Sat 15 Dec 2018 03:47:54 PM CST
****************************************/

#include <iostream>
#include <ctime>
#include "unionfind.h"
#include "unionfind2.h"
using namespace std;

namespace unionfindHelper{
	void testUF2(int n){
		srand(time(NULL));
		UF2::unionfind uf2 = UF2::unionfind(n);

		time_t startTime = clock();

		for(int i=0;i<n;i++){
			int a = rand()%n;
			int b = rand()%n;
			uf2.unionElem(a,b);
		}
		for(int i=0;i<n;i++){
			int a = rand()%n;
			int b = rand()%n;
			uf2.isConnected(a,b);
		}
		time_t endTime = clock();
		cout<<"UF2,"<<2*n<<","<<double(endTime-startTime)/CLOCKS_PER_SEC<<endl;
	}
	void testUF1(int n){
		srand(time(NULL));
		UF1::unionfind uf = UF1::unionfind(n);

		time_t startTime = clock();

		for(int i=0;i<n;i++){
			int a = rand()%n;
			int b = rand()%n;
			uf.unionElem(a,b);
		}
		for(int i=0;i<n;i++){
			int a = rand()%n;
			int b = rand()%n;
			uf.isConnected(a,b);
		}
		time_t endTime = clock();
		cout<<"UF1,"<<2*n<<","<<double(endTime-startTime)/CLOCKS_PER_SEC<<endl;
	}
}
