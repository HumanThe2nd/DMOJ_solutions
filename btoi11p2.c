/*
Baltic OI '11 P2 - Ice Cream
Author: Dan Shan
Date: 2025-06-10
1. store forbidden arrays in 2d matrix
2. brute force each valid triple
Time Complexity: O(M + N^3)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int a[201][201]; // forbidden pairs
int main(){
    int n,m,c=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){
        int ai,bi;
        scanf("%d %d",&ai,&bi);
        a[ai][bi]=1;
        a[bi][ai]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(a[i][j]) continue;
            for(int k=j+1;k<=n;++k){
                if(!a[i][k]&&!a[j][k]) ++c; // valid
            }
        }
    }
    printf("%d\n",c);
}
