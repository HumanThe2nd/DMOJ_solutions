/*
EGOI '22 P5 - Data Centers
Author: Dan Shan
Date: 2025-01-20
Updated: 2025-01-22
Priority queue: 77/100 subtask
Full Solution: Rebuild array with edited elements each query
Time Complexity: O(s*n)
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
    return (*(int*)b-*(int*)a);
}
int main(){
    buff();
    int n=scan(),s=scan();
    int a[n];
    for(int i=0;i<n;i++) a[i]=scan();
    qsort(a,n,sizeof(int),cmp);
    while(s--){
        int mi=scan(),ci=scan();
        for(int i=0;i<ci;i++) a[i]-=mi;
        int m[n];
        int i=0,j=ci,l=0;
        while(i<ci&&j<n){
            if(a[i]>a[j]) m[l++]=a[i++];
            else m[l++]=a[j++];
        }
        while(i<ci) m[l++]=a[i++];
        while(j<n) m[l++]=a[j++];
        for(i=0;i<n;i++) a[i]=m[i];
    }
    for(int i=0;i<n-1;i++) printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
}
