/*
Educational DP Contest AtCoder Z - Frog 3
Author: HumanThe2nd
Date: 2025-04-25
Dynamic Programming + Convex Hull Trick
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M=2e16,n,c;
vector<ll> dp,h;
deque<ll> dq;
inline ll in(ll i){
    return dp[i]+h[i]*h[i];
} 
inline double p(ll p1,ll p2){
    return (double)(in(p2)-in(p1))/(2*(h[p2]-h[p1]));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;
    h.resize(n+1);
    dp.resize(n+1,M);
    dp[1]=0; dq.emplace_back(1);
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=2;i<=n;i++){
        while(dq.size()>1&&p(dq[0],dq[1])<h[i]) dq.pop_front(); // prune sub-optimal
        dp[i]=dp[dq[0]]+(h[i]-h[dq[0]])*(h[i]-h[dq[0]])+c;
        while(dq.size()>1){ // maintain hull
            ll ai=dq[dq.size()-2],bi=dq.back();
            if(p(bi,i)>=p(bi,ai)) break; 
            dq.pop_back();
        }
        dq.emplace_back(i);
    }
    cout << dp[n] << "\n";
}
