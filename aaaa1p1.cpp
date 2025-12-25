/*
AAAA 1 P1 - Even-Odd Sort
Author: Dan Shan
Date: 2025-12-24

Count number of odds (and find evens by subtracting it from n)
if n is odd or even >= odds: Steven (p1 / even) wins
else Todd (p2 / odd) wins
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, o = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        o += (ai & 1);
    } int e = n - o;
    if((n & 1) || e >= o) puts("Steven");
    else puts("Todd");
}
