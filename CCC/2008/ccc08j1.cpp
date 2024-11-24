/*
CCC '08 J1 - Body Mass Index
Author: Dan Shan
Date: 2023-06-29
*/
#include <iostream>
using namespace std;
int main() {
  double weight, height, BMI;
  cin >> weight >> height;
  BMI = weight/height/height;
  if(BMI > 25) cout << "Overweight";
  else if(BMI >= 18.5) cout << "Normal weight";
    else cout << "Underweight";
}
