// SAC 2022 Code Challenge 5 Junior P2 - Badminton Scoring
// by: Dan Shan
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
  int n,M,O,c=0;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> M >> O;
    if(M > O) c++;
  }
  cout << c;
}
