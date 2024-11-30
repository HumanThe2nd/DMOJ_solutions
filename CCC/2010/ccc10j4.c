// CCC '10 J4 - Global Warming
// Author: Dan Shan
// brute force each frequency starting from 1
// special case: n=1 -> freq=0
#include <stdio.h>
int main() {
    while(1){
        int n;
        scanf("%d",&n);
        if(!n) break;
        int a[n-1],l,c=0;
        scanf("%d",&l);
        if(n==1){ // special case n=1
            printf("0\n");
            continue;
        }
        for(int i=0;i<n-1;i++){
            int ai;
            scanf("%d",&ai);
            a[i]=ai-l; l=ai;
        }
        for(c=1;c<n;c++){
            int f=1;
            for(int i=c;i<n-1;i++){
                if(a[i]!=a[i-c]) f=0;
            }
            if(f) break;
        }
        printf("%d\n",c);
    }
}
