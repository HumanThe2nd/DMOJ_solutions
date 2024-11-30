#include <iostream>
using namespace std;
int main() {
  int r1, r2, r3, r4;
  cin >> r1 >> r2 >> r3 >> r4;
  if(r4 == r3 && r3 == r2 && r2 == r1) cout << "Fish At Constant Depth";
  else if(r4 > r3 && r3 > r2 && r2 > r1) cout << "Fish Rising";
    else if(r4 < r3 && r3 < r2 && r2 < r1) cout << "Fish Diving";
      else cout << "No Fish";
}
