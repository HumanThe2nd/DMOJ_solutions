/*
NOIP '18 P1 - Paving Roads
Author: Dan Shan
Date: 2025-05-11
Divide and conquer: split at local minimum
Sparse table to precompute minimum between intervals
Note: Looking at other submissions, there are easier solutions
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
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int a[100001],st[100001][17][2],lf[100001];
void build(int n){ // sparse table: min, ind
    lf[1]=0;
    for(int i=2;i<=n;i++) lf[i]=lf[i>>1]+1;
    for(int i=0;i<n;i++) st[i][0][0]=a[i],st[i][0][1]=i;
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            int lv=st[i][j-1][0],rv=st[i+(1<<(j-1))][j-1][0];
            int li=st[i][j-1][1],ri=st[i+(1<<(j-1))][j-1][1];
            if(lv<=rv) st[i][j][0]=lv,st[i][j][1]=li;
            else st[i][j][0]=rv,st[i][j][1]=ri;
        }
    }
}
void q(int l, int r, int* m, int* ind){
    int j=lf[r-l+1];
    int lv=st[l][j][0],rv=st[r-(1<<j)+1][j][0];
    int li=st[l][j][1],ri=st[r-(1<<j)+1][j][1];
    if(lv<=rv) *m=lv, *ind=li;
    else *m=rv, *ind=ri;
    return;
}
int f(int l, int r, int v){
    if(r<=l) return 0;
    int m,ind;
    q(l,r-1,&m,&ind);
    m-=v;
    m+=f(l,ind,v+m)+f(ind+1,r,v+m); // divide & conquer
    return m;
}
int main(){
    buff();
    int n=scan();
    for(int i=0;i<n;i++) a[i]=scan();
    build(n);
    printf("%d\n",f(0,n,0));
}
