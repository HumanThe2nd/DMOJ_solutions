// CCC '13 S1 - From 1987 to 2013
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  scanf("%d",&n);
  bool b = 1;
  while(b){
    b=0;
    n++;
  unordered_set<int> s={};
  int n2=n;
  while(n2){if(s.find(n2%10)!=s.end()){b=1;break;}
          else {s.insert(n2%10);n2/=10;}}
}
  printf("%d\n",n);
}
