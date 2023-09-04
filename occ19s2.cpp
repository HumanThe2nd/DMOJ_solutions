// OCC '19 S2 - Rimuru's Number Game
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
ll n,c=0;
scanf("%lld",&n);
vector<int> nl;
while(n){nl.push_back(n%10);n/=10;}
while(nl.back()==1)nl.pop_back();
int s = nl.size()-1;
bool extra = 0;
// convert to a binary of 2 and 3s
for(int i=s;i>=0;i--){
  if(nl[i]>3){nl[i]=3;extra=1;}
  else if(nl[i]<3&&extra)nl[i] = 3;
  else if(nl[i]<2){nl[i+1]--;nl[i]=3;}
}
while(nl.back()==1)nl.pop_back();
s = nl.size();
for(int i=0;i<s;i++){
  if(nl[i]==3)c+=pow(2,i+1);
  else c+=pow(2,i);
}
printf("%lld\n",c);
}
