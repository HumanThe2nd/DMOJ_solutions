// COCI '14 Contest 5 #3 Traktor
// By: Dan Shan
// Theory: store minimum x and y cords of to collect to up
// k mushrooms along diagonals and sides
// contains a template i got for fast input for integers
#include <stdio.h>
const int lim=1e5+1;

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
    int n,k,x[lim],y[lim],xd[lim],zd[2*lim];
    for(int i=0;i<lim;i++){
        x[i]=0; y[i]=0; xd[i]=0; zd[i]=0;
    }
    for(int i=lim;i<lim*2;i++)zd[i]=0;
    n=scan(); k=scan();
    for(int i=1;i<=n;i++){
        int xi,yi;
        xi = scan(); yi = scan();
        x[xi]++; y[yi]++;
        if(x[xi]==k || y[yi]==k) return 0*printf("%d\n",i);
        xd[xi-yi]++;
        zd[xi+yi]++;
        if(xd[xi-yi]==k || zd[xi+yi]==k) return 0*printf("%d\n",i);
    }
    printf("-1\n");
}
