// DMOPC '17 Contest 1 P1 - Fujō Neko
// by: Dan Shan
#include <iostream>
#include <list>
#include <vector>
#include <cmath>
using namespace std; 
using ll = long long;
int main() {
  ll R,C,Q,sx,sy;
  vector<ll> x,y;
  char inp[1000],out;
  scanf("%lld", &R);
  scanf("%lld", &C);
  for(int i = 0;i<R;i++){
    scanf("%s", inp);
    for(int j = 0;j<C;j++){
      if(inp[j] == *"X"){
        y.push_back(i+1);
        x.push_back(j+1);
      }
    }
    }
  scanf("%lld", &Q);
    for(int i = 0;i<Q;i++){
      scanf("%lld", &sx);
      scanf("%lld", &sy);
      for(int j = 0;j < x.size();j++){
        if(x[j]==sx||y[j]==sy) out = *"Y";
      }
      if(out == *"Y") cout << out << "\n";
      else cout << "N" << "\n";
      out = *"N";
    }
}
