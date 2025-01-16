/*
DWITE '10 R2 #3 - Escape and Loot
Author: Dan Shan
Date: 2025-01-16
Grid Dynamic programming
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int dp[8][8];
int max (int a,int b){
    return a<b?b:a;
}
int main(){
    for(int t=5;t--;){
        int dp[8][9];
        char g[8][9];
        for(int i=7;i>=0;i--){
            for(int j=0;j<9;j++){
                g[i][j]=getchar();
                dp[i][j]=0;
            }
        } if(g[0][0]>'0') dp[0][0]=g[0][0]-'0';
        for(int i=1;i<8;i++){ // edges
            dp[i][0]=dp[i-1][0];
            dp[0][i]=dp[0][i-1];
            if(g[i][0]>'0') dp[i][0]+=g[i][0]-'0';
            if(g[0][i]>'0') dp[0][i]+=g[0][i]-'0';
        }
        for(int i=1;i<8;i++){
            for(int j=1;j<8;j++){
                if(g[i][j]=='#') continue; // skip walls
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(g[i][j]>'0') dp[i][j]+=g[i][j]-'0';
            }
        }
        printf("%d\n",dp[7][7]);
        if(!t) break;
        for(int i=0;i<9;i++) getchar(); // remove seperating dashes
    }
}
