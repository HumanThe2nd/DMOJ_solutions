// Cheerio Contest 2 P1 - Cow Pasture
// Author: Dan Shan
// absolute value float sorting
#include<stdio.h>
#include<math.h>
int scan() {
    int n = 0, a = 0;
    char c = getchar_unlocked();
    if (c == '-') n = 1, c = getchar_unlocked();
    while('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar_unlocked();
    return n ? -a : a;
}
int cmp (const void * a, const void * b) {
   if (*(long double*)a > *(long double*)b) return 1;
   else if (*(long double*)a < *(long double*)b) return -1;
   else return 0;
}

int main(int argc, char *argv[]) {
    int x=scan(),y=scan(),n=scan(),m=scan();
    long double a[n];
    for(int i=0;i<n;i++){
        int xi=scan(),yi=scan();
        a[i]=sqrt(pow(xi-x,2)+pow(yi-y,2));
    }
    qsort(a, n, sizeof(long double), cmp);
    printf("%0.8Lf\n",a[m-1]);
}
