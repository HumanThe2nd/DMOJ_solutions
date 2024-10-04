// CCC '02 S4 - Bridge Crossing
// Author: Dan Shan
// dp least time for each person and the added person
// find the path to the optimal and print
#include <stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
int dp[101],p[101]; // parent array
int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    int a[q];
    for(int i=1;i<=q;i++) dp[i]=2e9;
    char s[q][100];
    for(int i=0;i<q;i++) {
        scanf("%s%d",s[i],&a[i]);
    }
    for(int i=0;i<q;i++){
        int m=0;
        for(int j=0;j<n;j++){
            m=max(m,a[i+j]);
            if(dp[i]+m<dp[i+j+1]) {
                dp[i+j+1]=dp[i]+m;
                p[i+j+1]=i;
            }
        }
    }
    printf("Total Time: %d\n",dp[q]);
    int queue[q+1],l=0;
    queue[0]=p[q];
    while(queue[l]){ l++;
    queue[l]=p[queue[l-1]];
    } l--;
    for(int i=0;i<q;i++){
        printf("%s",s[i]);
        if(i+1==queue[l]){
            printf("\n"); l--;
        }
        else printf(" ");
    }
    printf("\n");
}
