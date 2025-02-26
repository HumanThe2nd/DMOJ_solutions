/*
CCC '96 S5 - Maximum Distance
Author: Dan Shan
Date: 2024-11-02
Store first index in array a each element occurs
for each element in b check if it exists and then if its distance to the first index is maximal
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
    cin >> t;
    while(t--){
        int n,m=0;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> s;
        cin >> a[0]; s[a[0]]=0;
        for(int i=1;i<n;i++){
            cin >> a[i];
            if(a[i]!=a[i-1]){
                s[a[i]]=i;
            }
        }
        for(int i=0;i<n;i++){
            int bi;
            cin >> bi;
            if(s.find(bi)==s.end()) continue;
            if(i-s[bi]>m) m=abs(i-s[bi]);
        }
        cout << "The maximum distance is " << m << "\n";
    }
}
