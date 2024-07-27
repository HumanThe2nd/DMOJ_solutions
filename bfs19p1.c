// Back From Summer '19 P1: Winnie's Orphans
// Author: Dan Shan
// minimum searching 2d array
#include <stdio.h>
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
    int n=scan(),m=scan(),min,ind=0;
    min = m+1;
    for(int i=1;i<=n;i++){
        int c=0;
        for(int j=0;j<m;j++){
            int ai=scan();
            if(ai==1||ai==10)c++;
        }
        if(c<min){
            min=c; ind=i;
        }
    }
    printf("%d\n",ind);
}
