#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  int N,k,count;
  cin >> N >>k;
  count = N;
    for(int i = 1;i<k+1;i++){
      count += N*pow(10,i);
    }
  cout << count;
}
