/*
CCC '16 S4 - Combining Riceballs
Author: Dan Shan
Date: 2025-06-13
Recursive Dynamic Programming
Observation: order of merging doesn't effect the sum 
1. Prefix sum array for O(1) range sum queries.
2. 2D memoization array stores whether each interval [l, r] is valid (can be merged).
3. Recursively try to split into 3 parts: left, right, middle (possibly empty).
4. Optimize Each call from O(N^2) to O(N) through two-pointers technique (Optional but speed up code significantly)
5. If left and right have equal sums, and all 3 parts are valid, then dp[l][r] is valid.
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0,neg=1;
    while((*ptr<'0'||*ptr>'9')&&*ptr!='-')++ptr; // Skip non-digit characters
    while(*ptr=='-')++ptr,neg*=-1;
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num*neg;
}
int dp[401][401],p[401];
int solve(int l, int r){
    if(dp[l][r]) return dp[l][r];
    if(l>=r) return dp[l][r]=1;
    int i=l,j=r;
    while(i<=j){
        int li=p[i]-p[l-1],ri=p[r]-p[j-1];
        if(li!=ri){ // sums don't match
            if(li<ri) ++i;
            else --j;
            continue;
        }
        if(solve(l,i)>0&&solve(i+1,j-1)>0&&solve(j,r)>0) return dp[l][r]=1;
        ++i; --j;
    }
    return dp[l][r]=-1;
}
int main(){
    buff();
    int n=scan(),m=1; p[0]=0;
    for(int i=1;i<=n;++i) {
        p[i]=scan(); p[i]+=p[i-1];
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            int d=p[j]-p[i-1];
            if(d>m&&solve(i,j)>0) m=d;
        }
    }
    printf("%d\n",m);
}
