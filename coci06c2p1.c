// COCI '06 Contest 2 #1 R2
// By: Dan Shan
// s = (r1 + r2) / 2
// by algebra: r2 = 2 * s - r1
#include <stdio.h>
int main(int argc, char *argv[]) {
    int r,s;
    scanf("%d %d",&r,&s);
    printf("%d\n",2*s-r);
}
