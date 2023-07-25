// CCC '14 S3 - The Geneva Confection
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;i++){
  stack<int> b,lake,m;
  b.push(1000001);
  lake.push(0);
  int n;
  char y = *"Y";
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int next;
    scanf("%d",&next);
    m.push(next);
  }
  while(m.size()>0){
    int next = m.top();
    m.pop();
    while(b.top()==lake.top()+1){
    lake.push(b.top()); b.pop();}
    if(y==*"Y"){
      if(next==lake.top()+1) lake.push(next);
      else if(b.top()==1000001||next<b.top()) b.push(next);
      else y=*"N";
    }
  }
  while(b.top()==lake.top()+1){
  lake.push(b.top()); b.pop();}
  if(b.size()>1) y=*"N";
  printf("%c %s",y,"\n");
  }
}
