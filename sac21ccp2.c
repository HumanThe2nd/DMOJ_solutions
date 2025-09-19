/*
SAC '21 Code Challenge P2 - Littering
Author: Dan Shan
Date: 2025-09-18
1. Sort the trash in non-increasing
2. Take the first k pieces of trash (sum of those values)

TC: O(N * log(N))
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
    long long num=0,neg=1;
    while((*ptr<'0'||*ptr>'9')&&*ptr!='-')++ptr; // Skip non-digit characters
    while(*ptr=='-')++ptr,neg*=-1;
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num*neg;
}
int cmp(const void* a, const void* b) {
   return (*(int*)b - *(int*)a);
}
int main() {
    buff();
    int n = scan(), k = scan(), a[n];
    for(int i = 0; i < n; ++i) a[i] = scan();
    
    qsort(a, n, sizeof(int), cmp); // sort trash
    long long c = 0;
    for(int i = 0; i < k; ++i) c += a[i]; // count k trash
    printf("%lld\n",c);
}
