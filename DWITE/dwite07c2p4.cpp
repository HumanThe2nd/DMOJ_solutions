// DWITE '07 R2 #4 - All Is Balanced
// By: Dan Shan 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i=0;i<5;i++){
    deque<int>b;
    int p1=0,p2=0,p3=0; // p1:(),p2:[],p3:{} 
    string c;
    cin >> c;
    for(auto x:c){
      if(p1<0||p2<0||p3<0) break;
      else if(x==*"(")b.push_front(1);
      else if(x==*")"&&b[0]==1)b.pop_front();
      else if(x==*")"){b.push_front(0);break;}
      else if(x==*"[")b.push_front(2);
      else if(x==*"]"&&b[0]==2)b.pop_front();
      else if(x==*"]"){b.push_front(0);break;}
      else if(x==*"{")b.push_front(3);
      else if(x==*"}"&&b[0]==3)b.pop_front();
      else if(x==*"}"){b.push_front(0);break;}
    }
    if(b.size()==0) printf("%s","balanced\n");
    else printf("%s","not balanced\n");
  }
}
