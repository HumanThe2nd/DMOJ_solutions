/*
Bob's Histogram
Author: Dan Shan
Date: 2025-02-18
Solve for y by finding average of elements and rounding to nearest integer 
calculate cost using (a[i]-y)^2 for each element
*/
#include <stdio.h>
#include <math.h>
#pragma GCC optimize("Ofast")
int main() {
    int n;
    scanf("%d",&n);
    double c=0;
    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        c+=a[i];
    }
    int y=round(c/n),res=0;
    for(int i=0;i<n;i++) res+=(a[i]-y)*(a[i]-y);
    printf("%d\n",res);
}
