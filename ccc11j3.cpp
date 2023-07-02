#include <iostream>
#include <vector>
using namespace std;
int main() {
  int start,end,holder;
  int count = 2;
  cin >> start >> end;
  while(start >= end){
    holder = end;
    end = start - end;
    start = holder;
    count++;
}
  cout << count;
}
