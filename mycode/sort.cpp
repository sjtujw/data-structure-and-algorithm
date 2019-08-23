#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void print_vector(vector<int> str){
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<' ';
    }
    cout<<endl;
}
//每趟选一个剩下的数组里面最小的，和第i个交换。
void SelectSort(vector<int> &str){
    int min;
    for(int i=0;i<str.size();i++){
        min = str[i];
        for(int j=i+1;j<str.size();j++){
            if(str[j]<min){
                int tmp;
                tmp = min;
                min = str[j];
                str[j] = tmp;
            }
        }
        str[i]=min;
    }
}
//每趟比较相邻的两个数，大数慢慢后移，形如一个冒泡
void BubbleSort(vector<int> &str){
    int tmp;
    for(int i=0;i<str.size()-1;i++){
        for(int j=0;j<str.size()-i-1;j++){
            if(str[j]>str[j+1]){
                tmp = str[j+1];
                str[j+1] = str[j];
                str[j] = tmp;
            }
            else
                continue;
        }
    }
}
//从头开始，假设前面是已经排序的，寻找下一个待排序元素在前面的插入位置
void InsertSort(vector<int> &str){
    int sz = str.size();
    for(int i=0;i<sz;i++){
        int tmp = str[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(tmp<str[j])
                str[j+1]=str[j];
            else
                break;
        }
        str[j+1]=tmp;
    }
}
int _partion(vector<int> &str,int l,int r){
    swap(str[l],str[rand()%(r-l+1)+l]);
    int v = str[l];
    int i=l+1,j=r;
    while(true){
        while(i<=r && str[i]<v)
            i++;
        while(j>=l+1 && str[j]>v)
            j--;
        if(i>j)
            break;
        swap(str[i],str[j]);
        i++;
        j--;
    }
    swap(str[l],str[j]);
    return j;
}
void _QuickSort(vector<int> &str, int l,int r){
    if(r-l<=15){
        InsertSort(str);
        return;
    }
    int p = _partion(str, l, r);
    _QuickSort(str, 0, p-1);
    _QuickSort(str, p+1, r);
}
void QuickSort(vector<int> &str,int n){
    srand(time(NULL));
    _QuickSort(str,0,n-1);

}
int main(){
    vector<int> str={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    int n = str.size();
    print_vector(str);
    //InsertSort(str);
    //BubbleSort(str);
    //SelectSort(str);
    QuickSort(str,n);
    print_vector(str);
    int s;
    cin>>s;
    return 0;
}