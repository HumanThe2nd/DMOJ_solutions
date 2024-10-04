#include <iostream>
using namespace std;
int main() {
  int day, evening, weekend;
  cin >> day >> evening >> weekend;
  float pA = 0;
  float pB = 0;
  if (day > 100) pA += (day-100)*0.25;
  if (day > 250) pB += (day-250)*0.45;
  pA += 0.15*evening + 0.2*weekend;
  pB += 0.35*evening + 0.25*weekend;
  cout << "Plan A costs " << double(pA);
  if(pA == int(pA))
    cout << ".00";
  cout << "\n";
  cout << "Plan B costs " << double(pB);
  if(pA == int(pA))
    cout << ".00";
  cout << "\n";
  if((pA- pB) == 0) cout << "Plan A and B are the same price.";
  else if(pB > pA) cout << "Plan A is cheapest.";
      else cout << "Plan B is cheapest.";
}
