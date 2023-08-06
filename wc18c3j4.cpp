// WC '18 Contest 3 J4 - Leveling Up
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class pokemon{
  public: int position,level,xp;
};
int main() {
  int n,s,l;
  vector<pokemon> p;
  scanf("%d %d %d",&n,&s,&l); // s = position, l = level 
  for(int i=0;i<n;i++){
    pokemon j;
    scanf("%d %d %d",&j.position,&j.level,&j.xp);
    p.push_back(j);
  }
     sort(p.begin(), p.end(), [&](pokemon x, pokemon y){return x.position < y.position;});
  stack<pokemon> low; // low starts from highest
  queue<pokemon> up; // up starts from lowest
  for(auto x:p){
    if(x.position>s) up.push(x);
    else low.push(x);
  }
  bool r = 1;
  while(r==1){
    if(low.size()>0&&low.top().level<=l){
      l+=low.top().xp;
      low.pop();
    }
    else if(up.size()>0&&up.front().level<=l){
      l+=up.front().xp;
      up.pop();
    }
    else break;
  }
  printf("%d",l);
}
