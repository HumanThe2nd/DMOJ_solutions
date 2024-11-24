// CCC '09 J3 - Good Times
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  printf("%d in Ottawa\n",n);
  printf("%d in Victoria\n",(n+2100)%2400);
  printf("%d in Edmonton\n",(n+2200)%2400);
  printf("%d in Winnipeg\n",(n+2300)%2400);
  printf("%d in Toronto\n",n);
  printf("%d in Halifax\n",(n+100)%2400);
  int h = (n/100);
  if((n%100)+30>59) n = 100*h + 200+((n+30)%100)%60;
  else n+=130;
  printf("%d in St. John's\n",(n)%2400);
}
