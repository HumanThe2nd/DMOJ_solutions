/*
UTS Open '24 P2 - Happy Gifts
Author: Dan Shan
Date: 2024-01-02
2 pointer with pairing negatives with 2 largest positives
Note: with odd numbers of k, the largest positive must be added first or the method fails
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int l=0,r=n-1; // 2 pointer with the array
    long long c=0;
    if((k&1)&&k<2*n){
        if(a[n-1]>0) c=a[n-1];
        r--;
        k--;
    }
    while(r-l>=0&&k>0){ // at least 2 elements remaining
        if(a[r]+max(0,a[r-1])>-a[l]){ // can skip second largest positive
            if(a[r]>0) c+=a[r];
            if(a[r-1]>0) c+=a[r-1];
            else{ // value not really used
                k++; r++;   
            }
            r-=2;
        }
        else{
            c+=-a[l];
            l++;
        }
        k-=2;
    }
    cout << c << "\n";
}
