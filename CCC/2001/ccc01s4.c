/*
Author: Dan Shan 
Date: 2025-02-19
Find distance that covers every 2 points (and 3 points for non-obtuse triangles)
3 points: d = (abc/2)*sqrt(s(s-a)(s-b)(s-c)
take the maximum of all possible combinations
*/
#include <stdio.h>
#include <math.h>
#pragma GCC optimize("Ofast")
int main() {
    int n;
    scanf("%d",&n);
    if(n==1) return puts("0")*0;
    int x[n],y[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    double mx=0;
    for(int i=0;i<n;i++){
        int xi=x[i],yi=y[i];
        for(int j=i+1;j<n;j++){ // 2 points
            int xj=x[j],yj=y[j];
            double a=sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj)); // 2 points
            if(a>mx) mx=a;
            for(int k=j+1;k<n;k++){
                int xk=x[k],yk=y[k];
                double b=sqrt((xi-xk)*(xi-xk)+(yi-yk)*(yi-yk));
                double c=sqrt((xk-xj)*(xk-xj)+(yk-yj)*(yk-yj));
                if(a*a+b*b<c*c||a*a+c*c<b*b||b*b+c*c<a*a) continue; // skip obtuse
                double s=(a+b+c)/2; // semiperimeter
                double di=a*b*c/(2*sqrt(s*(s-a)*(s-b)*(s-c)));
                if(di>mx) mx=di;
            }
        }
    }
    printf("%0.2lf\n",mx);
}
