// CCC '19 J3 - Cold Compress
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
  char in[10001]="";
  scanf("%s",in);
  char last=in[0];
  int c=1;
  for(int j=1;j<strlen(in);j++){
    if(in[j]==last)c++;
    else{
      printf("%d %c ",c,last);
      last = in[j];
      c=1;
    }
  }
  printf("%d %c\n",c,last);
  }
}
