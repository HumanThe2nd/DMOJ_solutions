/*
Yet Another Contest 9 P3 - Divide and Delete
Author: Dan Shan
Date: 2025-02-17
run a sieve to precompute largest prime factor of numbers in the array
largest prime factor an element: minimum prefix length to use the element
iterate backwards adding the max prefix length to the number of ways while updating right boundary
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // buffer size
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // fast input template
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int cmp(const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}
int p[1000001]; // largest prime factor
int main(){
    buff();
    int n=scan();
    int a[n],s[n+1],s2[n+1],r=0,m=0; // blocks -> s: value, s2: index
    for(int i=0;i<n;i++) {
        a[i]=scan();
        if(a[i]>m) m=a[i]; // max element
    } p[1]=1;
    for(int i=2;i<=m;i++){
        if(p[i]) continue; // not prime
        for(int j=i;j<=m;j+=i) p[j]=i; // update max prime
    }
    long long c=0;
    for(int i=n-1;i>=0;i--){
        s[r]=p[a[i]]-1; s2[r++]=i;
        while(r&&s[r-1]<=s2[r-1]-i) r--; // remove blocks
        if(r) c+=s2[r-1]-i;
        else c+=n-i;
    }
    printf("%lld\n",c);
}
