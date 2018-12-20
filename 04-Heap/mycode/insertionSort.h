#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void insertSort(T arr[],int n){
    for (int i=1;i<n;i++){
        for(int j=i;j>0 && arr[j]<arr[j-1];j--){
                swap(arr[j],arr[j-1]);
        }
    }
}

template<typename T>
void insertSort(T arr[],int l,int r){

    for(int i=l+1;i<=r;i++){
        T e=arr[i];
        int j;
        for(j=i;j>l&&arr[j-1]>e;j--)
            arr[j] = arr[j-1];
        arr[j]=e;
    }
    return;
}

#endif // INSERTIONSORT_H_INCLUDED
