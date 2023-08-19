// CCC '17 J3 - Exactly Electrical
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d,t;
  scanf("%d %d %d %d %d",&a,&b,&c,&d,&t);
  int x = abs(c-a), y= abs(d-b);
  if(x+y<=t&&(x+y)%2 == t%2) cout<<"Y\n";
  else cout<<"N\n";
}
