//============================================================================
// Name        : CCC '07 S1 - Federal Voting Age
// Author      : Dan Shan
//============================================================================
// Goal: check if each input user is over 18 years old as if Fer 27, 2007 given birthday
// Approach: If check if the age is a year older or months older or if they just turned 18
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int y,m,d;
		scanf("%d %d %d",&y,&m,&d);
		if(y<1989||(y==1989&&m<2)||(y==1989&&m==2&&d<=27))printf("Yes\n");
		else printf("No\n");
	}
}
