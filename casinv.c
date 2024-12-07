/*
Castle Invasion
Author: Dan Shan
Date: 2024-12-07
*/
#include <stdio.h>
#include<stdlib.h>
#pragma GCC optimize("Ofast")
long long scan() {
    long long num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int cmp(const void*a, const void*b){
    return (*(long long*)a-*(long long*)b);
}
int main() {
	long long n=scan();
    long long a[n],a2[n];
    for(int i=0;i<n;i++) a[i]=scan();
    for(int i=0;i<n;i++) a2[i]=scan();
    qsort(a,n,sizeof(long long),cmp);
    qsort(a2,n,sizeof(long long),cmp);
    if(a[n-1]!=a2[n-1]) return printf("-1\n")*0; // impossible
    long long i=0,j=0,c=0;
    while(i<n&&j<n){
        if(j<n&&a2[j]<a[i]){
            c+=a2[j]*(n-i);
            j++;
        }
        if(i<n&&j<n&&a[i]==a2[j]){
            c+=a[i]*(n-i)+a2[j]*(n-j)-a[i];
            i++; j++;
        }
        if(i<n&&a[i]<a2[j]){
            c+=a[i]*(n-j); i++;
        }
    }
    printf("%lld\n",c);
}
