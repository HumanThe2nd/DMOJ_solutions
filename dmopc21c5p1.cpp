// DMOPC '21 Contest 5 P1 - Permutations & Primes
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  deque<int> odd={1,3,5},even={4,2};
  if(n==1)cout<<1<<"\n";
  else if(n<5)cout<<-1<<"\n";
  else{
  for(int i=6;i<n+1;i++){
    if(i%2==0) even.push_back(i);
    else odd.push_front(i);
  }
  for(auto x:odd) printf("%d %s",x,"");
  int ES = even.size();
  for(int i=0;i<ES;i++){
    if(i==ES-1) cout<<even[i]<<"\n";
    else cout<<even[i]<<" ";
}
}
}
