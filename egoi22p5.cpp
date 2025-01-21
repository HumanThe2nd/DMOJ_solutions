/*
EGOI '22 P5 - Data Centers
Author: Dan Shan
Date: 2025-01-20
Priority queue: 77/100 subtask
Full Solution: Rebuild array with edited elements each query
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.rbegin(),a.rend());
    while(s--){
        int mi,ci;
        cin >> mi >> ci;
        for(int i=0;i<ci;i++) a[i]-=mi;
        vector<int> m(n);
        int i=0,j=ci,l=0;
        while(i<ci&&j<n){
            if(a[i]>a[j]) m[l++]=a[i++];
            else m[l++]=a[j++];
        }
        while(i<ci) m[l++]=a[i++];
        while(j<n) m[l++]=a[j++];
        a = move(m);
    }
    for(int i=0;i<n-1;i++) cout << a[i] << " ";
    cout << a[n-1] << "\n";
}
