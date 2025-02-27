/*
An Animal Contest 3 P3 - Monkey Market
Author: Dan Shan
Date: 2024-10-26
Theory: alternate small and large
if n is odd then the last element is a small element that should be skipped
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
    cin >> n;
    vector<int> a(n),a2(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i=0;i<n/2;i++) {
        a2[i*2]=a[i];
        if(n&1) a2[i*2+1]=a[n/2+i+1];
        else a2[i*2+1]=a[n/2+i];
    }
    if(n&1) a2[n-1]=a[n/2];
    for(int i=0;i<n-1;i++) printf("%d ",a2[i]);
    printf("%d\n",a2[n-1]);
    for(int i=0;i<(n>>1)<<1;i++){
        if(i&1) putchar_unlocked('S');
        else putchar_unlocked('B');
    }
    if(n&1) putchar_unlocked('E');
    putchar_unlocked('\n');
}
