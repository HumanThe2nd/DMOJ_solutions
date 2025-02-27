// Mispelling
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<n+1;i++){
    int x;
    string y,res="";
    cin>>x;
    getline(cin,y);
    int h = y.length()+1;
    for(int j=1;j<h-1;j++){
      if(j!=x) res+=y[j];
    }
    cout<<i<<" "<<res<<"\n";
  }
}
