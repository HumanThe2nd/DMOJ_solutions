/*
Arcadia Computing Contest 1 P4 - Cyclic Sorting
Author: Dan Shan
Date: 2025-01-30
store set of each index that decreases from its previous
if the number of indexes is 1 then output its minimum shifts: min(ind,n-ind)
otherwise it isn't possible
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    int a[n];
    cin >> a[0];
    unordered_set<int> s;
    for(int i=1;i<n;i++) {
        cin >> a[i];
        if(a[i]<a[i-1]) s.insert(i-1);
    }
    if(a[0]<a[n-1]) s.insert(n-1);
    while(q--){
        int ai,bi;
        cin >> ai >> bi;
        ai--;
        a[ai]=bi;
        for(int i=-1;i<2;i++){
            int aii=(ai+n+i)%n;
            if(a[aii]>a[(aii+1)%n]) s.insert(aii);
            else if(s.find(aii)!=s.end())s.erase(aii);
        }
        if(s.size()>1) cout << "-1\n";
        else {
            int di=0;
            if(s.size()) di=*s.begin();
            cout << min(di+1,n-di-1) << "\n";
        }
    }
}
