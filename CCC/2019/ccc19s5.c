/*
CCC '19 S5 - Triangle: The Data Structure
Author: Dan Shan
Date: 2025-03-31
Max-value sparse table with triangles
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
typedef long long ll;
#define bs 1<<27 // Templates
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
ll st[3001][3001];
ll f(ll ki, ll xi, ll yi){ // max value in subtriangle
    ll res=st[xi][yi],mi=(ki>>1);
    if(st[xi+ki][yi]>res) res=st[xi+ki][yi]; // bot left
    if(st[xi+ki][yi+ki]>res) res=st[xi+ki][yi+ki]; // bot right
    if(st[xi+mi][yi]>res) res=st[xi+mi][yi]; // mid left
    if(st[xi+mi][yi+mi]>res) res=st[xi+mi][yi+mi]; // mid right
    if(st[xi+ki][yi+mi]>res) res=st[xi+ki][yi+mi]; // bot mid
    return res;
}
int main(){
    buff();
    ll n=scan(),k=scan(),m=0;
    while((1<<(m+1))<k) m++;
    for(int i=1;i<=n;++i){ // full triangle
        for(int j=1;j<=i;++j){
            st[i][j]=scan();
        }
    }
    for(int i=1;i<=m;++i){ // build triangle sparse tables
        for(int j=1;j+(1<<i)-2<n;++j){
            for(int l=1;l<=j;++l){
                st[j][l]=f((1<<(i-1)),j,l);
            }
        }
    }
    ll res=0;
    for(int i=1;i+k-2<n;++i){ // query max triangle of size k
        for(int j=1;j<=i;++j) res+=f(k-(1<<m),i,j);
    }
    printf("%lld\n",res);
}
