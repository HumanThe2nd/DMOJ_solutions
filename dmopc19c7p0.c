/*
DMOPC '19 Contest 7 P0 - Contest Feedback
Author: Dan Shan
Date: 2025-03-02
Hard code each combination
formula: sum of elements / number of elements
*/
#include <stdio.h>
int main() {
    double a[4];
    scanf("%lf %lf %lf %lf",&a[0],&a[1],&a[2],&a[3]);
    for(int i=0;i<3;i++){ // condenses 2 element averages
        for(int j=i+1;j<4;j++) printf("%lf\n",(a[i]+a[j])/2);
    }
    printf("%lf\n%lf\n%lf\n%lf\n%lf\n",(a[0]+a[1]+a[2])/3,(a[0]+a[1]+a[3])/3,(a[0]+a[2]+a[3])/3,(a[1]+a[2]+a[3])/3,(a[0]+a[1]+a[2]+a[3])/4);
}
