// DMOPC '15 Contest 4 P4 - Great Sequence
// By: Dan Shan
// prefix sum array + 
// lower bounding 2d array with binary search
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,k,q;
    vector<vector<int>> v(2001);
    cin >> n >> k >> q;
	int a[n],psa[n+1];
    for(int i=0;i<n;i++) {
        cin >> a[i];
        v[a[i]+1000].emplace_back(i+1);
        psa[i+1]=psa[i]+a[i];
    }
    for(int i=0;i<q;i++){
        int ai,bi,x,y;
        cin >> ai >> bi >> x >> y;
        if(psa[y]-psa[x-1]<=k){
            printf("No\n");
            continue;
        } ai+=1000; bi+=1000;
        auto l1 = lower_bound(v[ai].begin(),v[ai].end(),x),
        l2 = lower_bound(v[bi].begin(),v[bi].end(),x);;
        if(l1==v[ai].end()||l2==v[bi].end()){
            printf("No\n");
            continue;
        }
        if(v[ai][l1-v[ai].begin()]>y||v[bi][l2-v[bi].begin()]>y)
            printf("No\n");
        else printf("Yes\n");
    }
}
