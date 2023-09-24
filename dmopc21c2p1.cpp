//============================================================================
// Name        : CCC '22 S1 - Good Fours and Good Fives
// Author      : Dan Shan
//============================================================================
// Goal: outputs combinations of 4 and 5 for given number
// Approach: mod 20 and add one if remainder satisfies conditions
#include <iostream>
using namespace std;
using ll = long long;
int main(){
	int n,c=0;
	scanf("%d",&n);
	c+=n/20;
	n%=20;
	if(n!=1&&n!=2&&n!=3&&n!=6&&n!=7&&n!=11)c++;
	printf("%d\n",c);
}
