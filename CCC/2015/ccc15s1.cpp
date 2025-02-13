// CCC '15 S1 - Zero That Out
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,c=0,x=0;
  scanf("%d",&n);
  vector<int> v;
  for(int i=0;i<n;i++){
    int s;
    scanf("%d",&s);
    v.push_back(s);
  }
  for(int i=n-1;i>=0;i--){
    if(v[i]==0)x++;
    else if(x>0)x--;
    else c+=v[i];
  }
  printf("%d\n",c);
}
