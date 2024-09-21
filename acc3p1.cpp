// Another Contest 3 Problem 1 - Diverse Arrays
// Author: Dan Shan
// Date: 2024-9-20
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,k,l=0;
    cin >> n >> k;
    int a[n];
    long long c=(n*n+n)/2;
    for(int i=0;i<n;i++) cin >> a[i];
    unordered_map<int, int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
        while(m.size()>=k){
            m[a[l]]--;
            if(!m[a[l]]) m.erase(a[l]);
            l++;
        }
        c-=i-l+1;
    }
    printf("%d\n",c);
}
