/*
DWITE '11 R1 #2 - Penny Game
Author: Dan Shan
Date: 2024-10-07
Approach: find average 
          take the sum of pennies above average
*/ 
#include <stdio.h>
int main() {
    int tc=1;
    while(tc--){
        int n,t=0,c=0;
        scanf("%d",&n);
        int a[n];
        for(int j=0;j<n;j++) {
            scanf("%d",&a[j]);
            t+=a[j];
        }
        t/=n; // average
        for(int j=0;j<n;j++){
            if(a[j]>t) c+=a[j]-t;
        }
        printf("%d\n",c);
    }
}
