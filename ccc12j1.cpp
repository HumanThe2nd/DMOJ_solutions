#include <iostream>
using namespace std;
int main() {
  int limit, speed,x;
  cin >> limit >> speed;
  if(limit > speed)
    cout << "Congratulations, you are within the speed limit!";
  else{
    x = speed - limit;
    cout << "You are speeding and your fine is $";
    if(x < 21) cout << 100;
    else if(x < 30) cout << 270;
      else cout << 500;
    cout << ".";
  }
}
