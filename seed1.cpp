// The Cosmic Era P1 - Ship
// by: Dan Shan
#include <iostream>
#include <list>
#include <vector>
#include <cmath>
using namespace std; 
using ll = long long;
int main() {
  string inp;
  cin >> inp;
  int B=0,F=0,T=0,L=0,C=0;
  for(auto x: inp){
    if(x == *"B")B++;
    else if(x == *"F")F++;
    else if(x == *"T")T++;
    else if(x == *"L")L++;
    else if(x == *"C")C++;
  }
    if(B == 0)cout<<"B";
    if(F == 0)cout<<"F";
    if(T == 0)cout<<"T";
    if(L == 0)cout<<"L";
    if(C == 0)cout<<"C";
    if(B!=0&&F!=0&&T!=0&&L!=0&&C!=0) cout << "NO MISSING PARTS";
    cout << "\n";
}
