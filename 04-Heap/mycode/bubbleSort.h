#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void BubbleSort(T arr[],int n){
    //for (int i=0;i<n-1;i++){
    //    for (int j=0;j<n-1 && arr[j]>arr[j+1];j++){
    //        swap(arr[j],arr[j+1]);
    //    }
    //}
    bool swapped;
    do{
        swapped = false;
        for( int i = 1 ; i < n ; i ++ )
            if( arr[i-1] > arr[i] ){
                swap( arr[i-1] , arr[i] );
                swapped = true;
            }
        n --;
    }while(swapped);
}

#endif // BUBBLESORT_H_INCLUDED
