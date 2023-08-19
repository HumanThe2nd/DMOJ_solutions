// CCC '16 J3 - Hidden Palindrome
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int m=1;
  char in[41];
  scanf("%s",in);
  for(int i=0;i<strlen(in);i++){
    int l=i,r=i,c=1;
    while(l!=0&&r!=strlen(in)){
      l--;
      r++;
      if(in[l]!=in[r]) break;
      else c+=2;
    }
    m = max(m,c);
  }
  for(int i=0;i<strlen(in)-1;i++){
    int l=i,r=i+1,c=2;
    if(in[l]==in[r]){
    while(l!=0&&r!=strlen(in)){
      l--;
      r++;
      if(in[l]!=in[r]) break;
      else c+=2;
    }
    }
    m = max(m,c);
  }
  printf("%d %s",m,"\n");
}
