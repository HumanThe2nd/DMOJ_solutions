// Magical Multiplication
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll c1=0,c2=0,c; 
  char a[1001],b[1001];
  scanf("%s %s",a,b);
  for(int i=0;i<strlen(a);i++)c1+=a[i]-48;
  for(int i=0;i<strlen(b);i++)c2+=b[i]-48;
  c = c1*c2;
  printf("%lld",c);
}
