/*
Title: 2048
Author: Dan Shan
Date: 2025-07-24
Approach: Backtracking brute force 

1. DFS all 4 direction slides that lead to unvisited boards 
2. hash to store each visited board in a boolean array
3. Update maximum along the way
*/
#include <stdio.h>
#include <stdbool.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<22 // Templates
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
int g[4][4],res;
bool v[1<<20];
inline int hash(){ // hash grid
    int h = 0;
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            h = h * 31 + g[i][j];
    return h & ((1<<20)-1);
}
void solve(){
    int vi=hash();
    v[vi]=1;
    int gi[4][4];
    for(int i=0;i<4;++i)
            for(int j=0;j<4;++j){ //printf("%d ",g[i][j]);
                gi[i][j]=g[i][j];
                if(g[i][j]>res) res=g[i][j]; // update max
            } 

    for(int i=0;i<4;++i){ // left shift start
        for(int j=1;j<4;++j){
            if(g[i][j]==g[i][j-1]){ // merge
                g[i][j-1]=0; g[i][j]<<=1;
            }
            int ji=j; // slide down
            while(ji>0&&!g[i][ji-1]) --ji;
            g[i][ji]=g[i][j];
            if(ji!=j) g[i][j]=0;
        }
    }
    vi=hash();
    if(!v[vi]) solve(); // unvisited board found
    for(int i=0;i<4;++i)
            for(int j=0;j<4;++j) g[i][j]=gi[i][j]; // reset (left shift end)
    
    for(int i=0;i<4;++i){ // right shift start
        for(int j=2;j>=0;--j){
            if(g[i][j]==g[i][j+1]){ // merge
                g[i][j+1]=0; g[i][j]<<=1;
            }
            int ji=j; // slide down
            while(ji<3&&!g[i][ji+1]) ++ji;
            g[i][ji]=g[i][j];
            if(ji!=j) g[i][j]=0;
        }
    }
    vi=hash();
    if(!v[vi]) solve(); // unvisited board found
    for(int i=0;i<4;++i)
            for(int j=0;j<4;++j) g[i][j]=gi[i][j]; // reset (right shift end)

    for(int i=0;i<4;++i){ // up shift start
        for(int j=1;j<4;++j){
            if(g[j][i]==g[j-1][i]){ // merge
                g[j-1][i]=0; g[j][i]<<=1;
            }
            int ji=j; // slide down
            while(ji>0&&!g[ji-1][i]) --ji;
            g[ji][i]=g[j][i];
            if(ji!=j) g[j][i]=0;
        }
    }
     vi=hash();
    if(!v[vi]) solve(); // unvisited board found
    for(int i=0;i<4;++i)
            for(int j=0;j<4;++j) g[i][j]=gi[i][j]; // reset (up shift end)
    
    for(int i=0;i<4;++i){ // down shift start
        for(int j=2;j>=0;--j){
            if(g[j][i]==g[j+1][i]){ // merge
                g[j+1][i]=0; g[j][i]<<=1;
            }
            int ji=j;
            while(ji<3&&!g[ji+1][i]) ++ji;
            g[ji][i]=g[j][i];
            if(ji!=j) g[j][i]=0;
        }
    }
    vi=hash();
    if(!v[vi]) solve(); // unvisited board found
    for(int i=0;i<4;++i)
            for(int j=0;j<4;++j) g[i][j]=gi[i][j]; // reset (down shift end)
        
}
int main(){
    buff();
    for(int ti=5;ti;--ti){
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j) g[i][j]=scan();
        res=0;
        solve();
        printf("%d\n",res);
        for(int i=0;i<(1<<20);++i) v[i]=0;
    }
}
