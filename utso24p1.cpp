/*
UTS Open '24 P1 - Watering the Plants
Author: Dan Shan
Date: 2025-01-02
start from back and move the the front
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k,t=0;
    cin >> n >> k;
    while(n>0){
        t+=2*n;
        n-=k;
    }
    cout << t << "\n";
}
*/
