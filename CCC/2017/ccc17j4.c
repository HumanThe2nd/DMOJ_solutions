// CCC '17 J4 - Favourite Times
// Author: Dan Shan
// Observation: every 720 minutes 31 arithmetic sequences occur
// Modulo input by 720 and add 31*(d/720) to optimize
#include <stdio.h>
int main() {
    int n,h=12,m=0;
    scanf("%d",&n);
    int c=(n/720)*31; n%=720;
    while(n--){
        m++;
        if(m>59) h++;
        m%=60;
        if(h>12) h%=12;
        int d=h%10-h/10,d2=m/10-h%10,d3=m%10-m/10;
        if(h<10)d=d2; // remove trailing 0
        if(d==d2&&d2==d3) c++;
    }
    printf("%d\n",c);
}
