// Sum of Primes 2
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
bool check(double n){
  bool prime=1;
  for(int i=2;i<pow(n,0.5)+1;i++){
   if(n/i == int(n/i)) prime = 0; 
  }
  return prime;
}
int main(){
  int q;
  scanf("%d",&q);
  vector<int> primes={0,2,5};
  for(double j=4;j<100001;j++){
    if(check(j)==1) primes.push_back(primes[j-2]+j);
    else primes.push_back(primes[j-2]);
  }
  for(int i=0;i<q;i++){
    double a,b;
    scanf("%lf %lf",&a,&b);
    printf("%d %s",primes[b-1]-primes[a-2],"\n");
  }
}
