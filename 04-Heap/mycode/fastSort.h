#ifndef FASTSORT_H_INCLUDED
#define FASTSORT_H_INCLUDED

#include <iostream>
#include <algorithm>
#include "mergeSort.h"
#include "SortTestHelper.h"

using namespace std;
//对arr[l,r]进行partition操作
template<typename T>
int __partition(T arr[],int l,int r){

    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    //arr[l+1,,,j]<v;arr[j+1...i]>v;
    int j=l;
    for(int i=l+1;i<=r;i++){
        if(arr[i]<v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}

template<typename T>
void __quickSort(T arr[],int l,int r){
    //if(l>=r)
    //    return;
    if(r-l<=15){
        insertSort(arr,l,r);
        return;
    }
    int p=__partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);

}

template<typename T>
void quickSort(T arr[],int n){
    srand(time(NULL));
    __quickSort(arr,0,n-1);
}
#endif // FASTSORT_H_INCLUDED
