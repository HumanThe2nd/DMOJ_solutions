// CCC '07 S4 - Waterpark
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> dp(n+1, 0);
    dp[1] = 1; 
    while(1){
        int a, b;
        cin >> a >> b;
        if(!a && !b) break;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        for(int j : adj[i]){
            dp[j] += dp[i];
        }
    }

    cout << dp[n] << "\n";
}
