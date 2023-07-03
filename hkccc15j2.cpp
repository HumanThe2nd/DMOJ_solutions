#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  ll n,inp,min = 1000000000000000;
  vector<ll> x,y,area;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> inp;
    x.push_back(inp);
    cin >> inp;
    y.push_back(inp);
  }
  for(ll i = 0; i < n; i++){
    for(ll k = 0; k < n; k++){
      if(i!=k){
          if(abs(x[i] - x[k]) > abs(y[i] - y[k])){
              area.push_back((x[i]-x[k])*(x[i]-x[k]));
          } else {
              area.push_back((y[i]-y[k])*(y[i]-y[k]));
          }
        }
    }
}
    for(ll i = 0; i < area.size();i++){
      if(area[i] < min) min = area[i];
    }
    cout << min <<"\n";
}
