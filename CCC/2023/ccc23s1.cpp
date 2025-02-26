// CCC '23 S1 - Trianglane
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,c=0;
  scanf("%d",&n);
  vector<bool> l1,l2;
  for(int i=0;i<n;i++){
    int in;
    scanf("%d",&in);
    l1.push_back(in);
  }
  for(int i=0;i<n;i++){
    int in;
    scanf("%d",&in);
    l2.push_back(in);
  }
  for(int i=0;i<n;i++){
    if(l1[i]==1){
      c+=3;
      if(i>0) if(l1[i-1]==1) c--;
      if(i<n-1) if(l1[i+1]==1) c--;
    }
  }
  bool temp =1;
  for(int i=0;i<n;i++){
    if(temp ==0) temp=1;
    else temp = 0;
    if(l2[i]==1){
      c+=3;
      if(l1[i]==1&&temp==0) c-=2;
      if(i>0) if(l2[i-1]==1) c--;
      if(i<n-1) if(l2[i+1]==1) c--;
    }
  }
  printf("%d",c);
}
