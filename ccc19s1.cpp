//============================================================================
// Name        : CCC '19 S1 - Flipper
// Author      : Dan Shan
//============================================================================
#include <bits/stdc++.h>
using namespace std;
int main(){
	char in[1000001];
  scanf("%s",in);
  int h=0,v=0;
  for(int i=0;i<strlen(in);i++){if(in[i]=='H')h++;else v++;}
  if(h%2&&v%2)printf("4 3\n2 1\n");
  else if(h%2)printf("3 4\n1 2\n");
  else if(v%2)printf("2 1\n4 3\n");
  else printf("1 2\n3 4\n");
}
