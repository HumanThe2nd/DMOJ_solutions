// CCC '21 J3 - Secret Instructions
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  bool r=1,l=1; // r:run, l:left
  while(r){
    int in,n,d,s;
    scanf("%d",&in);
    if(in==99999) break;
    n = in%1000;
    in/=1000;
    d = in%10;
    in/=10;
    s = in+d;
    if(s==0) {if(l==1)printf("left %d\n",n);
              else printf("right %d\n",n);}
    else if((in+d)%2==0) {printf("right %d\n",n); l=0;}
    else {printf("left %d\n",n); l=1;}
  }
}
