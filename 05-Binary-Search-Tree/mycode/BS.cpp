/****************************************
   >File Name:BS.cpp
   >Author:Ju Wei
   >Mail:949413827@qq.com
   >Created Time: Tue 04 Dec 2018 09:17:36 PM CST
****************************************/

#include <iostream>
using namespace std;

template<typename T>
int bs(T arr[],int n,T target){
	int l=0,r=n-1;
	while(l<=r){
		//int mid = (l+r)/2;
		int mid = l+(r-l)/2;
		if(arr[mid] == target)
			return mid;
		if(arr[mid] < target)
			l = mid+1;
		else
			r = mid-1;
	}
	return -1;
}

int main(){

	return 0;
}
