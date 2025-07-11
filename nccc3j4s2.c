#include <stdio.h>
/*
Mock CCC '18 Contest 3 J4/S2 - A Median Problem
Author: Dan Shan
Date: 2025-07-10

1. Compute and store median of each subarray in global array
2. Compute and return median of global array
*/
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0,neg=1;
    while((*ptr<'0'||*ptr>'9')&&*ptr!='-')++ptr; // Skip non-digit characters
    while(*ptr=='-')++ptr,neg*=-1;
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num*neg;
}
int cmp(const void*a, const void*b) {
   return(*(int*)a-*(int*)b);
}
int main(){
    buff();
    int n=scan();
    int a[n],ai[n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) ai[j]=scan();
        qsort(ai,n,sizeof(int),cmp);
        a[i]=ai[n>>1];
    }
    qsort(a,n,sizeof(int),cmp);
    printf("%d\n",a[n>>1]);
}
