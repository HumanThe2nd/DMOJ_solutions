// CCC '20 S1 - Surmising a Sprinter's Speed
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n; 
  double c=0;
  scanf("%d",&n);
  map<int,int> m;
  for(int i=0;i<n;i++){
    int t,x;
    scanf("%d %d",&t,&x);
    m[t] = x;
  }
  double ti =m.begin()->first;
  double di =m.begin()->second;
  double tt=0,dt=m.begin()->second;
  for(auto i=m.begin();i!=m.end();i++){
    double v;
    if(i!=m.begin()){
    tt = abs(i->first-ti); // delta time
    ti = i->first; // initial time
    dt = abs(i->second-di); // delta distance
    di = i->second; // initial distance
    v=dt/tt; // delta velocity
    if(v>c)c=v; // c = max average velocity
    }
  }
  printf("%lf",c);
}
