/*
PEG Test '14 - Fire
Author: Dan Shan
Date: 2025-01-31
sort the array, double the first element (if k!=0)
if there are elements that aren't doubled, take the minimum of that and the doubled first element
Note: statement is incorrect, k may be zero
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<22 // buffer size
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
int main(){
    buff();
    int n=scan(),k=scan();
    int a[n];
    for(int i=0;i<n;i++) a[i]=scan();
    qsort(a,n,sizeof(int),cmp);
    if(k) a[0]<<=1;
    if(k>=n){ // all leaves
        k=n-1;
        if(k) a[k]<<=1; // double the max leaf
    } if(a[k]<a[0]) a[0]=a[k];
    printf("%d\n",a[0]);
}
