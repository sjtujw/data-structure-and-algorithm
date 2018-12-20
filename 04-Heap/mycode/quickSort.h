#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include <iostream>
#include <algorithm>
#include "mergeSort.h"
#include "SortTestHelper.h"

using namespace std;
//¶Ôarr[l,r]½øÐÐpartition²Ù×÷
template<typename T>
int __partition2(T arr[],int l,int r){

    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    //arr[l+1,i]<=v;arr[j,r]>=v;
    int i=l+1,j=r;
    while(true){
        while(i<=r && arr[i]<v) i++;
        while(j>l+1 && arr[j]>v) j--;
        if(i>j) break;
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    swap(arr[l],arr[j]);

//    swap(arr[l],arr[rand()%(r-l+1)+l]);
//    T v = arr[l];
//    //arr[l+1,,,j]<v;arr[j+1...i]>v;
//    int j=l;
//    for(int i=l+1;i<=r;i++){
//        if(arr[i]<v){
//            swap(arr[j+1],arr[i]);
//            j++;
//        }
//    }
//    swap(arr[l],arr[j]);
    return j;
}

template<typename T>
void __quickSort2(T arr[],int l,int r){
    //if(l>=r)
    //    return;
    if(r-l<=15){
        insertSort(arr,l,r);
        return;
    }
    int p=__partition2(arr,l,r);
    __quickSort2(arr,l,p-1);
    __quickSort2(arr,p+1,r);

}

template<typename T>
void quickSort2(T arr[],int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}

#endif // QUICKSORT_H_INCLUDED
