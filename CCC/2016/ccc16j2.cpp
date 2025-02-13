#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  vector<int> row;
  vector<vector<int>> square;
  int inp,sum,count = 0;
  string m = "magic";
  // take in the input
  for(int i = 0; i < 4;i++){
    for(int j = 0; j < 4;j++){
      cin >> inp;
      row.push_back(inp);
    }
    square.push_back(row);
    for(int k = 0;k<4;k++){
      count += row[k];
    }
    if(i==0) sum = count;
    else if(count != sum) m = "not magic";
    count = 0;
    row.clear();
  }
  for(int i = 0; i < 4;i++){
    for(int j = 0; j < 4;j++){
    count += square[j][i];
  }
    if(count != sum) m = "not magic";
    count = 0;
}
  cout << m << "\n";
}
