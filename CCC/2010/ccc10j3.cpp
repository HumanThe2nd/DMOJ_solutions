// CCC '10 J3 - Punchy
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
  bool r=1;
  unordered_map<char,int>  m;
  while(r){
  int n1,n2;
  char c1,c2;
  scanf("%i",&n1);
  if(n1==7) break;
  if(n1==1){
    scanf("%c %d",&c1,&n2);
    m[c1] = n2;
  }
  else if(n1==2){
  scanf(" %c",&c1);
  printf("%i\n",m[c1]);
  }
  else if(n1==3){
  scanf(" %c %c",&c1,&c2); 
  int s = m[c1]+m[c2];
  m[c1] = s;
  }
  else if(n1==4){
  scanf(" %c %c",&c1,&c2); 
  int s = m[c1]*m[c2];
  m[c1] = s;
  }
  else if(n1==5){
  scanf(" %c %c",&c1,&c2); 
  int s = m[c1]-m[c2];
  m[c1] = s;
  }
  else {
  scanf(" %c %c",&c1,&c2); 
  int s = m[c1]/m[c2];
  m[c1] = s;
  }
  }
}
