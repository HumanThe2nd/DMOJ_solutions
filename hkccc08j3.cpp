// CCCHK 2008 J3 - Phone book
// by: Dan Shan
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  int n,n2,num,max = 0,index = 0;
  string name;
  vector<string> names;
  vector<int> numbers,count;
  cin >> n;
  for(int i = 0;i<n;i++){
    cin >> name >> num;
    names.push_back(name);
    numbers.push_back(num);
    count.push_back(0);
  }
  cin >> n2;
  for(int i = 0;i < n2;i++){
    cin >> num;
    for(int j = 0; j < n;j++){
      if(num == numbers[j]) count[j]++;
    }
  }
  for(int i = 0; i< n;i++){
    if(count[i] > max || (count[i] == max && numbers[i] < numbers[index])){
      index = i;
      max = count[i];
    }
  }
  cout << names[index];
}
