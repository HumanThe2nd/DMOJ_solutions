// DMPG '19 S1 - Candy Shop Tycoon
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  bool clear = 0;
  int a,b,c,C,m;
  scanf("%d %d %d %d",&a,&b,&c,&C);
  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++){
      for(int k=1;k<=100;k++){
        if(a*i+b*j+c*k==C) {clear=1;break;}
      }
    }
  }
}
