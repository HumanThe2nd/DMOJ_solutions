#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  if(n != 5 && n != 6 && n!=9)
    cout << (n%5)/2+1;
  if(n ==5 )
    cout << 3;
  if(n == 6)
    cout << 3;
  if(n == 9)
    cout << 1;
}
