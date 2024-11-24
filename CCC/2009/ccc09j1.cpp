/*
CCC '09 J1 - ISBN
Author: Dan Shan
Date: 2024-06-29
*/
#include <iostream>
using namespace std;
int main() {
  int num = 0;
  string inp;
  int j;
  string ISBN = "9780921418";
  for(int i = 0; i < 3;i++){
    cin >> inp;
    ISBN += inp;
  }
  for(int i = 0;i < 13;i++){
    if(i%2 ==0) j=1;
    else j = 3;
    num += (j)*(ISBN[i]-48);
  }
  cout << "The 1-3-sum is "<< num;
}
