/*
ACM U of T Tryouts C1 B - The Foxen's Treasure
Author: Dan Shan
Date: 2024-12-21
Brute force simulation  up to limit (47000 in this code)
The total cycle time is the sum of the awake and sleep time
use modulus to find state at each time up to the limit
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int main() {
    int t=scan();
    while(t--){
        int n=scan();
        int a[n],b[n],c[n],i;
        for(i=0;i<n;i++){
            a[i]=scan(); b[i]=scan(); c[i]=scan();
            b[i]+=a[i];
        } // if c[i] mod b[i] > a[i] then fox is asleep
        for(i=0;i<47000;i++){
            int f=1;
            for(int j=0;j<n;j++){
                if(c[j]%b[j]<a[j]) f=0; // fox awake
                c[j]++;
            }
            if(f) break;
        }
        if(i==47000) puts("Foxen are too powerful");
        else printf("%d\n",i);
    }
}
