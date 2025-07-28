/*
Appleby Contest '19 P5 - Matrix Operation
Author: Dan Shan
Date: 2025-07-28
Repeat for each cell:
1. DFS longest path
2. Mark cell with its maximum
3. Use memoization to avoid recomputation

Time Complexity: O(N^2)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<25 // Templates
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
int n,dx[]={-1,0,0,1},dy[]={0,-1,1,0},a[1501][1501],v[1501][1501],res=1;
int dfs(int x, int y){
    if(v[x][y]) return v[x][y]; // precomputed
    int cur=1;
    for(int i=0;i<4;++i){
        int xf=x+dx[i],yf=y+dy[i];
        if(xf<0||yf<0||xf>=n||yf>=n||a[xf][yf]<=a[x][y]) continue;
        int li=dfs(xf,yf)+1;
        if(li>cur) cur=li;
    }
    return v[x][y]=cur;
}
int main(){
    buff();
    n=scan();
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) {
            a[i][j]=scan();
        }
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(!v[i][j]) {
                int li=dfs(i,j);
                if(li>res) res=li;
            }
    printf("%d\n",--res);
}
