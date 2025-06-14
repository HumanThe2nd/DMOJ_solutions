/*
CCC '01 S2 - Spirals
Author: Dan Shan
Date: 2025-06-14
2d deque -> simple & efficient updates
Pattern modulo 4: left(0),down(1), right(2), up(3)
lengths: 1,1,2,2,3,3,4,4, etc
*/

// Newer Solution
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,y,p=1;
    cin >> x >> y;
    deque<deque<int>> dq={{x++}};
    while(x<=y){
        int si=dq.size();
        if(p%4==0){ // left
            for(int i=0;i<(p>>1)&&x<=y;++i){
                dq.front().emplace_front(x++);
            }
        }
        else if(p%4==1){ // down
            for(int i=1;i<=(p>>1)&&x<=y;++i){
                dq[i].emplace_front(x++);
            }
            if(x<=y) dq.emplace_back(deque<int>{x++});
        }
        else if(p%4==2){ // right
            for(int i=0;i<(p>>1)&&x<=y;++i){
                dq.back().emplace_back(x++);
            }
        }
        else{ // up
            for(int i=2;i<=dq.size()&&x<=y;++i){
                dq[dq.size()-i].emplace_back(x++);
            }
            if(x<=y) dq.emplace_front(deque<int>{x++});
        } ++p; // next
    }
    for(auto x: dq){
        for(auto y: x){
            cout << y << " ";
        }
        cout << "\n";
    }
}

// Old Solution
// Date: 2023-09-10
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
