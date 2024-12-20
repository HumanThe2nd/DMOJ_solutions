/*
SAC '22 Code Challenge 3 P3 - Bob Sort
Author: Dan Shan
Date: 2024-12-19
stable sort each digit from 1 to the max digit
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m=0,c=1;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]>m) m=a[i];
    }
    while(m/c>0){
        stable_sort(a.begin(),a.end(),[&](int ai, int bi){return (ai/c)%10<(bi/c)%10;});
        c*=10;
    for(int i=0;i<n-1;i++){
    cout << a[i] << " ";
    }
    cout << a[n-1] << "\n";
    }
}
