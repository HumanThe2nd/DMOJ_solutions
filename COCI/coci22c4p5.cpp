/*
COCI '22 Contest 4 #5 Vrsta
Author: Dan Shan
Date: 2024-12-28
Frequency arrays for each relative height
binary search highest frequency less than or equal to the median and return the actual height
*/
#include <bits/stdc++.h>
using namespace std;
long long n,tree[800001],p;
vector<int> a,a2,f,f2; // a: original, a2: sorted
void u(int index, int fi){ // index and new frequency
    index+=p;
    while(index>0) {
        tree[index]+=fi;
        index>>=1;
    }
}
int q(int index, long long fi){
    if(index>=p) return index-p;
    if(tree[index*2]>=fi) return q(index*2,fi); 
    return q(index*2+1,fi-tree[index*2]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, int> m; // compress height to using indexes
    cin >> n;
    p=1<<int(ceil(log2(n)));
    a.resize(n);
    a2.resize(n);
    f.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> f[i];
        a2[i]=a[i];
    }
    sort(a2.begin(),a2.end());
    a2.erase(unique(a2.begin(),a2.end()),a2.end());
    for(int i=0;i<a2.size();i++){
        m[a2[i]]=i; // absolute height to relative height
        f2.push_back(a2[i]);
    }
    long long c=0;
    for(int i=0;i<n;i++){ // start updates/queries
        int ind = m[a[i]];
        c+=f[i];
        u(ind,f[i]);
        cout << f2[q(1,(c+1)/2)] << "\n";
    }
}
