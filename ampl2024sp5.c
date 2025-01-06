/*
Amplitude Hackathon Summer '24 Problem 5 - Lunch Costs
Author: Dan Shan
Date: 2025-01-05
binary search optimal number of caterings 
for each search iterate over the array and compare the cost
*/
#include <stdio.h>
long long scan() {
    long long a=0;
    char c=getchar();
    while('0'<=c&&c<='9') a=a*10+c-'0',c = getchar();
    return a;
}
int main() {
    long long n=scan(),c=scan(),p=scan();
    long long d[n],l=0,r=1000000000;
    for(int i=0;i<n;i++) d[i]=scan();
    long long min=2e18,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        long long lc=(mid-1)*c*n,mc=mid*c*n,rc=(mid+1)*c*n; // potential costs
        for(int i=0;i<n;i++) if(mid<d[i])mc+=(d[i]-mid)*p;
        if(mc<min) min=mc;
        for(int i=0;i<n;i++){
            if(mid-1<d[i]) lc+=(d[i]-mid+1)*p; // uncatered
            if(mid+1<d[i]) rc+=(d[i]-mid-1)*p; // uncatered
        }
        if(mc<min) min=mc;
        if(lc<rc) r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n",min);
}
