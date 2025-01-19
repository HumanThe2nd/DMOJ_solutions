/*
Bubble Cup V9 D Potions homework
Author: Dan Shan
Date: 2025-01-18
sort the laziness, assign the laziest the easiest
multiply each ascneding element with its respective descending element
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<20 // buffer size
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
    long long n=scan(),a[n],c=0;
    for(int i=0;i<n;i++) a[i]=scan();
    qsort(a,n,sizeof(long long),cmp);
    for(int i=0;i<n;i++) c+=a[i]*a[n-i-1];
    printf("%lld\n",c%10007);
}
