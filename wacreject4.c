// Wesley's Anger Contest Reject 5 - Two Permutations
// Author: Dan Shan
// Theory: try each index from 1 to 1e4 storing past values.
// If current outputs match, break.
// If one of current matches with past numbers, print the past with the current then break.
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
int a[300001],b[300001];
int main(){
    int n=scan();
    for(int i=1;i<=n;i++){
        printf("%d %d\n",i,i);
        fflush(stdout);
        int ai=scan(),bi=scan();
        if(ai==bi) break;
        if(a[bi]) return printf("%d %d\n",a[bi],i)*0;
        if(b[ai]) return printf("%d %d\n",i,b[ai])*0;
        a[ai]=i; b[bi]=i;
    }
}
