// CCC '13 J4 - Time on task
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
int t,n,c=0;
scanf("%d %d",&t,&n);
vector<int> chores;
for(int i=0;i<n;i++){
  int in;
  scanf("%d",&in);
  chores.push_back(in);
}
sort(chores.begin(),chores.end());
for(auto x: chores){
  if(x>t)break;
  t-=x;
  c++;
}
printf("%d\n",c);
}
