// DWITE '10 R1 #1 - Age Gate
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std; 
int main() {
  int d,m,y;
  for(int i=0;i<5;i++){
  scanf("%d %d %d",&d,&m,&y);
    if(y>1997||(y==1997&&m>10)||(y==1997&&m==10&&d>27))printf("%s","too young\n");
    else printf("%s","old enough\n");
  }
}
