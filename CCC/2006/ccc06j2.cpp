#include <iostream>
using namespace std;
using ll = long long;
int main() {
  int m,n,count = 0;
  cin >> m >> n;
  for(int i = 1; i < m+1;i++){
    for(int j = 1; j < n+1;j++){
      if (i+j == 10) count ++;
    }
  }
  if(count == 1) cout << "There is 1 way to get the sum 10.";
  else cout << "There are " << count << " ways to get the sum 10.";
}
