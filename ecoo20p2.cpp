#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T,N;
  vector<vector<int>> o;
  map<string, int> m;
  scanf("%d",&T);
  for(int i=0;i<T;i++){
    string t="";
    char in[20] = "";
    scanf("%s",in);
    for(auto x:in)if(x!=*""&&x!=*" ")t+=x;
    o.push_back(vector<int>());
    m[t]=i;
  }
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    string t="";
    char in[20] = "";
    scanf("%s",in);
    for(auto x:in)if(x!=*""&&x!=*" ")t+=x;
    auto it = m.find(t);
    o[it->second].push_back(i+1);
  }
  for(auto i:o){
    for(auto j:i){
      printf("%d %s",j,"\n");
    }
  }
}
