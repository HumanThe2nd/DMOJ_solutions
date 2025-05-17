// COCI '16 Contest 1 #1 Tarifa
// Author: Dan Shan
// negative sum of array + length*constant
#include<stdio.h>
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
int main(int argc, char *argv[]) {
    int x=scan(),n=scan();
    int t=x*n+x;
    for(int i=0;i<n;i++){
        int a=scan();
        t-=a;
    }
    printf("%d\n",t);
}
