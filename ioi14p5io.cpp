/*
IOI '14 P5 - Friend (Standard I/O)
Author: Dan Shan
Date: 2025-08-13
Solution references the editorial:
  dmoj.ca/problem/ioi14p5/editorial
Undo the nodes from the back
 - Update max confidence at its host when removing
p: pick
np not pick 
WeAreYourFriends:
1. p[i] = max(p[i] + np[j], p[j] + np[i])
2. np[i] = np[i] + np[j]

MyFriendsAreYourFriends:
1. p[i] = max(p[i] + np[j], p[j] + np[i], p[i] + p[j])
2. np[i] = np[i] + np[j]

IamYourFriend:
1. p[i] += np[j]
2. np[i] = max(np[i] + p[j], np[i] + np[j])
TC: O(N)
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n],b[n],p[n],q[n];
    for(int i=0;i<n;++i) cin >> p[i],q[i]=0;
    for(int i=1;i<n;++i) cin >> a[i] >> b[i];
    for(int i=n-1;i>0;--i){
        if(b[i]==2){ // WeAreYourFriends
            p[a[i]] = max(p[a[i]] + q[i], p[i] + q[a[i]]);
            q[a[i]] += q[i];
        }
        else if(b[i]==1){ // MyFriendsAreYourFriends
            p[a[i]] = max(p[a[i]] + q[i], max(p[i] + q[a[i]],p[i] + p[a[i]]));
            q[a[i]] += q[i];
        }
        else{ // IamYourFriend
            p[a[i]] += q[i];
            q[a[i]] = max(p[i] + q[a[i]],q[i] + q[a[i]]);
        }
    }
    cout << max(p[0],q[0]) << "\n";
}
