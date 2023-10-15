// CCC '19 S2 - Pretty Average Primes
// By: Dan Shan
#include <stdio.h> 
#include <math.h>
int check(double n){
  int prime = 1;
for(int i=2;i<pow(n,0.5)+1;i++){
    if((int)(n/i)==(double)(n/i)){
      prime = 0;
      break;
  }
  }
return prime;
}
int main(){
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    double in;
    int out,p=0;
    scanf("%lf",&in);
      while(check(in+p)==0||check(in-p)==0) p++;
      out = in;
      printf("%d %d %s",out-p,out+p,"\n");
  }
}
