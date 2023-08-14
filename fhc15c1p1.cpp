// Facebook Hacker Cup '15 Round 1 P1 - Homework
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
vector<ll> Sieve(ll n){
  vector<ll> sieve;
  vector<bool> prime;
  for(int i=0;i<n;i++) prime.push_back(1);
  for(ll p=2;p*p<=n;p++){
  if(prime[p] == true){
    for(ll i = p*p;i<=n; i+=p) prime[i] = false;
  }
  }
  for(ll p=2;p<=n;p++) if (prime[p]) sieve.push_back(p);
  return sieve;
}
int main(){
  ll t;
  vector<ll> primes = Sieve(10000000),values;
  for(ll i=0;i<10000001;i++) values.push_back(0);
  for(auto x: primes){
    for(ll i=x-1;i<10000001;i+=x) values[i]++;
  }
  scanf("%lld",&t);
  for(ll j=1;j<t+1;j++){
  ll a,b,k,c=0;
  scanf("%lld %lld %lld",&a,&b,&k);
  for(ll i=a;i<b+1;i++){
    if(values[i-1]==k) c++;
  }
  cout<<"Case #"<<j<<": "<<c<<"\n";
  }
}
