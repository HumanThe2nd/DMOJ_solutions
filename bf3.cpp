// Next Prime
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  long double n;
  int out,prime=0;
  scanf("%Lf",&n);
  if(n==1) n=2;
  if(n==3||n==2) prime =1;
  if(prime ==0){
    prime = 1;
  for(int i=2;i<pow(n,0.5)+1;i++){
    if(int(n/i)==double(n/i)){
      prime = 0;
      break;
  }
  }
  }
    while(prime==0){
    n++;
    prime =1;
    for(int i=2;i<pow(n,0.5)+1;i++){
    if(int(n/i)==double(n/i)){
      prime = 0;
      break;
  }
}
}
out = n;
printf("%d",out);
}
