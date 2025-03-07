/*
COCI '11 Contest 6 #1 Jack
Brute Force 3 nested loops
Author: HumanThe2nd
Date: 2025-03-06
Time complexity: O(n^3)
*/
#include <stdio.h>
int main() {
    int n,m,mx=0;
    scanf("%d %d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int ai=a[i]+a[j]+a[k];
                if(ai>mx&&ai<=m) mx=ai;
            }
        }
    }
    printf("%d\n",mx);
}
