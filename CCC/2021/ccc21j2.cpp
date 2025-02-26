#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, value,max=0;
  string name, highest;
  vector<int> values;
  vector<string> names;
  cin >> n;
  for(int i = 0; i < n;i++){
    cin >> name;
    cin >> value;
    names.push_back(name);
    values.push_back(value);
  }
  for(int i = 0; i < n;i++){
    if(values[i] > max){
      max = values[i];
      highest = names[i];
    }
  }
  cout << highest;
}
