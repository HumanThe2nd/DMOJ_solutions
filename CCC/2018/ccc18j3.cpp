// CCC '18 J3 - Are we there yet?
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> v = {0};
  for(int i=0;i<4;i++){
    int n;
    scanf("%d",&n);
    v.push_back(n);
  }
  int c1 =0;
  for(int i=0;i<5;i++){
    c1+=v[i];
    int c2=c1;
    for(int j=0;j<5;j++){
      c2-=v[j];
      cout<<abs(c2)<<" ";
    }
    cout<<"\n";
  }
}
