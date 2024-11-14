#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> burgers = {0,461,431,420,0};
  vector<int> drinks = {0,130,160,118,0};
  vector<int> sides = {0,100,57,70,0};
  vector<int> desserts = {0,167,266,75,0};
  int inp;
  int calories = 0;
  cin >> inp;
  calories += burgers[inp];
  cin >> inp;
  calories += sides[inp];
  cin >> inp;
  calories += drinks[inp];
  cin >> inp;
  calories += desserts[inp];
  cout << "Your total Calorie count is " << calories << ".";
}
