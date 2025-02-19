#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
  int P,N,R,count = 0,i;
  cin >> P >> N >> R;
  i = N;
  while(i <= P){
    count++;
    i += N*pow(R,count);
  }
  cout << count;
}
