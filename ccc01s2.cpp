// CCC '01 S2 - Spirals
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int s,e;
  scanf("%d %d",&s,&e);
  deque<deque<int>> v{{s}};
  s++;
  // down, right, up, left
  while(s<=e){
    for(int i=1;i<v.size();i++){ // down
      if(s<=e){
      v[i].push_front(s);
        s++;
      }
    }
    if(s<=e){ 
      v.push_back({s});
        s++;
    }
    while(v.back().size()<v.size()-1){ // right
      if(s<=e){
      v.back().push_back(s);
        s++;
      }
      else break;
    }
    for(int i=v.size()-1;i>=0;i--){ // up
      if(s<=e){
      v[i].push_back(s);
        s++;
      }
      else break;
    }
    if(s<=e){ 
      v.push_front({s});
        s++;
    }
    while(v.front().size()<=v.size()-1){ // left
      if(s<=e){
      v.front().push_front(s);
        s++;
      }
      else break;
    }
  }
  for(auto x:v){
    for(auto y:x){
      if(y==*--x.end()) printf("%d\n",y);
      else printf("%d ",y);
    }
  }
}
