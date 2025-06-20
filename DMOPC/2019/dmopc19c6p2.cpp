// DMOPC '19 Contest 6 P2 - Grade 10 Math
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int m(int n, int p) {
int c = 0;
while (n){
    n /= p;
    c += n;
}
return c;
}
int mc(int fact, int n){
int res = INT_MAX;
for (int i = 2; i <= sqrt(n); i++) {
  int c = 0;
  while (n % i == 0) {
    c++;
    n = n / i;
  }
  if (c) {
    int curr_pow = m(fact, i) / c;
    res = min(res, curr_pow);
  }
}
if (n >= 2) {
  int curr_pow = m(fact, n);
  res = min(res, curr_pow);
}

return res;
}
int main(){
  int a,b;
  scanf("%d %d",&a,&b);
  printf("%d %s",mc(b,a),"\n");
}
