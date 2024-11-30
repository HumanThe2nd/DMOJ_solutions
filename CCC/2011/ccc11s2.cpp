// CCC '11 S2 - Multiple Choice
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,c=0;
  scanf("%d",&n);
  vector<char> a,k;
  char in[2];
  for(int i=0;i<n;i++){
    scanf("%s",in);
    a.push_back(in[0]);
  }
  for(int i=0;i<n;i++){
    scanf("%s",in);
    k.push_back(in[0]);
  }
  for(int i=0;i<n;i++){
    c+=(a[i]==k[i]);
  }
  printf("%d\n",c);
}
