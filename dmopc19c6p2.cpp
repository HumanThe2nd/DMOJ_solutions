// DMOPC '19 Contest 6 P2 - Grade 10 Math
// By: Dan Shan 
#include <bits/stdc++.h>
using namespace std;
int Sieve(int n) {
  int sieve = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      sieve += 2;
      if (i * i == n) sieve--;
    }
  }
  return sieve;
}
int main(){
  vector<vector<int>> values;
  for(int i=0;i<100001;i++) values.push_back({});
  for(int i=1;i<100001;i++){
    values[Sieve(i)].push_back(i);
  }
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    int k,a,b,c=0;
    scanf("%d %d %d",&k,&a,&b);
    for(auto x:values[k]) if(x>=a&&x<=b)c++;
    printf("%d %s",c,"\n");
  }
}
