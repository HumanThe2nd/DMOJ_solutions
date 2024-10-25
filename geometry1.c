// Troubling Triangles
// Author: Dan Shan
// Date: 2024-10-24
// Shoelace theorem + euclidian formula for coordinates
#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    while (n--) {
        long long x, y, x2, y2, x3, y3;
        scanf("%lld %lld %lld %lld %lld %lld",&x,&y,&x2,&y2,&x3,&y3);
        double a=0.5*fabs(x*(y2-y3)+x2*(y3-y)+x3*(y-y2));
        double p=sqrt(pow(x2-x,2)+pow(y2-y,2));
        double p2=sqrt(pow(x3-x,2)+pow(y3-y,2));
        double p3=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
        printf("%0.2lf %0.2lf\n",a,p+p2+p3);
    }
}
