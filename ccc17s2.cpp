// CCC '17 S2 - High Tide, Low Tide
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cout.sync_with_stdio(0);
  cout.tie(0);
  int n,l;
  scanf("%d",&n);
  vector<int> all,low,high;
  for(int i=0;i<n;i++){
    int j;
    scanf("%d",&j);
    all.push_back(j);
  }
  sort(all.begin(),all.end());
  // even number
  if(all.size()%2==1){
    for(int i=0;i<all.size()/2+1;i++) low.push_back(all[i]);
    for(int i=all.size()/2+1;i<all.size();i++) high.push_back(all[i]);
  }
  // odd number
  else{
    for(int i=0;i<all.size()/2;i++) low.push_back(all[i]);
    for(int i=all.size()/2;i<all.size();i++) high.push_back(all[i]);
  }
  for(int i=0;i<n;i++){
    if(i%2==0)cout<<low[low.size()-i/2-1]<<" ";
    else cout<<high[i/2]<<" ";
  }
  cout<<endl;
}
