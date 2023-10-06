//============================================================================
// Name        : Flip the Switches
// Author      : Dan Shan
//============================================================================
// Goal: find minimum prefix flips starting from 1 to make a boolean array all 0
// Approach: Iterate array from back tracking the last changed element and counting the number of changes
#include <iostream>
using namespace std;
int main() {
int n,c=0;
scanf("%d",&n);
char s[n+1],cur='0';
scanf("%s",s);
for(int i=n-1;i>=0;i--){ // iterates switches from back
	if(s[i]!=cur){cur=s[i];c++;}
}
printf("%d\n",c);
}
