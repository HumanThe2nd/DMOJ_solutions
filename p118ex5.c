/*
BlueBook - Max is Last
Author: Dan Shan
Date: 2025-08-09
1. store max and its index
2. print it last
*/
#include <stdio.h>
int main() {
    int n,ind;
    scanf("%d",&n);
    double m=-2e9,a[n];
    for(int i=0;i<n;++i){
        scanf("%lf",&a[i]);
        if(a[i]>m) m=a[i], ind=i;
    }
    for(int i=0;i<n;++i){
        if(i==ind)continue;
        printf("%0.2lf ",a[i]);
    }
    printf("%0.2lf\n",a[ind]);
}
