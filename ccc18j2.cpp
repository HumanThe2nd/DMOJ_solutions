#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  int n,count =0;
  string l1,l2;
  cin >> n >> l1 >> l2;
  for(int i = 0; i < n;i++){
    if(l1.substr(i,1) == "C" && l1[i] == l2[i]) count++;
  }
  cout << count;
}
