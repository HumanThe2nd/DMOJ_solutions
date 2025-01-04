/*
DMPG '17 G2 - Holy Grail War
Author: Dan Shan
Date: 2025-01-04
Segment tree with custom nodes and merge function
Iterative solution
*/
#include <stdio.h>
typedef long long ll;
const ll inf=-1e18; // negative pseudoinfinity
ll scan() {
    ll n=0, a=0;
    char c = getchar();
    if (c == '-') n = 1, c = getchar();
    while('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
    return n ? -a : a;
}
ll max(ll a,ll b){
    return a>b?a:b;
}
typedef struct{
    ll sum,pre,suf,mx;
} node;
node merge(node l, node r){
    node res;
    res.sum=l.sum+r.sum; // total interval sum
    res.pre=max(l.pre,l.sum+r.pre); // max prefix
    res.suf=max(r.suf,l.suf+r.sum); // max suffix
    res.mx=max(max(l.mx,r.mx),l.suf+r.pre); // combine max overlap
    return res;
}
ll a[100001],n,k;
node t[500001];
void build(){
    for(int i=0;i<n;i++) t[n+i]=(node){a[i],a[i],a[i],a[i]};
    for(int i=n-1;i>0;--i) t[i]=merge(t[i<<1],t[i<<1|1]);
}
void u(int p, ll v){ // update
    p+=n;
    t[p]=(node){v,v,v,v};
    for(p>>=1;p>0;p>>=1){
        t[p]=merge(t[p<<1],t[p<<1|1]);
    }
}
node q(ll l, ll r){ // query
    node ln={0,inf,inf,inf},rn=ln;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ln=merge(ln,t[l++]);
        if(r&1) rn=merge(t[--r],rn);
    }
    return merge(ln,rn);
}
int main() {
    n=scan(),k=scan();
    for(int i=0;i<n;i++) a[i]=scan();
    build();
    while(k--){
        char s=getchar(); getchar();
        ll ai=scan(),bi=scan();
        ai--; // tree is 0 indexed
        if(s=='S') u(ai,bi);
        else printf("%lld\n",q(ai,bi).mx);
    }
}
