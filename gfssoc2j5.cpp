// GFSSOC '15 Fall J5 - Nightmare-a-thon
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,q;
  scanf("%d %d",&n,&q);
  vector<vector<int>> mn;
  for(int i=0;i<10;i++) mn.push_back({});
  for(int i=1;i<n+1;i++){
    int in;
    scanf("%d",&in);
    mn[10-in].push_back(i);
  }
  vector<vector<int>> mp = mn;
  for(int i=0;i<10;i++)
  sort(mn[i].begin(),mn[i].end(),greater<>());
  for(int i=0;i<q;i++){
    int a,b,c=0,r=1;
    scanf("%d %d",&a,&b);
    for(int j=0;j<10;j++){
      int low = lower_bound(mp[j].begin(),mp[j].end(),a)-mp[j].begin();
      int up = mn[j].size()-(lower_bound(mn[j].begin(),mn[j].end(),b,greater<int>())-mn[j].begin());
    if(mn[j].size()-up+low>0){
      c = mn[j].size()-up+low;
      r = 10-j;
      break;
    }
    }
    printf("%d %d %s",r,c,"\n");
  }
}
