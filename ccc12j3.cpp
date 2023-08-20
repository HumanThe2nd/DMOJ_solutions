// CCC '12 J3 - Icon Scaling
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    cout<<"*";
  }
  for(int j=0;j<n;j++){
    cout<<"x";
  }
  for(int j=0;j<n;j++){
    cout<<"*";
  }
  cout<<"\n";
}
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    cout<<" ";
  }
  for(int j=0;j<2*n;j++){
    cout<<"x";
  }
  cout<<"\n";
}
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    cout<<"*";
  }
  for(int j=0;j<n;j++){
    cout<<" ";
  }
  for(int j=0;j<n;j++){
    cout<<"*";
  }
  cout<<"\n";
}
}
