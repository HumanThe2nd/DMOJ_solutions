// CCC '20 J3 - Art
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  vector<int> x,y;
  for(int i=0;i<n;i++){
    int X,Y;
    scanf("%d,%d",&X,&Y);
    x.push_back(X);
    y.push_back(Y);
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  printf("%d,%d\n%d,%d\n",--x[0],--y[0],++x.back(),++y.back());
}
