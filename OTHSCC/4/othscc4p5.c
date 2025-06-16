/*
OTHS Coding Competition 4 P5 - Teleport
Author: HumanThe2nd
Date: 2025-05-12

Intended Solution:
Mark every node on the bottom-right of any teleporter as 1
Mark every node top-left of any teleporter as 2 if the are 1

1. path to a teleporter with maximum cells marked 0 or 1 from start
2. path to a teleporter with maximum cells marked 0 or 1 from end

Answer: sum of 2 paths and number of cells marked as 2
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int dp[2000][2000],p[2000][2000],p2[2000][2000];
int main() {
    int n,res=0,m1=-0,m2=0;
    scanf("%d",&n);
    char s[n][n+1];
    for(int i=0;i<n;i++) { // mark as 1 
        scanf("%s",s[i]);
        for(int j=0;j<n;j++){
            if(s[i][j]=='x'||(i&&dp[i-1][j])||(j&&dp[i][j-1])) dp[i][j]=1;
        }
    }
    for(int i=n-1;i>=0;--i){ // mark as 2
        for(int j=n-1;j>=0;--j){
            if(!dp[i][j]) continue; // can't be reached from top left
            if(s[i][j]=='x'||(i<n-1&&dp[i+1][j]>1)||(j<n-1&&dp[i][j+1]>1)) dp[i][j]=2;
        }
    }
    for(int i=0;i<n;i++) { // find enter path
        for(int j=0;j<n;j++){
            if(i) p[i][j]=p[i-1][j];
            if(j&&p[i][j-1]>p[i][j]) p[i][j]=p[i][j-1];
            if(dp[i][j]<2) p[i][j]++; // extra cell 
        }
    }
    for(int i=n-1;i>=0;--i){ // find exit path
        for(int j=n-1;j>=0;--j){
            if(i<n-1) p2[i][j]=p2[i+1][j];
            if(j<n-1&&p2[i][j+1]>p2[i][j]) p2[i][j]=p2[i][j+1];
            if(dp[i][j]<2) p2[i][j]++; // extra cell 
        }
    }
    for(int i=0;i<n;i++) { // count visitable cells
        for(int j=0;j<n;j++){
            if(dp[i][j]==2) res++; // enclosed by teleporters
            if(s[i][j]=='.') continue; // only max paths at teleporters
            if(p[i][j]>m1) m1=p[i][j];
            if(p2[i][j]>m2) m2=p2[i][j];
        }
    }
    if(!res) return !printf("%d\n",2*n-1); // no teleporters
    printf("%d\n",res+m1+m2);
}
