// DMPG '17 B1 - Whale and Soul
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  double n,m1,m2;
  scanf("%lf %lf %lf",&n,&m1,&m2);
  for(int i=0;i<n;i++){
    double c,d;
    scanf("%lf %lf",&c,&d);
    if(d>m2||(d==m2&&c<m1)){m2=d;m1=c;}
  }
  int o1=m1,o2=m2;
  printf("%d %d\n",o1,o2);
}
