/*
CPC '19 Contest 1 P2 - Luggage
Author: Dan Shan
Date: 2025-05-20
1. sort items (ascending in this code)
2. Use a sliding window to find max included elements
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    buff();
    int n=scan(),k=scan(),l=0,m=0;
    int a[n];
    for(int i=0;i<n;i++) a[i]=scan();
    qsort(a,n,sizeof(int),cmp);
    for(int i=1;i<n;++i){
        while(a[i]-a[l]>k) l++;
        if(i-l>m) m=i-l;
    }
    printf("%d\n",m+1);
}
