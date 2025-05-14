// DMOPC '14 Contest 5 P2 - Longest Tunnel
// By: Dan Shan
// Date: 2024-10-14
// maximum calculator
#include <stdio.h>
int main() {
    int n,m=0;
    scanf("%d",&n);
    while(n--){
        int ai,bi;
        scanf("%d %d",&ai,&bi);
        bi-=ai;
        if(bi>m) m=bi;
    }
    printf("%d\n",m);
}
