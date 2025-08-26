/*
BlueBook - Power Base
Author: Dan Shan
Date: 2025-08-26

*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        double x;
        int p;
        scanf("%lf %d",&x,&p);
        double res=x;
        for(int i=1;i<p;++i) res*=x;
        printf("%.2lf\n",res);
    }
}
