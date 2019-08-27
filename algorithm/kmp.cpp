#include <bits/stdc++.h>

using namespace std;

int kmpmatch(char *s,char *p){
    int i=0,j=0;
    int slen = strlen(s);
    int plen = strlen(s);
    while(i<slen && j<plen){
        if(j==-1 || s[i]==p[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    if(j==plen)
        return i-j;
    else
        return -1;
}

int main(){
    return 0;
}