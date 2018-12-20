#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <iostream>
#include <algorithm>
#include "insertionSort.h"

using namespace std;

template<typename T>
void __merge(T arr[],int l,int mid, int r){
    T aux[r-l+1];
    for (int i=l;i<=r;i++)
        aux[i-l]=arr[i];

    int i=l,j=mid+1;
    for (int k=l;k<=r;k++){
        if(i>mid){
            arr[k] = aux[j-l];
            j++;
        }
        else if(j>r){
            arr[k] = aux[i-l];
            i++;
        }
        else if(aux[i-l]<aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}
//递归排序，对arr[l,r]的范围进行排序
template<typename T>
void __mergeSort(T arr[],int l,int r){
//    if(l>=r)
//        return;
    if(r-l<16){
        insertSort(arr,l,r);
        return;    //小数组实行插入排序来改进算法
    }

    int mid =(l+r)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    if(arr[mid]>arr[mid+1])
        __merge(arr,l,mid,r);
}

template<typename T>
void mergesort(T arr[],int n){
    __mergeSort(arr,0,n-1);
}

template<typename T>
void mergesortBU(T arr[],int n){
    for(int sz = 1;sz<=n;sz+=sz)
        for(int i=0;i<n;i+=sz+sz)
            __merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));
}
#endif // MERGESORT_H_INCLUDED
