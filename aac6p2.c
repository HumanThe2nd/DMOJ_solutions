/*
An Animal Contest 6 P2 - G-Pop
Author: Dan Shan
Date: 2025-01-15
store the minimal start time of each end time
keep track of earliest friend and their respective end time
max bands k: maximum interval a friend stays
change when: oldest friend doesn't leave
changing: done optimally by increasing by 1 each time modulo the max
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int scan() { // input template
    int num = 0;
    char c = getchar();
    while (c>'9'||c<'0') c = getchar();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar();
    }
    return num;
}
int main(){
    int n=scan(),q=scan(),ai=0;
    int a[n],l=1,k=0; // min start time
    for(int i=1;i<=n;i++) a[i]=i; // link end time to start time index
    while(q--){
        int li=scan(),ri=scan();
        if(ri-li>k) k=ri-li;
        if(ri>a[li]) a[li]=ri;
    }
    printf("%d\n1",++k);
    for(int i=1;i<n;i++){
        while(a[l]<=i&&l<i) l++;
        if(a[l]>i) ai++;
        putchar(' ');
        printf("%d",ai%k+1);
    }
    putchar('\n');
}
