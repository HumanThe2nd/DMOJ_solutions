/*
CCC '15 S5 - Greedy For Pies
Author: HumanThe2nd
Date: 2025-04-18
Dynamic Programming: Recursive approach
states: current pie, skipped last?, used pies, current used pies
Choices: Take, skip or insert pie
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma GCC optimize ("Ofast")
int cmp(const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}
int max(int a,int b){
    return a>b?a:b;
}
int n,m,a[3000],p[100];
int dp[3001][2][101][101]; // states: current pie, skipped last?, used pies, current used pies
int solve(int pi, int ti, int li, int ri){
    if(dp[pi][ti][li][ri]>0) return dp[pi][ti][li][ri]; // base case
    if(pi==n){
        if(li<=ri){
            if(ti){ // left
                dp[pi][ti][li][ri]=solve(pi,0,li+1,ri);
                return dp[pi][ti][li][ri];
            }
            else{ // right
                dp[pi][ti][li][ri]=solve(pi,1,li,ri-1)+p[ri];
                return dp[pi][ti][li][ri];
            }
        }
        else{
            dp[pi][ti][li][ri]=0;
            return 0;
        }
    }
    if(ti){
        dp[pi][ti][li][ri]=solve(pi+1,0,li,ri);
        if(li<=ri){
            dp[pi][ti][li][ri]=max(dp[pi][ti][li][ri],solve(pi,0,li+1,ri)); // left
        }
    }
    else{
        dp[pi][ti][li][ri]=max(solve(pi,1,li,ri),solve(pi+1,1,li,ri)+a[pi]);
        if(li<=ri) dp[pi][ti][li][ri]=max(solve(pi,1,li,ri-1)+p[ri],dp[pi][ti][li][ri]);
    }
    return dp[pi][ti][li][ri];
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&p[i]);
    }
    qsort(p,m,sizeof(int),cmp); 
    memset(dp,-1e9,sizeof(dp));
    printf("%d\n",m?solve(0,0,0,m-1):solve(0,0,1,0));
}
