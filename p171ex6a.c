/*
BlueBook - Max
Author: Dan Shan
Date: 2025-08-14
Update max with each larger element
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n;
    double mx;
    scanf("%d %lf",&n, &mx);
    for(int i = 1; i < n; ++i){
        double ai;
        scanf("%lf",&ai);
        if(ai > mx) mx = ai;
    }
    printf("%.4lf\n",mx);
}
