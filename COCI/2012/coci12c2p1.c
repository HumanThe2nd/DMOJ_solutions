/*
COCI '12 Contest 2 #1 Mortadela
Author: Dan Shan
Date: 2024-12-11
minimum x/y ratio * 1000
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int main() {
	int x=scan(),y=scan(),n=scan();
    double m=(double)x/y;
    while(n--){
        int xi=scan(),yi=scan();
        double mi=(double)xi/yi;
        if(mi<m) m=mi;
    }
    printf("%0.2lf\n",m*1000);
}
