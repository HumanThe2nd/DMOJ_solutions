#include <iostream>
using namespace std;
int main() {
  int w1,w2,w3;
  cin >> w1 >> w2 >> w3;
  if((w1 > w2 && w2 > w3)||(w3 > w2 && w2 > w1)) cout << w2;
  if((w2 > w1 && w1 > w3)||(w3 > w1 && w1 > w2)) cout << w1;
  if((w2 > w3 && w3 > w1)||(w1 > w3 && w3 > w2)) cout << w3;
}
