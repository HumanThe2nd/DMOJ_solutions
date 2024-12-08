#include <iostream>
#include <vector>
using namespace std;

int main() {
  int i,w,n,inp,count=0;
  vector<int> cartlist;
  cin >> w >> n;
  for(i = 0; i < n;i++){
    cin >> inp;
    cartlist.push_back(inp);
    if(i < 4){
      for(int j = 0; j< i+1;j++){
       count += cartlist[j]; 
      }
    }
    else{
      count += cartlist[i]+cartlist[i-1];
      count += cartlist[i-2]+cartlist[i-3];
    }
    if(count > w) break;
    else count = 0;
  }
  cout << i;
}
