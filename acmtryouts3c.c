/*
ACM U of T Tryouts C3 C - A Subtle Surf
Author: Dan Shan
Date: 2024-12-10
binary search largest next channel until the next channel is equal to itself
time is just a counter for the jump of times multipled by T
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int d;
    cin >> d;
    while(d--){
        int n,c,t,ti=0;
        cin >> n >> c >> t;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            a[i]*=-1;
        }
        int gi=a[0]*-1;
        sort(a.begin(),a.end());
        while(1){
            int gn=-*lower_bound(a.begin(),a.end(),-(gi+c));
            if(gn==gi) break; // can't surf anymore
            ti++; gi=gn;
        }
        cout << gi << " " << ti*t << "\n";
    }
}
