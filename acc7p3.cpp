/*
Another Contest 7 Problem 3 - Network Connections
Author: HumanThe2nd
Date: 2025-04-21
Kruskal's MST
Only push adjacent edges
Note: this code pre-initializes parent & rank arrays (for simplicity)
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
int n,m,a[100001],p[100001],r[100001]; // pre-initialization
int abs(int ai){
    return ai<0?-ai:ai;
}
int cmp(const void *a, const void *b) {
    return ((int*)a)[2] - ((int*)b)[2];
}
int f(int ai){ // find
    if(p[ai]==ai) return ai;
    return p[ai]=f(p[ai]);
}
void u(int ai, int bi){ // union
    ai=f(ai);
    bi=f(bi);
    if(r[ai]<r[bi]){ // path compression
        p[ai]=bi;
    }
    else {
        if(r[ai]==r[bi]) r[ai]++;
        p[bi]=ai;
    }

}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++) p[i]=i; // initialize parent array
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    while(m--){
        int ai,bi;
        scanf("%d %d",&ai,&bi);
        --ai; --bi;
        u(ai,bi);
    }
    int e[n][3],l=0,c=0;
    for(int i=1;i<n;i++){
        e[l][0]=i; e[l][1]=i-1; // edges 
        e[l++][2]=abs(a[i]-a[i-1]); // weight
    }
    qsort(e,l,sizeof(e[0]),cmp);
    for(int i=0;i<l;i++){
        if(f(e[i][0])==f(e[i][1])) continue; // skip uneeded edges
        c+=e[i][2]; u(e[i][0],e[i][1]);
    }
    printf("%d\n",c);
}
