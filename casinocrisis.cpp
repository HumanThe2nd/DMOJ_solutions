#include <bits/stdc++.h>
using namespace std;
// Casino Crisis
// By: Dan Shan
using pi = pair<int,int>;
int main() {
std::istream::sync_with_stdio(false);
cin.tie(nullptr);
int n,q,c=0;
cin >> n >> q;
int a[n+1];
vector<pi> steps;
for(int i=1;i<=n;i++) cin >> a[i];
int i=1;
while(i<=n){
    if(a[i]==i) {
        i++; continue;
    }
    vector<pi> v;
    for(int j=i;j<=n;j++){
        v.emplace_back(a[j],j);
        if(a[j]==i) break;
    }
    sort(v.begin(),v.end());
    int s = (int)v.size();
    for(int j=0;j<s/2;j++){
        a[v[j].second]=v[s-j-1].first;
        a[v[s-j-1].second]=v[j].first;
    }
    steps.emplace_back(i,i+s-1);
    c++;
}
printf("%d\n",c);
for(pi x: steps) printf("%d %d\n",x.first,x.second);
}
