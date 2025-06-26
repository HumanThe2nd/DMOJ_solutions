/*
IOI '21 P4 - Mutating DNA
Author: Dan Shan
Date: 2025-06-26

Initialization:
Create frequency PSA of each mutation at each index
A -> C, A -> T, C -> T, reverses

Querying:
1-step mutations: reverse

2-step mutations: 
Case 1. A -> T == T -> C == C -> A
Case 2. T -> A == A -> C == C -> T

Others: Impossible

Time Complexity: 
Initialization -> O(n)
Query -> O(1)
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int mx=1e5+2;
int ac[mx],at[mx],ct[mx],ca[mx],ta[mx],tc[mx];
void init(string a, string b){
    int n=a.size();
    for(int i=1;i<=n;++i){
        ac[i]+=ac[i-1]; at[i]+=at[i-1]; ct[i]+=ct[i-1];
        ca[i]+=ca[i-1]; ta[i]+=ta[i-1]; tc[i]+=tc[i-1];

        if(a[i-1]=='A'){
            if(b[i-1]=='C') ++ac[i];
            else if(b[i-1]=='T') ++at[i];
        }
        else if(a[i-1]=='C'){
            if(b[i-1]=='T') ++ct[i];
            else if(b[i-1]=='A') ++ca[i];
        }
        else{
            if(b[i-1]=='A') ++ta[i];
            else if(b[i-1]=='C') ++tc[i];
        }
    }
}
int get_distance(int x, int y){
    int aci=ac[y+1]-ac[x],ati=at[y+1]-at[x],cti=ct[y+1]-ct[x];
    int cai=ca[y+1]-ca[x],tai=ta[y+1]-ta[x],tci=tc[y+1]-tc[x];
    int m=min(aci,cai),res=0; aci-=m; cai-=m; res+=m; // 1-step mutations
    m=min(ati,tai); ati-=m; tai-=m; res+=m;
    m=min(cti,tci); cti-=m; tci-=m; res+=m;
    if(aci==0&&aci==ati&&aci==cti&&aci==cai&&ati==tai&&aci==tci) return res;

    if(aci==cti&&cti==tai&&aci>0) return res+2*aci; // 2-step mutations
    if(cai==tci&&tci==ati&&cai>0) return res+2*cai;
    return -1;
}
